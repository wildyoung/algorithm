#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
long long arr[1000001];
long long seg[4000004];

// 초기 트리 구축
long long init(int idx, int st, int en) {
    if (st == en) return seg[idx] = arr[st];
    int mid = (st + en) / 2;
    return seg[idx] = init(2 * idx, st, mid) + init(2 * idx + 1, mid + 1, en);
}

/**
 * 2. 트리 업데이트
 * 리프 노드에 도달했을 때만 += diff를 하고,
 * 이후 부모 노드들은 하위 자식들의 합으로 다시 계산합니다.
 */
void update(int idx, int st, int en, int i, long long diff) {
    // 1. 리프 노드에 도달한 경우 (사진의 if(st==en) 부분)
    if (st == en) {
        seg[idx] += diff;
        return;
    }

    // 2. 자식 노드로 내려가기 (사진의 if(i <= (st+en)/2) 부분)
    int mid = (st + en) / 2;
    if (i <= mid) {
        update(2 * idx, st, mid, i, diff);
    }
    else {
        update(2 * idx + 1, mid + 1, en, i, diff);
    }

    // 3. 자식들의 업데이트가 끝난 후 부모 노드 값 갱신 (중요!)
    // 사진에는 생략되어 있지만, 부모 노드가 합을 유지하려면 이 과정이 필수입니다.
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

/**
 * 3. 구간 합 구하기
 */
long long sum(int idx, int st, int en, int l, int r) {
    if (l > en || r < st) return 0;
    if (l <= st && en <= r) return seg[idx];

    int mid = (st + en) / 2;
    return sum(2 * idx, st, mid, l, r) + sum(2 * idx + 1, mid + 1, en, l, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init(1, 1, N);

    int total_queries = M + K;
    while (total_queries--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            long long diff = c - arr[b];
            arr[b] = c;
            update(1, 1, N, (int)b, diff);
        }
        else if (a == 2) {
            cout << sum(1, 1, N, (int)b, (int)c) << "\n";
        }
    }

    return 0;
}
