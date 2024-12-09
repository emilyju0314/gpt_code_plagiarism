#include<bits/stdc++.h>
using namespace std;

int M,N;
string S[130];

int dp[(1<<11)][(1<<11)];


bool check(int st,int fr){
  int mem[130]={};
  int n = __builtin_popcount(st);
  for(int i=0;i<M;i++){
    if( st & (1<<i) ) {
      for(int j=0;j<N;j++){
	if( S[j][i] == '0' && !(fr & (1<<i)) ){
	  mem[j]++;
	} else if( S[j][i] == '1' && (fr & (1<<i) ) ) {
	  mem[j]++;
	}
      }
    }
  }
  int cnt=0;
  for(int j=0;j<N;j++){
    if( mem[j] == n ) cnt++;
  }
  if( cnt == 1 ) return true;
  return false;
}

int solve(int st,int fr){
  if( dp[st][fr] != -1 ) return dp[st][fr];
  if( st>0 && check(st,fr) ) return dp[st][fr] = 0;
  if( st == (1<<M) - 1 ) return dp[st][fr] = 0;
  int ret = 100000;
  for(int i=0;i<M;i++){
    if( (st&(1<<i)) ) continue;
    ret = min( ret,
	       max( solve(st|(1<<i),fr|(1<<i))+1,
		    solve(st|(1<<i),fr)+1 ) );
  }
  return dp[st][fr] = ret;
}

int main() {
  while( cin >> M >> N && ( M||N ) ){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++) cin >> S[i];
    if( N == 1) cout << 0 << endl;
    else cout << solve( 0, 0 ) << endl;
  }
}