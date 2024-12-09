#include <bits/stdc++.h>
#define de(x)	cout << "  debug  " << #x << "  ==  " << x << endl;
using namespace std;
typedef long long  ll;
const int mod = 1e9 + 7;
inline int qpow(int x, int n) {
	x %= mod;
	int ret = 1;
	while(n) {
		if(n & 1) ret = 1ll * ret * x % mod;
		n >>= 1;
		x = 1ll * x * x % mod;
	}
	return ret;
}
const int maxn = 1e6 + 7;
void solve(int& kas) {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", qpow(n, k));
}
int main () {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr), cout.tie(nullptr);
	int kas = 0, T = 1;
	scanf("%d", &T);
	for (; T > 0; ++ kas, -- T) solve(kas);
	return 0;
}
