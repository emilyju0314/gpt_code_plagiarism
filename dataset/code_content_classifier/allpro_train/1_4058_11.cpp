#include<bits/stdc++.h>
using namespace std;
int k,a,b,day[101],n, memo[101][4][4];
int dfs(int j,int d1,int d2);
int main(){
  cin >> n >> k;
  fill(day,day+101,0);
  memset(memo,-1,sizeof(memo));
  for(int i=0;i<k;i++){
    cin >> a >> b;
    day[a] = b;
  }
  cout << dfs(1,0,0) << endl;
  return (0);
}

int dfs(int j,int d1,int d2){
  int ret = 0;
  if(j == n+1) return 1;
  if(memo[j][d1][d2] != -1) return memo[j][d1][d2];
  else if(day[j] != 0){
    if(d1!=d2||d2!=day[j]) ret += dfs(j+1,d2,day[j]);
  }
  else {
    for(int i=1;i<=3;i++){
      if(d1!=d2||d2!=i) ret += dfs(j+1,d2,i);
    }
  }
  return memo[j][d1][d2] = ret%10000;
}