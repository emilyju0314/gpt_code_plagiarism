#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long fact[2000005], inv[2000005];
char s[1000005];

long long mypow(long long x, long long y) {
	long long res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		y >>= 1;
		x = x * x % MOD;
	}
	return res;
}

long long ncr(int x, int y) {
	if (y < 0 || y > x) return 0;
	return fact[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main() {
	int k;
	scanf("%d", &k);
	scanf("%s", s);
	int l = strlen(s);
	
	fact[0] = 1;
	for (int i = 1; i <= k + l; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	inv[k + l] = mypow(fact[k + l], MOD - 2);
	for (int i = k + l - 1; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	}
	
	long long res = 0;
	
	for (int i = l; i <= k + l; i++) {
		res = (res + ncr(i - 1, l - 1) * mypow(25, i - l) % MOD * mypow(26, k + l - i) % MOD) % MOD;
	}
	
	printf("%lld\n", res);
}
