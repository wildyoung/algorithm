#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int a, b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<vector<int>> p(n+1);
	vector <int> deg(n + 1);

	while (m--)
	{
		cin >> a >> b;
		p[a].push_back(b);
		deg[b]++;
	}

	queue <int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			q.push(i);
		}
	}
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int nxt : p[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}

	return 0;
}
