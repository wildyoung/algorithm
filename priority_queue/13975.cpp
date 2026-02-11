#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int t; //테스트케이스 개수
int k;
int x;
long a, b;
long ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> k;
		priority_queue <long, vector<long>, greater<>> pq;
		while (k--)
		{
			cin >> x;
			pq.push(x);
		}
		ans = 0;
		while (pq.size() != 1)
		{
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			ans += (a + b);
			pq.push(a + b);
		}
		cout << ans << "\n";
	}

	return 0;
}
