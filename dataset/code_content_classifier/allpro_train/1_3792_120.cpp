#include <iostream>

using i64 = long long;

const int N = 300000 + 7;

int n;
i64 a[N], b[N], s[2];
i64 l, r, m, p;

int main() {
//	freopen("code.in", "r", stdin);
//	freopen("code.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", a + i),
		b[i] = b[i - 1] + (i & 1 ? 1 : -1) * a[i],
		s[i & 1] += a[i];
	if (n % 2 == 0) return printf("%lld %lld", std::max(s[0], s[1]), std::min(s[0], s[1])), 0;

	r = s[0] + s[1];
	while (l < r) {
		m = l + r + 1 >> 1, p = 0;
		for (int i = 1; i < n; i += 2)
			if (b[i] + p >= m) p = std::max(p, a[i + 1] - b[i]);
		b[n] + p >= m ? (l = m) : (r = m - 1);
	}
	m = std::max(s[0] + l, s[1]);
	return printf("%lld %lld", m, s[0] + s[1] - m), 0;
}
