#include <iostream>
#include <vector>
using namespace std;

int n, s;
vector<int> arr;   // 입력 배열
int ans = 0;

void func(int k, int sum)
{
    if (k == n)  // 모든 원소를 다 본 경우
    {
        return;
    }

    // 현재 원소 선택
    int newSum = sum + arr[k];
    if (newSum == s)
    {
        ans++;
    }

    func(k + 1, newSum);  // 선택한 경우
    func(k + 1, sum);     // 선택 안 한 경우
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    arr.assign(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    func(0, 0);

    cout << ans << "\n";

    return 0;
}
