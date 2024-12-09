#include <bits/stdc++.h>

using namespace std;

int a[111111];
int main() {
	int n, m = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	long c = 0;
	for (int i = 0; i < n; i++) {
		int b;
		scanf("%d", &b);
		a[i] = b - a[i];
		if (a[i] > 0) c += a[i], m++;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++, m++) {
		if (c <= 0) break;
		if (a[i] >= 0) {
			m = -1;
			break;
		}
		c += a[i];
	}
	cout << m << endl;
	return 0;
}
