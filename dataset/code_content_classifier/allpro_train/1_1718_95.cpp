#include<iostream>
#include<vector>
#define rep(i,a) for(int i = 0 ; i < a ; i++)
using namespace std;

int main(void){
  int n,m;
  while(cin>>n>>m,n+m){
    vector<vector<vector<int> > > dp(2,vector<vector<int> >(100,vector<int>(100,1<<22)));
    rep(i,n){
      int a,b,c,t;
      cin>> a >> b >> c >> t;
      dp[0][--a][--b] = c;
      dp[0][b][a] = c;
      dp[1][a][b] = t;
      dp[1][b][a] = t;
    }
    
    rep(k,m)rep(i,m)rep(j,m)rep(o,2)
      dp[o][i][j] = min(dp[o][i][j],dp[o][i][k]+dp[o][k][j]);
      
    int k;
    cin>>k;
    rep(i,k){
      int p,q,r;
      cin >> p >> q >> r;
      cout<< dp[r][--p][--q] << endl;
    }
  }
}