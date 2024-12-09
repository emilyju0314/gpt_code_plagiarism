#include <bits/stdc++.h>
using namespace std;

int main()
{
	int s;
	cin >> s;
	set<int> st;
	while (!st.count(s)) {
		st.insert(s);
		s = s & 1 ? s * 3 + 1 : s / 2;
	}
	cout << st.size() + 1 << endl;
	return 0;
}
