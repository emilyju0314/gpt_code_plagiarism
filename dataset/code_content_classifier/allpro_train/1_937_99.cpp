// Addition and Subtraction Hard
// * frank_c1
// * 2017 / 10 / 04

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = (int)(1e5) + 5;
LL f[3];
char opt[3];

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	f[0] = x; f[1] = f[2] = -(LL)(1e18);
	for (int i = 1; i < n; ++i) {
		scanf("%s%d", opt, &x);
		for (int j = 0; j < 2; ++j) f[j] = max(f[j], f[j + 1]);
		if (opt[0] == '+') for (int j = 0; j < 3; ++j) f[j] += (j & 1) ? -x : x;
		else {
			for (int j = 0; j < 3; ++j) f[j] += (j & 1) ? x : -x;
			for (int j = 2; j > 0; --j) f[j] = max(f[j], f[j - 1]);
		}
	}
	return printf("%lld\n", max(f[0], f[1])), 0;
}