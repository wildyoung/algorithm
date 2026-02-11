#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int x;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<vector<int>> u(n + 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> x;
			if (x == 1)
			{
				u[i].push_back(j);
			}
		}
	}
	queue <int> q;
	vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));

	for (int i = 1; i <= n; i++)
	{
		vector<bool> seen(n + 1, false);

		for (int nxt : u[i]) {
			if (!seen[nxt]) {
				seen[nxt] = true;
				q.push(nxt);
			}
		}

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			vis[i][cur] = true; // i -> cur 경로 존재

			for (int nxt : u[cur])
			{
				if (!seen[nxt])
				{
					seen[nxt] = true;
					q.push(nxt);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (vis[i][j])
			{
				cout << 1 << " ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << "\n";
	}

	return 0;

}
