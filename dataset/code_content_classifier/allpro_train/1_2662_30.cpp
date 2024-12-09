//besmellah
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	int a, b, k;
	cin >> a >> b >> k;
	cout << a - min(a, k) << ' ' << max(0ll, b - max(k - a, 0ll));
}
