#include <bits/stdc++.h>

[[noreturn]] void FAIL() {
	std::cout << "NO" << '\n';
	exit(0);
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; int64_t C; cin >> N >> C;
	vector<int64_t> W(N-2); for (auto& w : W) cin >> w;
	W.push_back(W.back());

	// there are 2 types of nontrivial events:
	//   either we take the full range at a particular interval, or we take a full range at a location
	// Either way, we can store it by the original loc

	vector<bool> can_full(N-1);
	vector<int> prv(N-1, -1);
	vector<int64_t> prv_val(N-1);

	int cur_sign = 1;
	int64_t cur_plus = 0;
	deque<pair<array<int64_t, 2>, int>> cur_poss;
	cur_poss.push_back({{0, W[0]}, -1}); // inclusive interval
	for (int i = 0; i < N-1; i++) {
		// first, trim the high and low
		if (cur_sign == 1) {
			while (!cur_poss.empty() && cur_poss.back().first[0] + cur_plus > W[i]) {
				cur_poss.pop_back();
			}
			if (!cur_poss.empty() && cur_poss.back().first[1] + cur_plus > W[i]) {
				cur_poss.back().first[1] = W[i] - cur_plus;
			}

			while (!cur_poss.empty() && cur_poss.front().first[1] + cur_plus < 0) {
				cur_poss.pop_front();
			}
			if (!cur_poss.empty() && cur_poss.front().first[0] + cur_plus < 0) {
				cur_poss.front().first[0] = 0 - cur_plus;
			}
		} else if (cur_sign == -1) {
			while (!cur_poss.empty() && -cur_poss.front().first[1] + cur_plus > W[i]) {
				cur_poss.pop_front();
			}
			if (!cur_poss.empty() && -cur_poss.front().first[0] + cur_plus > W[i]) {
				cur_poss.front().first[0] = -(W[i] - cur_plus);
			}

			while (!cur_poss.empty() && -cur_poss.back().first[0] + cur_plus < 0) {
				cur_poss.pop_back();
			}
			if (!cur_poss.empty() && -cur_poss.back().first[1] + cur_plus < 0) {
				cur_poss.back().first[1] = -(0 - cur_plus);
			}
		} else assert(false);

		if (cur_poss.empty()) {
			FAIL();
		}

		if (cur_sign == 1) {
			if (cur_poss.back().first[1] + cur_plus == W[i]) {
				can_full[i] = true;
				prv[i] = cur_poss.back().second;
				prv_val[i] = W[i];
			}
		} else if (cur_sign == -1) {
			if (-cur_poss.front().first[0] + cur_plus == W[i]) {
				can_full[i] = true;
				prv[i] = cur_poss.front().second;
				prv_val[i] = W[i];
			}
		} else assert(false);

		if (can_full[i]) {
			cur_sign = 1;
			cur_plus = 0;
			cur_poss.clear();
			cur_poss.push_back({{0, W[i]}, i});
		} else {
			// pick something arbitrary to be +
			if (cur_sign == 1) {
				if (cur_poss.front().first[0] + cur_plus != 0) {
					prv_val[i] = cur_poss.front().first[0] + cur_plus;
					prv[i] = cur_poss.front().second;
					cur_poss.push_front({{0 - cur_plus, 0 - cur_plus}, i});
				}
			} else if (cur_sign == -1) {
				if (-cur_poss.back().first[1] + cur_plus != 0) {
					prv_val[i] = -cur_poss.back().first[1] + cur_plus;
					prv[i] = cur_poss.back().second;
					cur_poss.push_back({{-(0 - cur_plus), -(0 - cur_plus)}, i});
				}
			} else assert(false);

			assert(prv[i] == -1 || (0 < prv_val[i] && prv_val[i] < W[i]));

			cur_sign = -cur_sign;
			cur_plus = W[i] - cur_plus;
		}
	}

	assert(can_full[0]);
	assert(can_full[N-2]);

	vector<int64_t> H(N);
	H[N-1] = 0;
	int delta_sign = 1;
	for (int cur = N-2; cur != -1; ) {
		int p = prv[cur];
		int64_t v = prv_val[cur];
		delta_sign *= -1;
		H[cur] = H[cur+1] + delta_sign * v;
		while (--cur != p) {
			v = W[cur] - v;
			H[cur] = H[cur+1] + delta_sign * v;
		}
	}

	for (int i = 0; i < N-2; i++) {
		if (max({H[i], H[i+1], H[i+2]}) - min({H[i], H[i+1], H[i+2]}) != W[i]) {
			assert(false);
		}
	}
	int64_t min_H = *min_element(H.begin(), H.end());
	cout << "YES" << '\n';
	for (int i = 0; i < N; i++) {
		H[i] -= min_H;
		cout << H[i] << " \n"[i+1==N];
	}

	return 0;
}
