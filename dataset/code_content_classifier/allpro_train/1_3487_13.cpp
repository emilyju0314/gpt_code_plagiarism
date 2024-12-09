#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ll long long
#define PI 3.1415926535897932384626
#define endl '\n'
#define FIO                           \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, x) for (auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for (auto it = x.rbegin(); it != x.rend(); it++)

#define umin(...) min({__VA_ARGS__})
#define umax(...) max({__VA_ARGS__})
#define MAX(v) *max_element(all(v))
#define MIN(v) *min_element(all(v))

typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
const int MOD = 1000000007;
const int INF = 1000000009;
const int MAXN = 1000005;  //300050;

/*debugging */
vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c)) v.emplace_back(x);
	return move(v);
}
template <typename T, typename... Args>
inline string arrStr(T arr, int n) {
	stringstream s;
	s << "[";
	for (int i = 0; i < n - 1; i++) s << arr[i] << ",";
	s << arr[n - 1] << "]";
	return s.str();
}

#ifndef ONLINE_JUDGE
#define debug(args...)                            \
	{                                             \
		__evars_begin(__LINE__);                  \
		__evars(split(#args, ',').begin(), args); \
	}

inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template <typename T>
inline void __evars_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template <typename T>
inline void __evars_out_var(T* val) { cerr << arrStr(val, 10); }
template <typename T>
inline void __evars_out_var(T val) { cerr << val; }
inline void __evars(vector<string>::iterator it) { cerr << endl; }

template <typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
	cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
	__evars_out_var(a);
	cerr << "; ";
	__evars(++it, args...);
}
// #define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif


/* Function to check primality in O(sqrt(n)) */
bool check_prime(ll n) {
	if (n < 2)
		return false;
	for (ll x = 2; x * x <= n; x++) {
		if (n % x == 0)
			return false;
	}
	return true;
}

/* Function to get prime factorization of n in O(sqrt(n))*/
vector<ll> get_prime_factors(ll n) {
	vector<ll> f;
	for (ll x = 2; x * x <= n; x++) {
		while (n % x == 0) {
			f.push_back(x);
			n /= x;
		}
	}
	if (n > 1)
		f.push_back(n);
	return f;
}


ll fpow(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res = (1LL * res * x) % MOD;
		}
		x = (1LL * x * x) % MOD;
		n >>= 1;
	}
	return (res % MOD);
}

vector<ll> fac, inv;
void create_fac(ll n = MAXN) {
	fac.resize(n + 5);
	inv.resize(n + 5);
	fac[0] = 1;
	inv[0] = fpow(fac[0], MOD - 2);
	for (ll i = 1; i <= n; i++) {
		fac[i] = (fac[i - 1] % MOD * i % MOD) % MOD;
		inv[i] = fpow(fac[i], MOD - 2);
	}
}

ll binomial_coefficient(ll n, ll r) {
	ll res = 1;
	res = (res * (fac[n] % MOD)) % MOD;
	res = (res * (inv[r] % MOD)) % MOD;
	res = (res * (inv[n - r] % MOD)) % MOD;
	// res = (res, ) % MOD;
	return res;
}

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a * (b / gcd(a, b));
}

ll sceil(ll a, ll b) {
	return (a + b - 1) / b;
}

vector<ll> lp;
vector<ll> pr;
void sieve(ll n = MAXN) {
	lp.resize(n + 1);
	lp.clear();
	for (ll i = 2; i <= n; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

/* ========== YOUR CODE HERE ========= */

void solution() {
	// ll solution() {
	ll n = 0;
	cin >> n;

	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	ll mx[n], mn[n];
	memset(mx, 0, sizeof(mx));
	memset(mn, 0, sizeof(mn));

	mx[0] = mn[0] = a[0];

	set<ll> s;
	s.insert(a[0]);

	for (ll i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			mx[i] = mn[i] = a[i];
			s.insert(a[i]);
		}
	}

	ll id = 1;

	// for(auto i = s.begin(); i != s.end(); i++)
	// 	cout << *i << ' ';
	// 	cout<<endl;

	for (ll i = 0; i < n; i++) {
		if (!mn[i]) {
			while (id < n && s.find(id) != s.end()) {
				id++;
			}
			mn[i] = id;
			// cout << "ID" << mn[i] << endl;
			id++;
		}
	}

	ll prev = 1;
	// id = -(a[0] - 1);

	s.clear();
	// for (int i = 0; i < n; i++) {
	// 	if (mx[i]) {
	// 		s.insert(-mx[i]);
	// 	}
	// }

	for (ll i = 0; i < n; i++) {
		for (int j = prev; j <= a[i]; j++)
			s.insert(j);

		prev = a[i] + 1;

		mx[i] = *s.rbegin();
		s.erase(*s.rbegin());
	}

	//output
	for (ll i = 0; i < n; i++)
		cout << mn[i] << ' ';
	cout << endl;
	for (ll i = 0; i < n; i++)
		cout << mx[i] << ' ';
	cout << endl;
}

/* ========== YOUR CODE HERE ========= */

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		// cout << solution() << endl;
		solution();
	}

	return 0;
}
