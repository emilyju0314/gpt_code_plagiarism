#include <bits/stdc++.h>
using namespace std;

long long n, a, num, ans, i;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> n;
	for (i=1; i<=n; i++) {
		cin >> a;
		num+=a;
		if (a==0 or i==n) {
			ans+=num/2;
			num=0;
		}
	}
	cout << ans;

}