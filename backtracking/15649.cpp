#include <iostream>
#include <vector>
using namespace std;
int n, m; 
vector<int> res;
vector<bool> visited;
void func(int k)
{
	if (k == m)
	{
		 for (int i = 0; i < m; i++)
		 {
		 	cout << res[i] << " ";
		 }
		 cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		res[k] = i;
		visited[i] = true;
		func(k + 1);
		visited[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	res.assign(m, 0);
	visited.assign(n + 1, false);
	func(0);
	return 0;
}
