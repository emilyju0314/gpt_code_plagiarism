#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, int> plp;
const ll INF = 1e9+100;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
const bool debug = 0;
//--------------------------------//

int N;
int c[100];
bool dp[100][101];

int main() {
	cin >> N;
	REP(i, N) scanf("%d", c + i);
	
	REP(i, N - 1) if (c[i] == c[i + 1]) dp[i][i + 2] = true;
	
	FOR(s, 2, N + 1) {
		REP(l, N - s + 1) {
			int r = l + s;
			
			FOR(k, l + 1, r) {
				dp[l][r] |= dp[l][k] & dp[k][r]; // xx
				
				if (c[l] == c[r - 1]) {
					dp[l][r] |= dp[l + 1][r - 1]; // 1x1
					if (c[l] == c[k]) dp[l][r] |= dp[l + 1][k] & dp[k + 1][r - 1]; // 1x1x1
				}
			}
			
			if (c[l] && c[r - 1]) {
				if (l > 0 && c[l - 1] == c[l]) dp[l - 1][r] |= dp[l][r];
				if (r < N && c[r - 1] == c[r]) dp[l][r + 1] |= dp[l][r];
			}
		}
	}
	
	puts(dp[0][N] ? "yes" : "no");
	return 0;
}