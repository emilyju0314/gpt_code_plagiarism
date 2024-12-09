#include <stdio.h>
long long p, g, k, h;
long long a[3000];
long long b[3000];
long long c[3000];
long long f[3000];
long long rui(long long x, long long y) {
	if (y == 0)return 1;
	if (y == 1)return x;
	if (y == 2)return x * x % p;
	if (y % 2)return (rui(rui(x, y / 2), 2)) * x % p;
	else return rui(rui(x, y / 2), 2);
}
int main() {
	scanf("%lld", &p);
	g = 2;
	while (true) {
		k = 1;
		for (int i = 2; i * i <= p - 1; i++) {
			if ((p - 1) % i == 0) {
				if (rui(g, (p - 1) / i) == 1)k = 0;
				if (rui(g, i) == 1)k = 0;
			}
		}
		if (k)break;
		g++;
	}
	for (int i = 0; i < p; i++) {
		scanf("%lld", a + i);
	}
	if (p == 2 && a[0] == 1 && a[1] == 1) {
		printf("1 0\n");
		return 0;
	}
	if (p == 2 && a[0] == 0 && a[1] == 1) {
		printf("0 1\n");
		return 0;
	}
	for (int i = 1; i < p; i++) {
		c[i] = a[rui(g, i)];
	}
	for (int i = 1; i < p; i++) {
		a[i] = c[i];
	}
	if (a[0] == 1) {
		b[0] = 1;
		for (int i = 1; i < p; i++) {
			a[i] += p - 1;
			a[i] %= p;
		}
	}
	f[0] = 1;
	for (int i = 1; i < p; i++) {
		f[i] = g * f[i - 1] % p;
	}
	for (long long i = 1; i < p; i++) {
		for (long long j = 1; j < p; j++) {
			b[i] += a[j] * (p - 1) * f[i * j * (p - 2) % (p - 1)];
			b[i] %= p;
		}
	}
	for (int i = 0; i < p - 1; i++) {
		printf("%lld ", b[i]);
	}
	printf("%lld\n", b[p - 1]);
}