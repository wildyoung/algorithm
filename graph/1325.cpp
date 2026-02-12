#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int a, b;
int cnt;
int mx;
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	vector<int> ans;
	while(m--)
	{
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for(int i=1; i<=n; i++)
	{
		vector<int> dist(n + 1, -1);
		queue<int> q;
		dist[i] = 0;
		q.push(i);
		cnt = 0;
		while(!q.empty())
		{
			int cur = q.front(); q.pop();
			for(int nxt : graph[cur])
			{
				if(dist[nxt] == -1)
				{
					dist[nxt] = dist[cur] + 1;
					q.push(nxt);
					cnt++;
				}
			}
		}
		if (cnt > mx)
		{
			mx = cnt;
			ans.clear();
			ans.push_back(i);
		}
		else if (cnt == mx)
		{
			ans.push_back(i);
		}
	}

	for(int x : ans)
		cout << x << " ";

	return 0;
}
