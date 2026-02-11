#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n, m,v;
int x, y;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> v;

	vector <vector<int>> u(n + 1);
	vector <bool> vis(n + 1, false);

	while (m--)
	{
		cin >> x >> y;
		u[x].push_back(y);
		u[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		sort(u[i].begin(), u[i].end()); // 오름차순 정렬
	}

	//DFS
	stack <int> s;
	s.push(v);
	// DFS 스택 부분
	while (!s.empty()) {
		x = s.top();
		s.pop();
		if (!vis[x])
		{
			vis[x] = true;
			cout << x << " ";
			// 인접 리스트를 뒤에서부터 순회 (큰 숫자부터 push)
			for (int i = u[x].size() - 1; i >= 0; i--) {
				int next = u[x][i];
				s.push(next);
			}
		}
	}
	cout << "\n";
	//BFS
	queue <int> q;
	q.push(v);
	vis.assign(n + 1, false);
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		if (!vis[x])
		{
			vis[x] = true;
			cout << x << " ";
			for (int next : u[x]) {
				q.push(next);
			}
		}

	}



	return 0;
}
