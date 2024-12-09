#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <random>
#include <cstring>
using namespace std;

//#pragma comment(linker, "/stack:36777216")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
}

bool isPrime(int x) {
	if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
	for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
}

typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define fori(n) for(int i = 0; i < (n); ++i)
#define forj(n) for(int j = 0; j < (n); ++j)
#define fork(n) for(int k = 0; k < (n); ++k)
#define forx(n) for(int x = 0; x < (n); ++x)


#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_p(x) cerr << #x << " " << x.ff << " " << x.ss << endl;
#define debug_v(x) cerr << #x << " "; for (auto ii : x) cout << i << " "; cout << endl;
#define debug_vp(x) cerr << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
#define mp make_pair
#define rand kjsdflsdfsdlsjdlkfsdjflsjdfl 

#define Return cerr<<endl<<"RUNTIME: "<<1.0*clock()/CLOCKS_PER_SEC << " s" <<endl; return 0;

#define PI 3.14159265

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}

/////////////////////
#define int long long
int Mod = 1e9 + 7;
#define endl '\n'
/////////////////////

//int inf = 1e18;

int32_t main() {
	boostIO();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);



	int n, m, k; cin >> n >> m >> k;
	int sum = 0;

	vector<int> N(n);
	vector<int> M(m);
	vector<int> K(k);

	int nsum = 0;
	fori(n) {
		int x; cin >> x;
		sum += x;

		N[i] = x;
		nsum += x;
	}
	int msum = 0;
	fori(m) {
		int x; cin >> x;
		sum += x;

		M[i] = x;
		msum += x;
	}

	int ksum = 0;
	fori(k) {
		int x; cin >> x;
		sum += x;

		K[i] = x;
		ksum += x;
	}

	sort(all(N));
	sort(all(M));
	sort(all(K));

	int ans = -4e18;

	ans = max(ans, sum - 2 * (N[0] + M[0]));
	ans = max(ans, sum - 2 * (N[0] + K[0]));
	ans = max(ans, sum - 2 * (M[0] + K[0]));

	ans = max(ans, sum - 2 * nsum);
	ans = max(ans, sum - 2 * msum);
	ans = max(ans, sum - 2 * ksum);




	cerr << "ans = ";
	cout << ans << endl;
}