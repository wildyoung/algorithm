#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int a, b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector <vector<int>> v(n + 1);
	vector <int> deg(n + 1);
	while (m--)
	{
		cin >> a >> b;
		deg[b]++;
		v[a].push_back(b);
	}

	priority_queue <int, vector<int>, greater<>> q;

	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.top();
		q.pop();
		cout << cur << " ";

		for (int nxt : v[cur])
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
