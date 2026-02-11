#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int n;
int a, b;
int x, y;
int mx;
long long ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<pair<int, int>> pq;

	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		pq.push({ a,b });
		if (a > mx)mx = a;
	}

	priority_queue<int> cand; 

	for (int day = mx; day >= 1; day--) {
		while (!pq.empty() && pq.top().X >= day) {
			cand.push(pq.top().Y);
			pq.pop();
		}

		if (!cand.empty()) {
			ans += cand.top();
			cand.pop();
		}
	}

	cout << ans;

	return 0;
}
