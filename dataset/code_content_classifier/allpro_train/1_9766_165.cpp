#include <iostream>
using namespace std;

const int mxn = 1e5 + 5;
long long n, a[mxn], sfx[mxn];

int main() {
	cin >> n;
	for (int i=0; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=n; i>=0; i--) {
		sfx[i] = sfx[i + 1] + a[i];
	}
	long long nodes = 1, ans = 0;
	for (int i=0; i<=n; i++) {
		ans += nodes;
		if (a[i] > nodes) {
			cout << -1 << '\n';
			return 0;
		}
		nodes = min(sfx[i + 1], 2 * (nodes - a[i]));
	}
	cout << ans << '\n';
}