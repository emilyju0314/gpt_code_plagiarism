#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 1200;
const int K_MAX = 15;
vector<int> Prime;
int dp[MAX][K_MAX][200];

void make(){
  int isPrime[MAX];
  memset(isPrime,true,sizeof(isPrime));
  for(int i = 2; i*i < MAX; i++)
    if(isPrime[i]) for(int j = 2; i*j < MAX; j++) isPrime[i*j]=false;

  for(int i = 2; i < MAX; i++)
    if(isPrime[i]) Prime.push_back(i);
}

void solve(){
  memset(dp,0,sizeof(dp));
  dp[0][0][0] = 1;
  
  for(int j = 1; j < K_MAX; j++)
    for(int k = 0; k < (int)Prime.size(); k++)
      for(int i = 0; i < MAX; i++)
	for(int x = 0; x <= k; x++){
	  if(j != 1 && x == k) break;
	  if(i-Prime[k] >= 0) dp[i][j][k] += dp[i-Prime[k]][j-1][x];
	}
}

int main(){
  make();
  solve();
  int n,k;
  while(cin >> n >> k && n+k){
    int sum = 0;
    for(int i = 0; i < 200; i++) sum += dp[n][k][i];
    cout << sum << endl;
  }
  return 0;
}