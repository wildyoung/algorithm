#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int ans;
int a, b;
int cur;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<vector<int>> u(n + 1);
	vector<bool> vis(n + 1, false);
	queue <int> q;

	while (m--)
	{
		cin >> a >> b;
		u[a].push_back(b);
		u[b].push_back(a);
	}


	for (int j = 1; j <= n; j++)
	{
		if (!vis[j])
		{
			ans++;
			q.push(j);
			vis[j] = true;
		}
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			for (int next : u[cur])
			{
				if (!vis[next])
				{
					vis[next] = true;
					q.push(next);
				}
			}
		}
	}

	cout << ans;

	return 0;
}
