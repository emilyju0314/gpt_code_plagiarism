#include <iostream>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define int long long
using namespace std;
int s;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ans = 0;
	int N;
	cin >> N;
	while (N--)
	{
		int a;
		cin >> a;
		ans += a * s;
		ans %= MOD;
		s = (s + a) % MOD;
	}
	cout << ans;
}