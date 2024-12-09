#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long int ll;

const int MAX_N = 1010;
const ll INF = (1LL << 60);
ll S[MAX_N];
ll L[MAX_N];
ll dp[MAX_N][MAX_N];
int N,W;

void input(){
  for(int i = 0 ; i < N ; i++){
    cin >> L[i];
  }
  S[0] = L[0];
  for(int i = 1 ; i < N ; i++){
    S[i] = S[i-1] + L[i];
  }
}

ll getCost(int i,int j){
  return S[i] - S[j] + L[j];
}

void solve(){
  input();
  for(int i = 0 ; i <= N ; i++ ){
    for(int j = 0 ; j <= N ; j++){
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;

  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j <= i ; j++){
      dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
      dp[i+1][i+1] = min(dp[i+1][i+1],dp[i][j] + labs(getCost(i,j) - W));
    }
  }
  
  ll res = INF;

  for(int i = 0 ; i < N ; i++){
    res = min(res,dp[N][i] + max(0LL,getCost(N-1,i)-W));
  }
  cout << res << endl;
}

int main(){
  int cnt = 1;
  while(cin >> N >> W,N || W){
    cout << "Case " << cnt++ << ": ";
    solve();
  }
  return 0;
}