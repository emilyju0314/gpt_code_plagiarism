#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

class DSU {
	std::vector<int> f, siz;

public:
	DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
	int root(int x) {
		while (x != f[x]) x = f[x] = f[f[x]];
		return x;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	bool merge(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}
	int size(int x) { return siz[root(x)]; }
};

constexpr int ci[4]{1, -1, 0, 0};
constexpr int cj[4]{0, 0, 1, -1};

void solve() {
	int n, m;
	cin >> n >> m;

	vector<string> g(n);
	forn(i, n) cin >> g[i];

	forn(i, n) {
		if (i % 3 != 0) continue;
		forn(j, m) {
			g[i][j] = 'X';
		}
	}

	DSU dsu(n * m);
	forn(i, n) {
		forn(j, m) {
			forn(k, 4) {
				int ni = i + ci[k];
				int nj = j + cj[k];
				if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
				if (g[i][j] != 'X') continue;
				if (g[ni][nj] != 'X') continue;
				dsu.merge(i * m + j, ni * m + nj);
			}
		}
	}

	auto check = [&](int i, int j) -> bool {
		vector<int> p;
		forn(k, 4) {
			int ni = i + ci[k];
			int nj = j + cj[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			if (g[ni][nj] != 'X') continue;
			p.push_back(ni * m + nj);
		}
		for (int x : p) {
			for (int y : p) {
				if (x != y && dsu.same(x, y)) {
					return 0;
				}
			}
		}
		return 1;
	};

	auto add = [&](int i, int j) {
		g[i][j] = 'X';
		forn(k, 4) {
			int ni = i + ci[k];
			int nj = j + cj[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			if (g[ni][nj] != 'X') continue;
			dsu.merge(m * i + j, m * ni + nj);
		}
	};

	forn(i, n) {
		if (i % 3 == 0) continue;
		forn(j, m) {
			if (g[i][j] != 'X') continue;
			forn(k, 2) {
				int ni = i + ci[k];
				int nj = j + cj[k];
				if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
				if (g[ni][nj] == 'X') continue;
				if (check(ni, nj)) add(ni, nj);
			}
		}
	}

	forn(i, n - 2) {
		if (i % 3 != 0) continue;
		forn(j, m) {
			if (check(i + 1, j) && check(i + 2, j)) {
				add(i + 1, j);
				if (check(i + 2, j)) {
					add(i + 2, j);
				}
			}
		}
	}

	forn(i, n) cout << g[i] << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}
