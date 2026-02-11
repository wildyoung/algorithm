#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int x, y;
int ans=-1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	vector<vector<int>> u(n+1);
	vector <bool> vis(n + 1, false);
	queue <int> q;
	while (m--)
	{
		cin >> x >> y;
		u[x].push_back(y);
		u[y].push_back(x);
	}
	vector<int> dist(n + 1, -1);
	dist[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : u[cur]) {
			if (dist[nxt] == -1) {
				dist[nxt] = dist[cur] + 1;
				if (dist[nxt] <= 1) q.push(nxt); 
			}
		}
	}

	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (dist[i] != -1 && dist[i] <= 2) ans++;
	}
	cout << ans;
}
