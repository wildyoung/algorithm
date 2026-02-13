#include <iostream>
#include <vector>
using namespace std;
int k;
int x;
vector <int> arr;
vector <bool> visited;
void func(int start, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < k; i++)
			if (visited[i]) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i < k; i++) {
		visited[i] = true;
		func(i + 1, cnt + 1);
		visited[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		cin >> k;
		if (k == 0) return 0;
		arr.resize(k);
		visited.resize(k);
		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}
		func(0, 0);
		cout << "\n";
	}

	return 0;
}
