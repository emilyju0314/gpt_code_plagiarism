  
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
vector<vector<int> > g;
vector<int> A;
vector<vector<int> > dp;
vector<vector<int> > fail;
vector<int> fi;
vector<int> se;
vector<int> fi_sum;
vector<int> se_sum;
vector<int> sum;
pair<int, int> dfs1(int a, int p) {

	dp[a].resize(g[a].size(), 0);
	fail[a].resize(g[a].size(), 0);
	int f = 0;
	int step = 0;
	int t = 1;
	if (t > A[a]) {
		f = 1;
	}
	if (f == 0) {
		step++;
	}
	for (int i = 0; i < g[a].size(); i++) {
		if (g[a][i] != p) {
			pair<int, int> p = dfs1(g[a][i], a);
			dp[a][i] = p.first;
			if (f == 0) {
				step += dp[a][i];
			}
			fail[a][i] = p.second;
			f |= p.second;
			t++;
			if (t > A[a]) {
				f = 1;
			}
			if (f == 0) {
				step++;
			}
		}
	}
	return make_pair(step, f);
}

void dfs2(int a, int p, int j) {
	int idx = -1;
	for (int i = 0; i < g[a].size(); i++) {
		if (g[a][i] == p) {
			idx = i;
		}
	}
	if (idx >= 0) {
		fail[a][idx] = 0;
		if (fi[p] == -1) {

			if (j < A[p]) {
				dp[a][idx] = sum[p] - dp[p][j];
				if (A[p] < (int)g[p].size()) {
					dp[a][idx] += dp[p][A[p]];
					/*if (fail[p][A[p]]) {
						fail[a][idx] = 1;
						dp[a][idx] += A[p] - 1;
					}
					else {
						dp[a][idx] += A[p];
					}*/
					dp[a][idx] += A[p];
					fail[a][idx] = 1;
				}
				else {
					dp[a][idx] += (int)g[p].size();
				}

			}
			else {
				dp[a][idx] = sum[p] + A[p];
				fail[a][idx] = 1;
			}
		}
		else {
			if (j < fi[p]) {
				dp[a][idx] = fi_sum[p] - dp[p][j];
				dp[a][idx] += fi[p];
				fail[a][idx] = 1;
			}
			else if (j == fi[p]) {
				if (se[p] == -1) {
					dp[a][idx] = sum[p] - dp[p][j];
					if (A[p] < (int)g[p].size()) {
						dp[a][idx] += dp[p][A[p]];
						/*if (fail[p][A[p]]) {
							fail[a][idx] = 1;
							dp[a][idx] += A[p] - 1;
						}
						else {
							dp[a][idx] += A[p];
						}*/
						dp[a][idx] += A[p];
						fail[a][idx] = 1;
					}
					else {
						dp[a][idx] += (int)g[p].size();
					}
				}
				else {
					dp[a][idx] = se_sum[p] - dp[p][j];
					dp[a][idx] += se[p];
					fail[a][idx] = 1;
				}
			}
			else {
				dp[a][idx] = fi_sum[p];
				dp[a][idx] += fi[p] + 1;
				fail[a][idx] = 1;
			}
		}
	}
	fi[a] = -1;
	se[a] = -1;
	sum[a] = 0;
	for (int i = 0; i < min(A[a], (int)g[a].size()); i++) {
		if (fail[a][i] == 1) {
			if (fi[a] == -1) {
				fi[a] = i;
				fi_sum[a] = sum[a] + dp[a][i];
			}
			else if (se[a] == -1) {
				se[a] = i;
				se_sum[a] = sum[a] + dp[a][i];
			}
		}
		sum[a] += dp[a][i];
	}



	for (int i = 0; i < g[a].size(); i++) {
		if (g[a][i] != p) {
			dfs2(g[a][i], a, i);
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	A.resize(N);
	dp.resize(N);
	fail.resize(N);
	g.resize(N);
	fi.resize(N);
	se.resize(N);
	fi_sum.resize(N);
	se_sum.resize(N);
	sum.resize(N);

	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		sort(g[i].begin(), g[i].end());
	}

	dfs1(0, -1);
	dfs2(0, -1, -1);

	for (int a = 0; a < N; a++) {
		int f = 0;
		int step = 0;
		int t = 1;
		if (t > A[a]) {
			f = 1;
		}
		if (f == 0) {
			step++;
		}
		for (int i = 0; i < g[a].size(); i++) {
			if (f == 0) {
				step += dp[a][i];
			}
			f |= fail[a][i];
			t++;
			if (t > A[a]) {
				f = 1;
			}
			if (f == 0) {
				step++;
			}
		}
		cout << step << endl;

	}
}
