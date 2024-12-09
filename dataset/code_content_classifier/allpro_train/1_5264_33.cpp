#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, a[100008], p[200009], sum = 0, maxn = 0;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n - 1; i++) {
		long long L = a[i], R = a[i + 1]; if (L > R) R += m; sum += (R - L);
		if (R - L <= 1) continue;
		p[L + 2]++;
		p[R + 1] -= (R - L);
		p[R + 2] += (R - L - 1);
	}
	for (int i = 1; i <= 2 * m + 1; i++) p[i] += p[i - 1];
	for (int i = 1; i <= 2 * m + 1; i++) p[i] += p[i - 1];
	long long maxn = 0;
	for (int i = 1; i <= m; i++) maxn = max(maxn, p[i] + p[i + m]);
	cout << sum - maxn << endl;
	return 0;
}