#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int x, y;
int ans;
int sum;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	 // priority_queue<int> pq; 최대힙 -> 큰 수 부터 출력
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--)
	{
		cin >> x;
		pq.push(x);
	}

	while (pq.size()!= 1)
	{
		x = pq.top();
		pq.pop();
		y = pq.top();
		pq.pop();
		sum += x + y;
		pq.push(x + y);
	}

	cout << sum;

	return 0;
}
