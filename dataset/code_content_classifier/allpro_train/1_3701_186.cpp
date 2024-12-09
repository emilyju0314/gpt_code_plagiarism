#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int ans = 0;
	for (char c : s) {
		ans += (c - '0');
	}
	if (ans % 9) cout << "No";
	else cout << "Yes";
	cout << endl;
}
