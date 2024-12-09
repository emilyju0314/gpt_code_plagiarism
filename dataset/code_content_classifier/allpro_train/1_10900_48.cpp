#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define range(x,l,r) (l<=x && x<r)
#define chmax(a,b) (a = max(a,b))
using namespace std;

const int dy[] = {0,1,0,-1}, dx[] = {1,0,-1,0};
int dp[50][50][4][1<<12];
int vis[1<<12];

inline int visit(int bit){
  if(vis[bit]>=0)return vis[bit];

  int y=0, x=0, b=bit;
  rep(i,6){
    y += dy[b&3], x += dx[b&3]; b>>=2;
    if(y==0 && x==0)return vis[bit] = 1;
  }
  return vis[bit] = 0;
}

int main(){
  int h,w,k;
  string g[50];
  cin >> h >> w >> k;
  rep(i,h)cin >> g[i];

  memset(vis,-1,sizeof(vis));
  memset(dp,-1,sizeof(dp));
  dp[0][0][0][0] = isdigit(g[0][0])?(int)(g[0][0]-'0'):0;

  rep(rev,k+1){
    rep(y,h)rep(x,w){
      if(g[y][x] == '#')continue;
      rep(bit,1<<12){
	if(dp[y][x][rev][bit]<0)continue;

	rep(d,4){
	  if(rev==k && d>1)break;
	  int ny = y+dy[d], nx = x+dx[d];
	  if(!range(ny,0,h) || !range(nx,0,w))continue;
	  if(g[ny][nx] == '#')continue;

	  int nbit = ((bit<<2)|d) & ((1<<12)-1);
	  int item = isdigit(g[ny][nx])?(int)(g[ny][nx]-'0'):0;
	  if(visit(nbit))item = 0;

	  if(d<2){
	    chmax(dp[ny][nx][rev][nbit], dp[y][x][rev][bit] + item);
	  }else{
	    chmax(dp[ny][nx][rev+1][nbit], dp[y][x][rev][bit] + item);
	  }
	}
      }
    }
  }

  int res = 0;
  rep(bit,1<<12)chmax(res, dp[h-1][w-1][k][bit]);
  cout << res << endl;
}