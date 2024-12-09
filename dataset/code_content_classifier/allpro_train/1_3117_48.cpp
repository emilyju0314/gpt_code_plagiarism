#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
using namespace std;
int n;
signed main() {
	cin >> n;
	int ans = n;
	if (n % 2 == 0) { ans /= 2; while (n % 2 == 0)n /= 2; }
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) {
			ans *= i - 1; ans /= i;
			while (n % i == 0)n /= i;
		}
	}
	if (n > 1) { ans *= n - 1; ans /= n; }
	cout << ans << endl;
}
