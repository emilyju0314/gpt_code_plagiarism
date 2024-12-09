#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb         push_back

const int N = 300;
const double inf = 1000;
const double eps=1e-10;

double cost[N][N];
double dp[N][N];

double le(vector<double> &tmp,double tar){
  int l=0,r=tmp.size()-1;
  double ret=-inf;
  while(l <= r){
    int mid=(l+r)/2;
    if (fabs(tmp[mid]-tar)<eps)return tmp[mid];
    else if (tmp[mid] > tar)r=mid-1;
    else l=mid+1,ret=tmp[mid];
  }
  return ret;
}

double ge(vector<double> &tmp,double tar){
  int l=0,r=tmp.size()-1;
  double ret=inf;
  while(l <= r){
    int mid=(l+r)/2;
    if (fabs(tmp[mid]-tar)<eps)return tmp[mid];
    else if (tmp[mid] > tar)r=mid-1,ret=tmp[mid];
    else l=mid+1;
  }
  return ret;
}

void pre(int n,double *in,double div,int L){
  rep(i,n){
    REP(j,i+1,n){
      double maxi=0;
      double mini=10000000;
      cost[i][j]=0;
      for(int k=i;k<=j;k++){
	mini=min(mini,in[k]);
	maxi=max(maxi,in[k]);
      }
      double tmp=(maxi-mini)/div;
      vector<double> hoge;
      REP(k,1,(1<<L)+1){
	hoge.pb(mini+(k-1)*tmp);
      }
      sort(hoge.begin(),hoge.end());
      for(int k=i;k<=j;k++){
	double a=le(hoge,in[k]);
	double b=ge(hoge,in[k]);
	a=(a-in[k])*(a-in[k]);
	b=(b-in[k])*(b-in[k]);
	cost[i][j]+=min(a,b);
      }
    }
  }
}

double solve(int n,int M){
  rep(i,n+1){
    rep(j,M+1)dp[i][j]=inf;
  }
  dp[0][0]=0;
  REP(i,2,n+1){
    REP(j,1,M+1){
      rep(k,i-1){
	dp[i][j]=min(dp[i][j],dp[k][j-1]+cost[k][i-1]);
      }
    }
  }
  return dp[n][M];
}

int main(){
  //test();
  int n,M,L;
  double in[N];
  while(cin>>n>>M>>L && n){
    rep(i,n)cin>>in[i];
    pre(n,in,(1<<L)-1,L);
    printf("%.7lf\n",solve(n,M));
  }
  return false;
}