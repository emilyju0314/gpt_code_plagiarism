#include<cstdio>
#include<cstring>
#include<algorithm>
int n, m;
int c[310];
int dp[310][310];
int solve(int di, int sum, int x[]){
  if(di == n) return 0;
  if(dp[di][sum] != -1) return dp[di][sum];
  int a = 0;
  for(int i = 0;i * c[di] + sum <= m; i++) a = std::max(a, solve(di + 1, sum + i * c[di], x) + i * x[di]);
  return dp[di][sum] = a;
}
void foo(int v[], int d[], int l[]){
  int ans = 0;
  memset(dp, -1, sizeof(dp));
  ans = std::max(ans, solve(0, 0, v));
  memset(dp, -1, sizeof(dp));
  ans = std::max(ans, solve(0, 0, d));
  memset(dp, -1, sizeof(dp));
  ans = std::max(ans, solve(0, 0, l));
  printf("%d\n",ans);
}
int main(void){
  char s[50];
  int v[310],d[310],l[310];
  while(scanf("%d %d",&n,&m) != EOF){
    for(int i = 0;i < n; i++){
      fgets(s, sizeof(s), stdin); fgets(s, sizeof(s), stdin);
      scanf("%d %d %d %d",&c[i],&v[i],&d[i],&l[i]);
    }
    foo(v, d, l);
  }
}
