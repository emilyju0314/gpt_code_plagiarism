#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 303;
const int mod = 998244353;

int dp[N][N][N];

void add(int& x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

int main() {
	string s;
	cin >> s;
	int k = nxt();
	int n = s.length();

	s += '0';
	vector<int> cnts;
	for (int i = 0, c = 0; i < n + 1; ++i) {
		if (s[i] == '1') {
			++c;
		} else {
			cnts.push_back(c);
			c = 0;
		}
	}

	const int total = accumulate(all(cnts), 0);
	reverse(all(cnts));

	dp[0][0][0] = 1;
	for (int i = 0; i < (int)cnts.size(); ++i) {
		for (int bal = 0; bal <= total; ++bal) {
			for (int used = 0; used <= total; ++used) {
				if (!dp[i][bal][used]) {
					continue;
				}
				for (int here = 0; here <= total; ++here) {
					if (bal + cnts[i] - here < 0) {
						break;
					}
					add(dp[i + 1][bal + cnts[i] - here][used + max(0, here - cnts[i])], dp[i][bal][used]);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= min(k, total); ++i) {
		add(ans, dp[(int)cnts.size()][0][i]);
	}
	cout << ans << "\n";

	return 0;
}
