#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define all(v) (v).begin(), (v).end()
#define rev(s) (s).rbegin(), (s).rend()
#define MP make_pair
#define X first
#define Y second
#define debug(x) cout << #x << " = " << x << endl;
#define sq(x) ((x)*(x))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;

int Lcost[205][205];
int Scost[205][205];

int dp[1005][205];

int main(){
	int n, m;
	while(cin >> n >> m, n|m){
		static const int INF = 1e8;
		rep(i, n) rep(j, n){
			if(i == j) continue;
			Lcost[i][j] = INF;
			Scost[i][j] = INF;
		}
		rep(i, m){
			int x, y, t;
			char sl;
			cin >> x >> y >> t >> sl;
			x--, y--;
			if(sl == 'L'){
				Lcost[x][y] = Lcost[y][x] = t;
			}else{
				Scost[x][y] = Scost[y][x] = t;
			}
		}
		rep(i, n) rep(j, n) rep(k, n){
			Lcost[j][k] = min(Lcost[j][k], Lcost[j][i] + Lcost[i][k]);
			Scost[j][k] = min(Scost[j][k], Scost[j][i] + Scost[i][k]);
		}

		int r;
		cin >> r;
		vector<int> z(r);
		rep(i, r){
			cin >> z[i];
			z[i]--;
		}

		rep(i, r) rep(j, n) dp[i][j] = INF;
		dp[0][z[0]] = 0;
		for(int i = 1; i < r; i++){
			int pos = z[i-1];
			int next = z[i];
			rep(j, n){
				dp[i][j] = min(dp[i][j], dp[i-1][j]+Lcost[pos][next]);
				rep(k, n){
					dp[i][k] = min(dp[i][k], dp[i-1][j]+Lcost[pos][j]+Scost[j][k]+Lcost[k][next]);
				}
			}
		}
		int ans = INF;
		rep(i, n) ans = min(ans, dp[r-1][i]);
		cout << ans << endl;
	}

    return 0;
}