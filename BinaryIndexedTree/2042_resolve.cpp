#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
long long arr[1000001];  // 원본 배열 저장용
long long tree[1000001]; // 펜윅 트리 배열
long long a, b, c;

// 1. 트리 업데이트 함수
void update(int i, long long diff) {
    while (i <= N) {
        tree[i] += diff;
        i += (i & -i); // LSB(Least Significant Bit)를 더하며 상위 관리자로 이동
    }
}

// 2. 1부터 i까지의 누적 합 함수
long long sum(int i) {
    long long ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= (i & -i); // LSB를 빼며 이전 구간 합으로 이동
    }
    return ret;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) 
    {
        cin >> arr[i];
        update(i, arr[i]); // 초기 값들을 트리에 반영
    }

    int total_queries = M + K;
    while (total_queries--) 
    {
        cin >> a >> b >> c;
        if (a == 1) 
        {
            // b번째 수를 c로 변경
            long long diff = c - arr[b];
            arr[b] = c; // 원본 배열 갱신
            update(b, diff);
        }
        else if (a == 2)
        {
            cout << sum(c) - sum(b - 1) << "\n";
        }
    }
    return 0;
}
