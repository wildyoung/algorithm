#include <iostream>
#include <vector>
using namespace std;
int n; // 배열의 크기

// idx: 세그먼트 트리의 현재 노드 인덱스
// st: 현재 노드가 담당하는 구간의 시작 인덱스
// en: 현재 노드가 담당하는 구간의 끝 인덱스
int init(vector<int>& num, vector<int>& seg, int idx, int st, int en)
{
	if (st == en) return seg[idx] = num[st];

	int mid = (st + en) / 2;
	return seg[idx] = init(num, seg, idx * 2, st, mid) + init(num, seg, idx * 2 + 1, mid + 1, en);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> num(n); // 배열의 크기 n
	vector<int> seg(4 * n); // 세그먼트 트리 배열의 크기는 일반적으로 4배로 설정

	for (int i = 0; i < n; i++)
	{
		num[i] = i + 1; // 배열에 1부터 n까지의 수를 저장
	}

	init(num, seg, 1, 0, n - 1);

	for (int i = 1; i < 2 * n; i++)
	{
		cout << "seg[" << i << "] = " << seg[i] << "\n";
	}

	return 0;
}
