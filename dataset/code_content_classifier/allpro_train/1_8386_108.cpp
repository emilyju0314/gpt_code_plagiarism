#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	ll x[n];
	for (int i = 0;i < n;i++)cin >> x[i];
	ll ans = 0;
	for (int i = 1;i < n;i++) {
		ans += min((x[i] - x[i - 1])*a, b);
	}
	cout << ans << endl;
}