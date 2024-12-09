#include <bits/stdc++.h>

using namespace std;

const long long r = 1e9 + 7;

long long d[5001][5002];

long long f(long long a, long long p) {
	if (p == 1)
		return a;

	long long ret = f(a, p / 2);
	ret = ret * ret % r;
	if (p % 2 == 1)
		ret = ret * a % r;

	return ret;
}

int main() {
	int n;
	string s;
	cin >> n >> s;

	d[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		d[i][0] = (d[i - 1][0] + d[i - 1][1]) % r;
		for (int j = 1; j <= n; ++j)
			d[i][j] = (2 * d[i - 1][j - 1] + d[i - 1][j + 1]) % r;
	}

	long long tmp = 1;
	for (int i = 0; i < s.length(); ++i)
		tmp = tmp * 2 % r;

	printf("%lld", d[n][s.length()] * f(tmp, r - 2) % r);

	return 0;
}