#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <fstream>
using namespace std;
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toStr(T x) { ostringstream sout; sout << x; return sout.str();}
typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

int main() {
	int N;
	while(cin >> N, N) {
		vi guyT(N), guyL(N);
		int M, L, S, E;
		REP(i, N) {
			cin >> M >> guyL[i];
			REP(j, M) {
				cin >> S >> E;
				FOR(k, S-6, E-6-1) {
					guyT[i] += (1<<k);
				}
			}
		}

		int ans = 0;
		vi dp(1<<16);
		REP(i, 1<<16) {
			REP(j, N) {
				if((i&guyT[j]) == 0) {
					dp[i|guyT[j]] = max(dp[i|guyT[j]], dp[i]+guyL[j]);
					ans = max(ans, dp[i|guyT[j]]);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}