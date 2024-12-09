#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
const pair<int, int> arienai = make_pair(inf, -inf);
bool vis[209][209]; pair<int, int> dp[209][209];
pair<int, int> solve(int l, int r, string& s) {
	if (r - l == 0) return arienai;
	if (r - l == 1) return('0' <= s[l] && s[l] <= '9' ? make_pair(int(s[l] - '0'), int(s[l] - '0')) : arienai);
	if (vis[l][r]) return dp[l][r];
	pair<int, int> ans = arienai;
	for (int i = l + 1; i < r - 1; ++i) {
		if (s[i] == '+') {
			pair<int, int> lc = solve(l, i, s);
			pair<int, int> rc = solve(i + 1, r, s);
			if (lc != arienai && rc != arienai) {
				ans.first = min(ans.first, lc.first + rc.first);
				ans.second = max(ans.second, lc.second + rc.second);
			}
		}
		if (s[i] == '-') {
			pair<int, int> lc = solve(l, i, s);
			pair<int, int> rc = solve(i + 1, r, s);
			if (lc != arienai && rc != arienai) {
				ans.first = min(ans.first, lc.first - rc.second);
				ans.second = max(ans.second, lc.second - rc.first);
			}
		}
	}
	for (int i = 1; i < 4; ++i) {
		if ((i & 1) && s[l] != '(') continue;
		if ((i & 2) && s[r - 1] != ')') continue;
		pair<int, int> res = solve(l + (i & 1 ? 1 : 0), r - (i & 2 ? 1 : 0), s);
		if (res != arienai && (r - (i & 2 ? 1 : 0)) - (l + (i & 1 ? 1 : 0)) >= 2) {
			ans.first = min(ans.first, res.first);
			ans.second = max(ans.second, res.second);
		}
	}
	vis[l][r] = true;
	dp[l][r] = ans;
	return ans;
}
int main() {
	string s;
	cin >> s;
	pair<int, int> ans = solve(0, s.size(), s);
	cout << ans.second << endl;
	return 0;
}
