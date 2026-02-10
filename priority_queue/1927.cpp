#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n; // 연산 개수
int x; // 변수 입력용
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int> ,greater<>> pq;
	cin >> n; // 연산의 개수 입력
	while (n--)
	{
		cin >> x;
		if (x == 0)
		{
			if (pq.size() == 0)cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n";
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
