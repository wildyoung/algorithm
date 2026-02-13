#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> ans;
vector<bool> visited;
vector<char> arr;
int cnt[2];

void func(int st, int k)
{
    if (k == l)
    {
        ans.clear();
        cnt[0] = cnt[1] = 0;

        for (int u = 0; u < c; u++)
            if (visited[u]) ans.push_back(arr[u]);

        for (int j = 0; j < l; j++) {
            char ch = ans[j];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') cnt[0]++;
            else cnt[1]++;
        }

        if (cnt[0] >= 1 && cnt[1] >= 2) {
            for (int j = 0; j < l; j++) cout << ans[j];
            cout << "\n";
        }
        return;
    }

    for (int i = st; i < c; i++)
    {
        visited[i] = true;
        func(i + 1, k + 1);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> c;

    arr.resize(c);
    visited.assign(c, false);

    for (int j = 0; j < c; j++) cin >> arr[j];

    sort(arr.begin(), arr.end());
    func(0, 0);
}
