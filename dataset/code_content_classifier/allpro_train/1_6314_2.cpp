#include <iostream>
#include <queue>
#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <set>
using namespace std;

double dp[1024];

int main(){
  const int n = getInt();
  const int m = getInt();

  dp[0] = 1.0;
  for(int i = 0; i < n; i++){
    for(int j = 1; i + j <= n && j <= m; j++){
      dp[i + j] += dp[i] / (n - i);
    }
  }

  printf("%.10f\n", dp[n]);

  return 0;
}