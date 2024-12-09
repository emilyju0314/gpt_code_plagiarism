#include<iostream>
#include<algorithm>

using namespace std;

#define MOD 1000000007
#define M 108
typedef long long Int;

int a, b, c, d, e;
Int dp[108][21600];
Int dp1[108][21600];
Int dp2[108][21600];
int main(){
  cin >> a >> b >> c >> d >> e;
  b -= a;
  e -= a*d;
  dp[0][0] = 1;
  dp1[0][0] = 1;
  dp2[0][0] = 1;
  for(int i = 0;i <= d;i++){
    for(int j = 0;j < 21500;j++){
      if(i == 0 && j == 0)continue;
      dp[i%M][j] = 0;    
      int l = max(0, i - j);
      int r = min(c, i);
	  if(l <= r){
	      if(i-l>=0 && j - (i-l) >= 0)dp[i%M][j] += dp1[(i-l)%M][j-(i-l)];
	      if(i-(r+1) >= 0 && j-(i-(r+1)) >= 0)dp[i%M][j] -= dp1[(i-(r+1))%M][j-(i-(r+1))];
	  }
/*      for(int k = l;k <= r;k++){
	dp[i][j] += dp[i-k][j-(i-k)];
	} */
      l = 1;
      r = min(c, i);
      r = min(r, j / (b+1));
      if(l <= r){
	      if(i-l >= 0 && j-(b+1)*l >= 0)dp[i%M][j] -= dp2[(i-l)%M][j-(b+1)*l];
	      if(i-(r+1) >= 0 && j-(b+1)*(r+1) >= 0)dp[i%M][j] += dp2[(i-(r+1))%M][j-(b+1)*(r+1)];
	  }
/*      for(int k = l;k <= r;k++){
	dp[i][j] -= dp[i-k][j-(b+1)*k];
	}*/
      dp[i%M][j] %= MOD;
      if(dp[i%M][j] < 0)dp[i%M][j] += MOD;
      dp1[i%M][j] = dp2[i%M][j] = dp[i%M][j];
      if(i)(dp1[i%M][j] += dp1[(i-1)%M][j+1])%=MOD;
      if(i && j-(b+1)>=0)(dp2[i%M][j] += dp2[(i-1)%M][j-(b+1)])%=MOD;
    }
  }
  cout << dp[d%M][e] << endl;
  return 0;
}
