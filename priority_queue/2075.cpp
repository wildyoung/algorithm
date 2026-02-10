#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	// 최소 힙 선언 (작은 숫자가 top에 옴)
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n * n; i++) {
		int x;
		cin >> x;

		// 1. 일단 큐에 넣음
		pq.push(x);

		// 2. 큐의 크기가 n을 초과하면 가장 작은 놈(top)을 버림
		if (pq.size() > n) {
			pq.pop();
		}
	}

	// 최종적으로 큐에 남은 n개 중 가장 작은 것이 "n번째로 큰 수"
	cout << pq.top();

	return 0;
}
