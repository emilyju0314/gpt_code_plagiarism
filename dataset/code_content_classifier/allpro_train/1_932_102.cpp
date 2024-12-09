#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
#include <cassert>
using namespace std;

typedef long long ll;

int main() {
	int N, Q; cin >> N >> Q;
	string s; cin >> s;
	s = "@" + s + "@";
	vector<char> t(Q), d(Q);
	for (int i = 0; i < Q; i++) cin >> t[i] >> d[i];
	int pos = 0;
	for (int i = Q - 1; i >= 0; i--) {
		if (pos <= N && t[i] == s[pos + 1] && d[i] == 'L') pos = min(N + 1, pos + 1);
		else if (t[i] == s[pos] && d[i] == 'R') pos = max(0, pos - 1);
	}
	int ans = pos;
	pos = N + 1;
	for (int i = Q - 1; i >= 0; i--) {
		if (pos > 0 && t[i] == s[pos - 1] && d[i] == 'R') pos = max(0, pos - 1);
		else if (t[i] == s[pos] && d[i] == 'L') pos = min(N + 1, pos + 1);
	}
	ans = min(N, ans + N + 1 - pos);
	cout << N - ans << endl;
	return 0;
}
