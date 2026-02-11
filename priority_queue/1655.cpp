#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int t;
int x;
int a, b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<>> min_pq;

	cin >> t;
	
	while (t--)
	{
		cin >> x;

		if (max_pq.size() <= min_pq.size())
		{
			max_pq.push(x);
		}
		else
		{
			min_pq.push(x);
		}

		if (max_pq.size() != 0 && min_pq.size() != 0)
		{
			if (max_pq.top() > min_pq.top())
			{
				a = max_pq.top();
				b = min_pq.top();
				max_pq.pop();
				min_pq.pop();

				max_pq.push(b);
				min_pq.push(a);
			}
		}

		if (min_pq.size() == 0)cout << max_pq.top()<<"\n";
		else
		{
			cout << min(max_pq.top(), min_pq.top())<<"\n";
		}
	}
	return 0;
}
