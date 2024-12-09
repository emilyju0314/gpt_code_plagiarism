#include <bits/stdc++.h>

typedef long long LL;
const int weight[4] = {1, 1000, 1000000, 1000000000};
const int N = 505;

std::unordered_map<LL, int> num;
LL q[N], ans;

inline int get(LL s, int b) { return s / weight[b] % 1000; }
inline void insert(LL s, int v = 1) {
	for (int i = 0; i < 4; ++i)
		num[s] += v, s = s % 1000 * weight[3] + s / 1000;
}
inline void remove(LL s) { insert(s, -1); }

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	int n; std::cin >> n;
	for (int i = 0; i < n; insert(q[i++]))
		for (int j = 0, x; j < 4; ++j) std::cin >> x, q[i] += (LL) x * weight[j];
	for (int i = 0; i < n; ++i) {
		remove(q[i]);
		for (int j = i + 1; j < n; ++j) {
			remove(q[j]);
			int up[5], down[5]; LL s[4];
			for (int k = 0; k < 4; ++k) up[3 - k] = get(q[i], k); up[4] = up[0];
			for (int k = 0; k < 4; ++k) down[k] = get(q[j], k); down[4] = down[0];
			for (int shift = 0; shift < 4; ++shift) {
				LL prod = 1;
				for (int k = 0; k < 4; ++k) {
					s[k] = up[k] + up[k + 1] * 1000 + down[k + 1] * 1000000 + down[k] * 1000000000LL;
					prod *= num[s[k]], remove(s[k]);
				}
				ans += prod;
				for (int k = 0; k < 4; ++k) insert(s[k]);
				int t = up[3]; up[3] = up[2], up[2] = up[1], up[1] = up[0], up[4] = up[0] = t;
			}
			insert(q[j]);
		}
		insert(q[i]);
	}
	std::cout << ans / 3 << '\n';
	return 0;
}