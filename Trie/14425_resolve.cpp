#include <iostream>
using namespace std;

// ===================== Trie(트라이) 자료구조로 "문자열 집합 포함 여부" 체크 =====================
// - 각 노드는 'a'~'z'로 가는 간선(다음 노드 인덱스) 26개를 가진다.
// - 루트(ROOT)에서 시작해서 문자열을 한 글자씩 따라가며 노드를 만든다/이동한다.
// - 어떤 노드가 "문자열의 끝"인지 표시(chk)해두면, 탐색 시 정확히 같은 문자열만 true가 된다
//   (접두사만 같은 경우는 false)

const int ROOT = 1;          // 루트 노드 인덱스(0을 안 쓰고 1부터 사용)
int unused = 2;              // 새 노드를 할당할 때 사용할 다음 인덱스 (1은 ROOT가 사용 중)

// 최대 등장 가능한 글자 수 = (N 최대 10000) * (문자열 길이 최대 500) + 여유
// 트라이는 최악의 경우 글자 하나마다 노드 하나가 생기므로 노드 수도 이 정도까지 늘 수 있음
const int MX = 10000 * 500 + 5;

// chk[node] = true 면 "이 노드에서 어떤 문자열이 끝난다"라는 의미
bool chk[MX];

// nxt[node][c] = node에서 문자 c('a'~'z')로 이동했을 때의 다음 노드 인덱스
// 없으면 -1
int nxt[MX][26];

// 문자 -> 0~25 인덱스로 변환
int c2i(char c) {
    return c - 'a';
}

// 문자열 s를 트라이에 삽입
void insert(string& s) {
    int cur = ROOT; // 항상 루트에서 시작

    // 문자열을 한 글자씩 처리
    for (auto c : s) {
        int idx = c2i(c);

        // 해당 문자로 가는 간선이 아직 없다면 새 노드를 만들고 연결
        if (nxt[cur][idx] == -1)
            nxt[cur][idx] = unused++;

        // 다음 노드로 이동
        cur = nxt[cur][idx];
    }

    // 문자열의 마지막 글자까지 따라온 노드에 "여기서 문자열 끝" 표시
    chk[cur] = true;
}

// 문자열 s가 트라이에 "완전히 동일하게" 존재하는지 탐색
bool find(string& s) {
    int cur = ROOT; // 루트에서 시작

    for (auto c : s) {
        int idx = c2i(c);

        // 가는 길이 없으면 집합에 없는 문자열
        if (nxt[cur][idx] == -1)
            return false;

        // 있으면 다음 노드로 이동
        cur = nxt[cur][idx];
    }

    // 여기까지 왔다는 건 "접두사 경로는 존재"한다는 뜻
    // 하지만 정확히 문자열이 끝나는 지점인지(chk)가 true여야 "동일 문자열"이 존재
    return chk[cur];
}

int n, m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // nxt 배열 초기화: 모든 간선을 -1로 (아직 연결 없음)
    // nxt는 전역 배열이라 기본값 0이 들어가는데, 0을 쓰면 "간선 있음"처럼 오해할 수 있으니
    // 반드시 -1로 초기화해서 "없음"을 명확하게 표시한다.
    for (int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);

    cin >> n >> m;

    // 집합 S에 들어갈 N개 문자열 삽입
    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }

    int ans = 0;

    // 검사할 M개 문자열에 대해, find가 true면 카운트 증가
    // ans += find(s); 는 bool이 true면 1, false면 0으로 더해지는 성질 이용
    while (m--) {
        string s;
        cin >> s;
        ans += find(s);
    }

    // 포함된 문자열 개수 출력
    cout << ans;
}
