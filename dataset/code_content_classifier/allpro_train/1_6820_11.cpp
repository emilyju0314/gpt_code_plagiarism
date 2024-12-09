#include <bits/stdc++.h>

const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
const int MAXN = 210;
LL A[MAXN], B[MAXN], C[MAXN], D[MAXN], K, li[MAXN];
int n;
std::map<std::vector<LL>, std::vector<std::pair<LL, LL>>> M;
int calc(LL l, LL r) {
	int res = 0;
	for (int i = 60; ~i; --i)
		if ((r >> i & 1) != (l >> i & 1)) {
			res += !!l; break;
		} else res += r >> i & 1, l ^= (r >> i & 1) << i;
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 0; i <= 60; ++i) {
		for (int j = 1; j <= n; ++j)
			B[j] = A[j] >> i, li[j] = (C[j] = A[j] & (1ll << i) - 1) + 1;
		li[n + 1] = 1ll << i, li[n + 2] = 0;
		std::sort(li + 1, li + 3 + n);
		int bak = std::unique(li + 1, li + 3 + n) - li - 1;
		for (int j = 1; j < bak; ++j) {
			LL stp = K - i - calc(li[j], li[j + 1] - 1);
			for (int k = 1; k <= n; ++k)
				stp = std::min(stp, D[k] = B[k] - (C[k] < li[j]));
			for (int k = n; k > 1; --k) D[k] -= D[k - 1];
			if (stp >= 0)
			M[std::vector<LL> (D + 2, D + n + 1)].emplace_back(std::max(D[1] - stp, 0ll), D[1]);
		}
	}
	int ans = 0;
	for (auto t : M) {
		auto & v = t.second;
		std::sort(v.begin(), v.end());
		LL lst = -1;
		for (auto i : v) {
			lst = std::max(lst, i.first - 1);
			reduce(ans += remod(std::max(i.second - lst, 0ll)) - mod);
			lst = i.second;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
