#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> Pii;
 
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
 
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
 
template<int mod, int primitive_root>
class NTT {
public:
	int get_mod() const { return mod; }
	void _ntt(vector<ll>& a, int sign) {
		const int n = sz(a);
		assert((n ^ (n&-n)) == 0); //n = 2^k
 
		const int g = 5; //g is primitive root of mod
		int h = (int)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
		if (sign == -1) h = (int)mod_inv(h, mod); //h = h^-1 % mod
 
		//bit reverse
		int i = 0;
		for (int j = 1; j < n - 1; ++j) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (j < i) swap(a[i], a[j]);
		}
 
		for (int m = 1; m < n; m *= 2) {
			const int m2 = 2 * m;
			const ll base = mod_pow(h, n / m2, mod);
			ll w = 1;
			FOR(x, m) {
				for (int s = x; s < n; s += m2) {
					ll u = a[s];
					ll d = a[s + m] * w % mod;
					a[s] = u + d;
					if (a[s] >= mod) a[s] -= mod;
					a[s + m] = u - d;
					if (a[s + m] < 0) a[s + m] += mod;
				}
				w = w * base % mod;
			}
		}
 
		for (auto& x : a) if (x < 0) x += mod;
	}
	void ntt(vector<ll>& input) {
		_ntt(input, 1);
	}
	void intt(vector<ll>& input) {
		_ntt(input, -1);
		const int n_inv = mod_inv(sz(input), mod);
		for (auto& x : input) x = x * n_inv % mod;
	}
 
	// 畳み込み演算を行う
	vector<ll> convolution(const vector<ll>& a, const vector<ll>& b){
		int ntt_size = 1;
		while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;
 
		vector<ll> _a = a, _b = b;
		_a.resize(ntt_size); _b.resize(ntt_size);
 
		ntt(_a);
		ntt(_b);
 
		FOR(i, ntt_size){
			(_a[i] *= _b[i]) %= mod;
		}
 
		intt(_a);
		return _a;
	}
};
 
const ll MOD=998244353;
const ll inv3=332748118;
typedef NTT<MOD, 3> NTT_1;
NTT_1 ntt;
ll ans;
int n;
string s;
void solve(int l, int r){
    if(r-l<2) return;
    int m=(l+r)/2;
    vector<ll> x(m-l+1), y(r-m);
    for(int i=0; i<m-l+1; i++){
        if(s[l+i]=='U') x[i]=1;
        else if(s[l+i]=='?') x[i]=inv3;
    }
    for(int i=0; i<r-m; i++){
        if(s[m+1+i]=='G') y[i]=1;
        else if(s[m+1+i]=='?') y[i]=inv3;
    }
    vector<ll> z=ntt.convolution(x, y);
    z.resize(r-l);
    for(int i=l; i<=r; i++){
        if(2*i-m-l-1<0 || 2*i-m-l-1>=r-l) continue;
        if(s[i]=='M') (ans+=z[2*i-m-l-1])%=MOD;
        else if(s[i]=='?') (ans+=z[2*i-m-l-1]*inv3)%=MOD;
    }
    solve(l, m);
    solve(m+1, r);
}
int main()
{
    cin>>s;
    n=s.size();
    ll p=1;
    for(int i=0; i<n; i++) if(s[i]=='?') p=p*3%MOD;
    solve(0, n-1);
    ans=ans*p%MOD;
    cout<<ans<<endl;
    return 0;
}
