#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, ans[N], ord[N];
long long qn, a[N], t[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
		ord[i] = ans[i] = i;
	}
	for (int i = n; i >= 1; --i) {
		a[i] -= a[i - 1];
	}
	scanf("%d%lld", &m, &qn);
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		swap(ord[x], ord[x + 1]);
	}
	for (; qn; qn >>= 1) {
		if (qn & 1) {
			for (int i = 1; i <= n; ++i) {
				ans[i] = ord[ans[i]];
			}
		}
		for (int i = 1; i <= n; ++i) {
			t[i] = ord[ord[i]];
		}
		for (int i = 1; i <= n; ++i) {
			ord[i] = t[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		t[i] = a[ans[i]];
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = t[i] + a[i - 1];
		printf("%lld.0\n", a[i]);
	}
}