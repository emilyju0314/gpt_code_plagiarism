#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define REP(i, a, b) for(int i = (a); i < int(b); ++i)
#define rep(i, n) REP(i, 0, n)

struct union_find {
	vector<int> uf;
	vector<int> num;

	union_find(int n):uf(2 * n, -1), num(2 * n, 0) {
		fill(num.begin(), num.begin() + n, 1);
	}

	inline bool root(int x) const {
		return uf[x] < 0;
	}

	inline int find(int x) {
		return root(x) ? x : uf[x] = find(uf[x]);
	}

	inline void unite(int x, int y) {
		x = find(x);
		y = find(y);

		if(x == y) return;

		if(uf[x] > uf[y]) {
			swap(x, y);
		}

		num[x] += num[y];
		uf[x] += uf[y];
		uf[y] = x;
	}

	inline int number_of_sets() const {
		return count_if(uf.begin(), uf.begin() + uf.size() / 2, [](int x) { return x < 0; });
	}
};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int n, p1, p2; cin >> n >> p1 >> p2 && (n | p1 | p2);) {
		const int V = p1 + p2;
		union_find uf(V);

		bool has_no = false;
		rep(i, n) {
			int x, y;
			string s;
			cin >> x >> y >> s;
			--x; --y;

			if(s[0] == 'n') { // no
				y += V;
				has_no = true;
			}

			uf.unite(x, y);
			uf.unite(x + V, (y + V) % (2 * V));
		}

		if(p1 == 0) {
			cout << (has_no ? "no" : "end") << endl;
			continue;
		}

		if(p2 == 0) {
			if(has_no) {
				cout << "no" << endl;
				continue;
			}

			rep(i, V) {
				cout << i + 1 << endl;
			}
			cout << "end" << endl;
			continue;
		}

		const int m = uf.number_of_sets();

		vector<int> idx, a, b;
		idx.reserve(m);
		a.reserve(m);
		b.reserve(m);

		rep(i, V) {
			if(uf.root(i) || uf.root(i + V)) {
				idx.emplace_back(i);
				a.emplace_back(uf.num[i]);
				b.emplace_back(uf.num[i + V]);
			}
		}

		vector<vector<int>> dp(m + 1, vector<int>(V + 1, 0));
		dp[0][0] = 1;

		rep(i, m) {
			rep(j, V - a[i]) {
				dp[i + 1][j + a[i]] += dp[i][j];
			}

			rep(j, V - b[i]) {
				dp[i + 1][j + b[i]] += dp[i][j];
			}
		}

		if(dp[m][p1] != 1) {
			cout << "no" << endl;
			continue;
		}

		int sum = p1;
		vector<bool> which(m);
		for(int i = m - 1; i >= 0; --i) {
			if(dp[i][sum - a[i]] == 1) {
				which[i] = true;
				sum -= a[i];
			}
			else {
				which[i] = false;
				sum -= b[i];
			}
		}

		vector<int> ans;
		ans.reserve(p1);

		rep(i, V) {
			bool T = true;
			int r = uf.find(i);

			if(r >= V) {
				r = uf.find(r - V);
				T = false;
			}

			const int id = lower_bound(idx.begin(), idx.end(), r) - idx.begin();

			if(which[id]) {
				if(T) ans.emplace_back(i + 1);
			}
			else {
				if(!T) ans.emplace_back(i + 1);
			}
		}

		for(const auto &e : ans) {
			cout << e << endl;
		}
		cout << "end" << endl;
	}

	return EXIT_SUCCESS;
}