#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
const int MAXN = 2e5 + 5, MAXM = 2e3 + 5, BOUND = 2e5, MOD = 1e9 + 7, INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0), eps = 1e-3;
#define mid l + ((r-l)>>1)
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define lc(x) ch[x][0]
#define pii pair<int,int>
#define rc(x) ch[x][1]
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int b, w;
ll inv2, inv[MAXN], fact[MAXN];
void exgcd(int a, int b, int &x, int &y) {
	if (b == 0) { x = 1, y = 0; return; }
	exgcd(b, a%b, y, x); y -= (a / b) * x;
}
void init(int n) {
	int x, y;
	exgcd(2, MOD, x, y);
	inv2 = (x%MOD + MOD) % MOD;
	fact[0] = fact[1] = 1;
	rep(i, 2, n)fact[i] = fact[i - 1] * i%MOD;
	exgcd(fact[n], MOD, x, y);
	inv[n] = (x%MOD + MOD) % MOD;
	for (int i = n - 1; ~i; i--)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> b >> w;
	init(b + w);
	ll q = 0, p = 0, denominator = 1;
	rep(i, 0, b + w - 1) {
		if (i >= b) {
			p = (p + denominator * fact[i - 1] % MOD * inv[i - b] % MOD * inv[b - 1]) % MOD;
		}
		if (i >= w) {
			q = (q + denominator * fact[i - 1] % MOD  * inv[i - w] % MOD  * inv[w - 1]) % MOD;
		}
		denominator = denominator * inv2%MOD;
		cout << (1 + q - p + MOD) % MOD * inv2 %MOD << '\n';
	}
	return 0;
}