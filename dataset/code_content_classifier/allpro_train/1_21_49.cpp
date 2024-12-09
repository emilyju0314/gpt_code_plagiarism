#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define debug(x) cout << #x << " is " << x << endl
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f, N = 2e5 + 15;
const ll MOD = 1e9 + 7;

int t, n, m;
ll a[N];

int main() 
{
	for (int i = 0; i <= 9; ++i) a[i] = 1;
	for (int i = 10; i <= N; ++i) a[i] = (a[i-9] + a[i-10]) % MOD;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		ll ans = 0;
		while (n) {
			(ans += a[n%10+m]) %= MOD;
			n /= 10;
		}
		printf("%lld\n", ans);
	}
    return 0;
}