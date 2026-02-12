#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);

    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> score(n + 1);
    int min_score = 1e9;

    // 각 사람마다 BFS
    for (int i = 1; i <= n; i++)
    {
        vector<int> dist(n + 1, -1);
        queue<int> q;

        dist[i] = 0;
        q.push(i);

        while (!q.empty())
        {
            int cur = q.front(); q.pop();

            for (int nxt : graph[cur])
            {
                if (dist[nxt] == -1)
                {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }

        int max_dist = 0;
        for (int j = 1; j <= n; j++)
        {
            max_dist = max(max_dist, dist[j]);
        }

        score[i] = max_dist;
        min_score = min(min_score, max_dist);
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (score[i] == min_score)
            ans.push_back(i);
    }

    cout << min_score << " " << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";
}
