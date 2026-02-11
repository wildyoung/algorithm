#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m; // 컴퓨터 개수, 간선 개수
int a, b;
int x;
int ans=-1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	vector <vector <int>> u(n + 1);
	vector <bool> vis(n + 1, false);

	while (m--)
	{
		cin >> a >> b;
		u[a].push_back(b);
		u[b].push_back(a);
	}

	queue <int> q;
	q.push(1);

	while (!q.empty())
	{
		x = q.front();
		q.pop();
		if (!vis[x])
		{
			ans++;
			vis[x] = true;

			for (int next : u[x])
			{
				if (!vis[next])
				{
					q.push(next);
				}
			}
		}
	}
	cout << ans;

	return 0;
}
