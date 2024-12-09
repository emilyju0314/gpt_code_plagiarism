#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[10000000];
int main() {

	ll i, j, k, l, test, n;
	cin >> n;

	for (i = 0; i < n; i++) cin >> a[i];

	for (i = 0; i < n; i++) {
		a[i] -= (i + 1);
	}
	ll sum = 0;
	sort(a, a + n);
	for (i = 0; i < n; i++) {
		sum += abs(a[i] - a[n / 2]);
		//cout << a[i] << "\n";
	}
	cout << sum;
}