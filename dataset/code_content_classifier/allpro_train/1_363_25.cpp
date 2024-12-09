#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#pragma comment(linker, "/STACK:2769095000")
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstdlib>
//#include<cstdint>
#include<sstream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<sstream>
#include<numeric>
#include<random>
#include<functional>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<complex>
#include<numeric>
#include<chrono>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef int itn;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;
typedef pair<ll, ld> pid;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
#define xx first
#define yy second
//#define int __int128t
//#define F first
//#define S second
#define zz second
#define mp make_pair
#define y1 oshfkfsldhs
#define union jfghjdghdjhgjhdjgh
#define all(x) (x).begin(), (x).end()
#define out(x) return void(cout << (x) << endl)
#define OUT(x) ((cout << (x)), exit(0))
const ll MOD = (ll)998244353;
const ll MOR = (ll)1e9 + 33;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const char dc[] = { 'D', 'U', 'R', 'L' };
const ll INF = 1e16 + 100;
const ld EPS = 1e-10;
const double PI = 3.14159265358979323846;
const int SZ = 80000001;
const ll MAXN = (1 << 20) + 100;

#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
typedef __int64 int128;
#else
//typedef __int128 int128;
#endif

inline void getint(int& x) {
	int c = getc(stdin);
	x = 0;
	while (c <= 32)
		c = getc(stdin);
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getc(stdin);
	return;
}
inline void writeint(int& x)
{
	char s[10];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		putc(s[n], stdout);
	putc('\n', stdout);
}

ll n, m, k, x, y, z, a[MAXN], b[MAXN], cnt[2][MAXN];


ll gcd(ll x, ll y)
{
	if (x == 0)
		return y;
	return gcd(y % x, x);
}

ll lcm(ll x, ll y)
{
	return x / gcd(x, y) * y;
}
map<ll, vector<pii>> mem;
vector<pii> primes(ll x)
{
	if (mem.count(x))
		return mem[x];
	ll cx = x;
	vector<pii> res;
	for (ll d = 2; d * d < x; d++)
	{
		if (x % d == 0)
		{
			res.push_back({ d, 0 });
			while (x % d == 0)
				res.back().yy++, x /= d;
		}
	}
	if (x > 1)
		res.push_back({ x, 1 });
	return mem[cx] = res;
}

ll bp(ll x, ll st, ll mod)
{
	if (st == 0)
		return 1;
	if (st & 1)
		return x * bp(x, st - 1, mod) % mod;
	return bp(x * x % mod, st >> 1, mod);
}

vector<ll> pr, phi;
vector<pii> d;
vector<ll> step, d1, d2;
ll rev[100][100];

ll KTO(ll r1, ll p1, ll r2, ll p2)
{
	//cout << r1 << " " << p1 << "   " << r2 << " " << p2 << "\n";
	
	r1 %= p1;
	r2 %= p2;
	if (p1 == 1)
		return r2;
	if (p2 == 1)
		return r1;
	//vector<pii> d = primes(lcm(p1, p2));
	//vector<ll> pr;
	//vector<ll> phi;
	ll k = pr.size();
	vector<ll> x(k, 0);
	vector<ll> r(k, 0);
	for (int i = 0; i < k; i++)
	{
		if (d1[i] < d2[i])
		{
			if (r1 % d1[i] == r2 % d1[i])
				r[i] = (r2 % d2[i]);
			else
				return -1;
		}
		else
		{
			if (r1 % d2[i] == r2 % d2[i])
				r[i] = (r1 % d1[i]);
			else
				return -1;
		}
	}
	for (int i = 0; i < k; ++i) {
		x[i] = r[i];
		for (int j = 0; j < i; ++j) {
			x[i] = rev[j][i] * (x[i] - x[j] + pr[i]) % pr[i];
		}
	}
	//if (x.size() == 0)
	//	exit(124124);
	ll ans = x[0], w = 1;
	for (int i = 1; i < k; i++)
	{
		w *= pr[i - 1];
		ans += x[i] * w;
	}
	//cout << ans << "\n\n";
	return ans;
}

void solve()
{
	cin >> n >> m >> k;
	fill(cnt[0], cnt[0] + MAXN, -1);
	fill(cnt[1], cnt[1] + MAXN, -1);
	for (int i = 0; i < n; i++)
		cin >> a[i], cnt[0][a[i]] = i;
	for (int j = 0; j < m; j++)
		cin >> b[j], cnt[1][b[j]] = j;


	ll per = lcm(n, m);
	ll agr = per;
	vector<ll> it;
	d = primes(per);
	for (auto p : d)
	{
		ll x = pow(p.xx, p.yy);
		step.push_back(x);
		phi.push_back(x - x / p.xx);
		for (int j = 0; j < pr.size(); j++)
			rev[j][pr.size()] = bp(pr[j], phi[pr.size()] - 1, x);
		pr.push_back(x);
		d1.push_back(gcd(x, n));
		d2.push_back(gcd(x, m));
	}



	for (int i = 0; i <= 2 * max(n, m); i++)
	{
		if (cnt[0][i] == -1 || cnt[1][i] == -1)
			continue;
		ll pos = KTO(cnt[0][i], n, cnt[1][i], m);
		if (pos != -1)
		{
			agr--;
			it.push_back(pos);
		}
	}
	ll ans = k / agr * per;
	k %= agr;
	sort(all(it));
	if (k == 0)
	{
		ans -= per;
		k += agr;
	}
	it.push_back(per + 1);
	for (int i = 0; i < it.size(); i++)
	{
		if (k > it[i] - i)
			continue;
		cout << ans + k + i;
		return;
	}
}


int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(11);
#ifdef _DEBUG
	auto _ = freopen("input.txt", "r", stdin);
	_ = freopen("output.txt", "w", stdout);
#else
	//auto _ = freopen("input.txt", "r", stdin);
	//_ = freopen("output.txt", "w", stdout);
#endif
	int test = 1;
	//cin >> test;
	while (test--)
	{
		solve();
	}
}