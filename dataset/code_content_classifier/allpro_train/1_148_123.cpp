#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> f(n, 0);
	for (auto&& fi : f)
		for (int i = 0; i < 10; i++)
		{
			int j;
			cin >> j;
			fi |= (j << (9 - i));
		}
	vector<vector<int>> p(n, vector<int>(11));
	for (auto&& pi : p)
		for (auto&& pii : pi)
			cin >> pii;

	int maxp = INT_MIN;
	for (int i = 1; i < 1024; i++)
	{
		int curp = 0;
		for (int j = 0; j < n; j++)
		{
			int count = 0;
			int check = f[j] & i;
			for (int k = 0; k < 10; k++)
				count += ((check >> k) & 1);
			curp += p[j][count];
		}
		maxp = max(maxp, curp);
	}
	cout << maxp << endl;
	return 0;
}
