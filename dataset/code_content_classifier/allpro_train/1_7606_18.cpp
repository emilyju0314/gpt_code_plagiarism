#include<bits/stdc++.h>
using namespace std;
/*
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using pq = priority_queue<int>;
template<class T>
using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
*/
typedef vector<int> V;
typedef vector<vector<int> > VV;
#define rep(i,n) for(int i=0;i<(n);i++)
/*
int under = (1 << 31);
int upper = under - 1;
ll UNDER = (1LL << 63);
ll UPPER = UNDER - 1;
*/
const int MOD = 1e9 + 7;
const long double pi = 3.141592653589793;
void add(int& a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
int main() {
	string s, t;
	cin >> s >> t;
	int x = s.size();
	int y = t.size();
	VV dp(x + 2, V(y + 2, 0));
	dp[0][0] = 1;
	rep(i, x) rep(j, y + 1) {
		add(dp[i + 1][j], dp[i][j]);
		if (s[i] == t[j]) add(dp[i + 1][j + 1], dp[i][j]);
	}
	cout << dp[x][y] << endl;
	return 0;
}
