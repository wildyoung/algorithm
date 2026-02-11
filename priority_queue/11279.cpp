#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int x;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int> pq;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x == 0)
		{
			if (pq.size() == 0)
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << pq.top()<<"\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}

	}


	return 0;
}
