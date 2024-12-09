#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

const int N = 1001;


int compute(int x,int y,int n){
  double z = sqrt(n-(double)x*x-(double)y*y);
  if (isnan(z))return 0;
  if ( fabs(z-(n-(double)x*x-(double)y*y))<1e-10)return (int)z;
  else return (int)ceil(z);
}

int height[N][N];
int th[N+1][N+1];

void estimate(int n,int tn){
  rep(i,tn)rep(j,tn)height[i][j]=0;
  rep(y,tn+1){
    rep(x,tn+1)th[y][x]=compute(x,y,n);
  }
  rep(y,tn){
    rep(x,tn){
      int p=0;
      height[y][x]=max(max(th[y][x],th[y+1][x]),
		       max(th[y+1][x],th[y+1][x+1]));
    }
  }
}

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int n,int y,int x,int d,bool &xzero,bool &yzero){
  if (y==-1||x==-1||y==n||x==n||height[y][x] != d)return;
  height[y][x]=0;
  if(x==0)xzero=true;
  if(y==0)yzero=true;
  rep(i,4)dfs(n,y+dy[i],x+dx[i],d,xzero,yzero);
}

int solve(int n){
  int ret=0;
  rep(i,n){
    rep(j,n){
      if (height[i][j] != 0){
	bool xzero=false,yzero=false;
	int tmp=1;
	dfs(n,i,j,height[i][j],xzero,yzero);
	if (xzero&&yzero);
	else if (xzero||yzero)tmp*=2;
	else tmp*=4;
	ret+=tmp;
      }
    }
  }
  return ret*6;
}

int main(){
  int n;
  while(cin>>n && n){
    int tn = (int)(ceil(sqrt(n)));
    estimate(n,tn);
    cout << solve(tn) << endl;
  }
  return false;
}