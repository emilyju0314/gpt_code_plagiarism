#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int N;
int pos[2][2020];
int L[2][2020][2020];
int dp[2020][2020];

int main() {
    string s;
    int x;
    cin >> N;
    rep(i,2*N) {
		cin>>s>>x;
		pos[s=="W"][x-1]=i;
	}
    rep(i,2) {
		rep(x,N) {
			for(int y=x+1;y<N;y++) if(pos[i][y]<pos[i][x]) L[i][x][N]++;
			for(int y=N-1;y>=0;y--) L[i][x][y]=L[i][x][y+1]+(pos[i^1][y]<pos[i][x]);
		}
	}
    rep(x,N+2) rep(y,N+2) dp[x][y]=1<<25;
    dp[0][0] = 0;
    rep(x,N+1) rep(y,N+1) {
		if(x<N) chmin(dp[x+1][y],dp[x][y]+L[0][x][y]);
		if(y<N) chmin(dp[x][y+1],dp[x][y]+L[1][y][x]);
	}
    cout << dp[N][N] << endl;
    return 0;
}