// 다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘
#include <iostream>
#include <queue>
using namespace std;

#define x first
#define y second

int board[502][502]; // 다차원 배열
bool vis[502][502]; // 방문여부 체크 용도

// 맵의 크기 (행, 열)
int n = 4;
int m = 5;

// 상하좌우 이동을 위한 방향 벡터 (→, ↓, ←, ↑ 순서)
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue <pair<int, int>> q; //BFS 탐색을 위한 큐 선언(좌표를 저장)

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 2차원 배열 입력 받기
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	// 시작점이 1인 경우에만 시작
	if (board[0][0] == 1) {
		vis[0][0] = true;
		q.push({ 0, 0 });
	}

	// 큐가 빌 때까지 너비 우선 탐색 수행
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); // 큐의 front에서 현재 좌표 꺼냄
		q.pop(); // 큐에서 제거

		cout << "(" << cur.x << ", " << cur.y << ") 방문\n";

		// 상하좌우 방향으로 인접 칸 확인
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			// 범위를 벗어나면 무시
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			
			// 이미 방문했거나 벽(0)이라면 무시
			if (vis[nx][ny] || board[nx][ny] != 1)continue;

			// 조건을 만족하면 방문 처리하고 큐에 추가
			vis[nx][ny] = 1;
			q.push({ nx,ny });

		}
	}



	return 0;
}
