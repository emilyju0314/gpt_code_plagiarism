#include<vector>
#include<queue>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include <bitset>

using namespace std;

//int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef vector<char>vc;
typedef vector<string>vs;
typedef vector<vector<int>>vii;
typedef vector<vector<char>>vvc;
typedef vector<vector<ll>>vll;
typedef vector< pair<ll, ll>>vpll;
typedef vector< pair<ld, ld>>vpld;
typedef vector< pair<int, int>>vpi;
typedef pair<ld, ld>pld;
#define mp make_pair
#define pb push_back

int mod = 1000000007;
int sum(int a, int b)
{
	int c = a + b;
	if (c >= mod)
	{
		c -= mod;
	}
	return c;
}
int dif(int a, int b)
{
	int c = a - b;
	if (c < 0)
	{
		c += mod;
	}
	return c;
}
int mlt(int a, int b)
{
	ll c = a * 1LL * b;
	return c % mod;
}
int ibit(int n, int i)
{
	return ((n >> i) & 1);
}
void outp(vii &ou)
{
	for (int i = 0; i < ou.size(); i++)
	{
		for (int j = 0; j < ou[i].size(); j++)
		{
			cout << ou[i][j] << ' ';
		}
		cout << '\n';
	}
}
int bp(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	int a = 0;
	if (!(y % 2))
	{
		a = bp(x, y / 2);
	}
	return (y % 2) ? mlt(bp(x, y - 1), x) : mlt(a, a);
}
int obr(int x)
{
	return bp(x, mod - 2);
}
const int maxn = 10000007;
int fact[1000007], ofact[1000007];
void prec()
{
	fact[0] = 1;
	ofact[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		fact[i] = mlt(fact[i - 1], i);
	}
	//cerr << "sdsds" << endl;
	ofact[maxn - 1] = obr(fact[maxn - 1]);
	for (int i = maxn - 2; i > 0; i--)
	{
		ofact[i] = mlt(ofact[i + 1], i + 1);
	}
}
int c(int a, int b)
{
	return ((a <= b) && (a >= 0)) ? mlt(fact[b], mlt(ofact[a], ofact[b - a])) : 0;
}
ll gcd(ll x, ll y)
{
	//cerr << x << y << endl;
	if (x == 0)return y;
	return(x > y) ? gcd(y, x) : gcd(y%x, x);
}
void upd(ll x, ll y, ll &curx, ll &cury)
{
	ld x1 = (ld)x / (ld)y;
	ld cur1 = (ld)curx / ld(cury);
	if (x1>cur1 + 1e-17)
	{
		curx = x / gcd(x, y);
		cury = y / gcd(x, y);
	}
}
ll good(vl &prefs, vi &a, vi&b, int excl, int len, ll summ, vi&ord, vpi &h)
{
	if (len < 0)return 0LL;
	if (len >= ord.size()) return -1LL;
	//cerr << summ << endl;
	ll sum1 = summ - (ll)max(0, b[excl] - a[excl]), psum = prefs[len];
	if (ord[excl] < len)psum = psum - max(a[excl], b[excl]) + h[len].first;
	sum1 += b[excl] - a[excl];
//	cerr << excl << ' ' << len << ' ' << summ << ' ' << sum1<<' '<< psum << endl;
	return max(sum1 - psum, -1LL);
}
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	vpi h(n);
	vi a(n), b(n), ord(n), aord(n);
	vl prefs(n + 1);
	ll summ = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		h[i] = mp(max(a[i], b[i]), i);
		summ += max(b[i] - a[i], 0);
	}
	sort(h.begin(), h.end());
	for (int i = 0; i < n; i++)
	{
		prefs[i + 1] = prefs[i] + h[i].first;
		ord[h[i].second] = i;
		aord[i] = h[i].second;
	}
	//cerr <<summ<<' '<< aord[0] << ' '<<b[0]<< ' '<<prefs[0]<<' '<<prefs[1]<<' '<<prefs[2]<<' '<<prefs[3]<<endl;
	ll curx = 0, cury = 1;
	for (int k = 0; k < n; k++)
	{
		int lb = -1, rb = n - 1;
		for (int i = 0; i < 50; i++)
		{
			int mid = (rb + lb + i % 2) / 2;
			ll val = good(prefs, a, b, k, mid, summ, ord, h);
			if (val < 0)rb = mid - 1;
			else {
				lb = mid;
				if (mid >= 0)
				{
			//		assert(val <= (ll)b[aord[mid]]);
					ll num = mid * 1LL * b[k] + min(val, (ll)b[k]), den = b[k] * 1LL * n;
					upd(num, den, curx, cury);
		//			cerr << "dsdsd" <<k<<' '<<val<<' '<< num << ' ' << den << ' ' << mid << ' ' << val << ' ' << b[aord[mid]] << endl;
				}
			}
		}
	//	cerr <<"?! "<< k << ' ' << curx << ' ' << cury << endl;
	}
	cout << curx << ' ' << cury << endl;
}
int main()
{
	//prec();
	//cerr << "Here" << endl;
	solve();
	int n;
	cin >> n;
}