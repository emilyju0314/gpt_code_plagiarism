#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
vector<ll> v;

int main(void)
{
	vector<ll> v;
	int n, k;
	ll t[1000000];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		if (i!=0) {
			v.push_back(t[i] - t[i - 1] - 1);
		}
	}
	sort(v.begin(), v.end());
	ll ans = n;
	for (int i = 0; i < n-k; i++) {
			ans += v[i];
	}
	cout << ans << endl;
	return 0;
}

