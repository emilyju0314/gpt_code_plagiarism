#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }
template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }

typedef vector<vector<int>> graph;

constexpr int INF = (1 << 29);
constexpr int MAX_N = 50;

enum {A, B, NUM};
int dp[MAX_N][MAX_N][NUM];

inline string solve() {
	int n;
	cin >> n;

	graph G(n);
	for(int v = 0; v < n; ++v) {
		G[v].emplace_back(v);
		for(int u = 0; u < n; ++u) {
			int exist;
			cin >> exist;
			if(exist) G[v].emplace_back(u);
		}
	}

	fill_n((int *)dp, sizeof(dp) / sizeof(int), INF);
	for(int v = 0; v < n; ++v) {
		dp[v][v][A] = dp[v][v][B] = 0;
	}

	for(int iter = 0; iter < 2 * n; ++iter) {
		for(int v = 0; v < n; ++v) {
			for(int u = 0; u < n; ++u) {
				if(v == u) continue;

				// Aaron turn
				dp[v][u][A] = 0;
				for(const auto &to : G[v]) {
					chmax(dp[v][u][A], dp[to][u][B]);
				}

				// Bruce turn
				for(const auto &to : G[u]) {
					chmin(dp[v][u][B], dp[v][to][A] + 1);
				}
			}
		}
	}

	int a, b;
	cin >> a >> b;

	return dp[a][b][A] >= n ? "infinity" : to_string(dp[a][b][A]);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while(T--) cout << solve() << endl;

	return EXIT_SUCCESS;
}