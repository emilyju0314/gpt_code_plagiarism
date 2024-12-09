#include <bits/stdc++.h>
using namespace std;

#define rep2(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) rep2(i,0,n)

const int INF = 1070000000;

int n,m,k,p;
int dist[1<<10][1<<10];
int pick[7], send[7];
int dp[1<<10][1<<6][1<<6];

int f(int cur,int mask1,int mask2){
	int& res = dp[cur][mask1][mask2];
	if(res != -1) return res;
	if(mask2 == (1<<k)-1) return res = 0;
	res = INF;
	// pick
	rep(i,k)if((mask1>>i&1) == 0){
		res = min(res, dist[cur][pick[i]] + f(pick[i], mask1 | 1<<i, mask2));
	}
	// send
	rep(i,k)if((mask2>>i&1) == 0 && (mask1>>i&1) == 1){
		res = min(res, dist[cur][send[i]] + f(send[i], mask1, mask2 | 1<<i));
	}
	//cout<<cur<<" "<<mask1<<" "<<mask2<<" : "<<res<<endl;
	return res;
}

int main(){
	cin>>n>>m>>k>>p; p--;
	rep(i,n)rep(j,n)dist[i][j] = i==j ? 0 : INF;
	rep(i,m){
		int x,y,w;
		cin>>x>>y>>w;
		x--; y--;
		dist[x][y] = dist[y][x] = w;
	}
	rep(K,n)rep(i,n)rep(j,n)dist[i][j] = min(dist[i][j], dist[i][K] + dist[K][j]);
	//rep(i,n)rep(j,n)cout<<dist[i][j]<<(j==n-1 ? "\n":" ");
	rep(i,k){
		cin>>pick[i]>>send[i];
		pick[i]--; send[i]--;
	}
	memset(dp,-1,sizeof(dp));
	int ans = f(p, 0, 0);
	if(ans >= INF) cout<<"Cannot deliver"<<endl;
	else cout<<ans<<endl;
}