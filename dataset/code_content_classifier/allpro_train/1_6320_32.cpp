#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int	N;
	cin >> N;
	multiset<int> ms;
	rep(i, N)
	{
		int	a, b;
		cin >> a >> b;
		if (a == 0)
		{
			ms.insert(b);
			cout << ms.size() << endl;
		}
		else if (a == 1)
			cout << ms.count(b) << endl;
		else if (a == 2)
			ms.erase(b);
		else
		{
			int c;
			cin >> c;
			for (multiset<int>::iterator it = ms.lower_bound(b); it != ms.upper_bound(c); it++)
				cout << *it << endl;
		}
	}
}

