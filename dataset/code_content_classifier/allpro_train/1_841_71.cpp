//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include <array>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

typedef long long int LL;
//typedef __int128 LLL;
typedef long long LLL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PLL> VPL;
typedef vector<PII> VP;
typedef vector<double> VD;
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
typedef long double ld;

#define MAXN 5000
//#define MAXN 1006

const LL MOD = 1000000007;
//const LL MOD = 998244353;
const LL INF = 2000000000000000001LL; //2e18 + 1

LL dp[5005][5005];
LL sdp[5005][5005];
LL p2[5005], invp2[5005];

LL bigmod(LL a, LL b) {
	if (b == 0) return 1;
	LL x = bigmod(a, b / 2);
	x = (x * x) % MOD;
	if (b & 1) x = (x * a) % MOD;
	return x;
}

void solve(int ks) {
	p2[0] = 1;
	invp2[0] = 1;
	LL inv = bigmod(2, MOD - 2);
	for (int i = 1; i <= MAXN + 2; i++) {
		p2[i] = (2 * p2[i - 1]) % MOD;
		invp2[i] = (inv * invp2[i - 1]) % MOD;
	}
	for (int i = 0; i <= MAXN; i++) {
		for (int j = 0; j <= MAXN; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 1;
				if (i) sdp[i][j] = sdp[i - 1][j];
				sdp[i][j] = (sdp[i][j] + ((invp2[i + 1] * i) % MOD) * dp[i][j]) % MOD;
				continue;
			}

			// 0*1*
			dp[i][j] = (dp[i][j] + dp[i][j - 1] * (i + 1)) % MOD;
			// 0*1(anything)01*.
			dp[i][j] = (dp[i][j] + p2[i] * (sdp[i - 1][j - 1] - sdp[0][j - 1] + MOD)) % MOD;
			if (i) sdp[i][j] = sdp[i - 1][j];
			sdp[i][j] = (sdp[i][j] + ((invp2[i + 1] * i) % MOD) * dp[i][j]) % MOD;
			//for (int x = 0; x <= i - 2; x++) {
			//	dp[i][j] = (dp[i][j] + ((p2[i - x - 2] * (x + 1)) % MOD) * dp[x + 1][j - 1]) % MOD;
			//}
		}
	}

	int n, m;
	scanf("%d %d", &n, &m);
	printf("%lld\n", dp[m][n]);
}

void gen() {
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	// freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	gen();

	if (0) {
		int T;
		scanf("%d", &T);
		//AIN(T, 1, 5000);
		for (int ks = 1; ks <= T; ks++) {
			solve(ks);
			if (ks % 1 == 0) fprintf(stderr, "%d done\n", ks);
		}
	}
	else {
		solve(0);
	}

	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

	return 0;
}
