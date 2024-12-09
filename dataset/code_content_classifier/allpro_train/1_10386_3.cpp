#include <bits/stdc++.h>
using namespace std;

template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

typedef pair<int, int> point;
#define X first
#define Y second

struct state {
	point pos;
	int cost;

	state(int x, int y, int cost_):pos(x, y), cost(cost_) {}

	bool operator<(const state &s) const {
		return cost < s.cost;
	}
};

inline bool in_range(int l, int r, int x) {
	return l <= x && x <= r;
}

inline int calc_best(int l, int r, int x) {
	return x < l ? l : r < x ? r : x;
}

inline int dist(const point &a, const point &b) {
	return abs(a.X - b.X) + abs(a.Y - b.Y);
}

void reduce(vector<state> &states) {
	sort(begin(states), end(states));

	const int n = states.size();
	vector<bool> ok(n, true);
	int last = 0;

	for(int i = 0; i < n; ++i) {
		if(ok[i]) {
			for(int j = i + 1; j < n; ++j) {
				if(ok[j] && states[j].cost - states[i].cost >= dist(states[i].pos, states[j].pos)) {
					ok[j] = false;
				}
			}
			states[last++] = states[i];
		}
	}

	states.erase(begin(states) + last, end(states));
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int n; cin >> n && n;) {
		int m, k, r;
		cin >> m >> k >> r;

		vector<int> cx, cy;
		vector<int> rx(n), ry(n), rz(n);

		for(int i = 0; i < n; ++i) {
			cin >> rx[i] >> ry[i] >> rz[i];
			cx.emplace_back(rx[i]);
			cy.emplace_back(ry[i]);
			--rz[i];
		}

		vector<vector<pair<point, point>>> holes(k);
		for(int i = 0; i < m; ++i) {
			int x1, y1, x2, y2, w;
			cin >> x1 >> y1 >> x2 >> y2 >> w;
			holes[w - 1].emplace_back(point(x1, y1), point(x2, y2));

			if(w == k) {
				if(x1 > 1) cx.emplace_back(x1 - 1);
				if(x2 < r) cx.emplace_back(x2 + 1);
				if(y1 > 1) cy.emplace_back(y1 - 1);
				if(y2 < r) cy.emplace_back(y2 + 1);
			}

			cx.emplace_back(x1);
			cx.emplace_back(x2);
			cy.emplace_back(y1);
			cy.emplace_back(y2);
		}

		vector<state> candidate;
		candidate.reserve(cx.size() * cy.size());
		sort(begin(cx), end(cx));
		sort(begin(cy), end(cy));
		cx.erase(unique(begin(cx), end(cx)), end(cx));
		cy.erase(unique(begin(cy), end(cy)), end(cy));

		for(const auto &x : cx) {
			for(const auto &y : cy) {
				for(const auto &hole : holes.back()) {
					if(in_range(hole.first.X, hole.second.X, x) && in_range(hole.first.Y, hole.second.Y, y)) {
						goto next_candidate;
					}
				}
				candidate.emplace_back(x, y, 0);
			next_candidate:;
			}
		}

		int ans = 0;
		for(int r_idx = 0; r_idx < n; ++r_idx) {
			ans += (k - (rz[r_idx] + 1)) * 100;

			vector<state> dp(1, state(rx[r_idx], ry[r_idx], 0));

			for(int i = rz[r_idx] + 1; i < k; ++i) {
				vector<state> next_dp;

				for(const auto &s : dp) {
					for(const auto &hole : holes[i]) {
						const int x = calc_best(hole.first.X, hole.second.X, s.pos.X);
						const int y = calc_best(hole.first.Y, hole.second.Y, s.pos.Y);
						next_dp.emplace_back(x, y, s.cost + dist(s.pos, make_pair(x, y)));
					}
				}

				dp = move(next_dp);
				reduce(dp);
			}

			for(auto &c : candidate) {
				int min_cost = INT_MAX;

				for(const auto &e : dp) {
					chmin(min_cost, e.cost + dist(c.pos, e.pos));
				}
				c.cost += min_cost;
			}
		}

		ans += min_element(begin(candidate), end(candidate))->cost;
		cout << ans << endl;
	}

	return EXIT_SUCCESS;
}