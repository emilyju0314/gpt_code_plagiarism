#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;
typedef pair<int,int> P;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
P position(char bet){
  if(bet == 'A')return P(0,0);
  else if(bet == 'B')return P(0,1);
  else if(bet == 'C')return P(0,2);
  else if(bet == 'D')return P(1,0);
  else if(bet == 'E')return P(1,1);
  else if(bet == 'F')return P(1,2);
  else if(bet == 'G')return P(2,0);
  else if(bet == 'H')return P(2,1);
  else if(bet == 'I')return P(2,2);
}

int main(){
  int n;
  char sc,tc,bc;
  P s,t,b;  

  while(cin >> n && n){
    double dp[3][3][n+1];
    for(int i=0;i<=n;i++){
      for(int j=0;j<3;j++){
	for(int k=0;k<3;k++){
	  dp[j][k][i] = 0;
	}
      }
    }
    cin >> sc >> tc >> bc;
    s = position(sc);
    t = position(tc);
    b = position(bc);
    dp[s.second][s.first][0] = 1;
    
    for(int k=0;k<n;k++){
      for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	  if(dp[i][j][k] == 0 || (i == b.second && j == b.first))continue;
	  
	  for(int ii=0;ii<4;ii++){
	    int nx = j+dx[ii],ny = i+dy[ii];
	    if(0<=nx && nx <3  && 0<=ny && ny <3 && !(nx == b.first && ny == b.second)){
	      dp[ny][nx][k+1] += dp[i][j][k]*0.25;
	    }
	    else{
	      dp[i][j][k+1] += dp[i][j][k]*0.25;
	    }
	  }

	}
      }
    }

    printf("%.8f\n",dp[t.second][t.first][n]);

  }
  return 0;
}