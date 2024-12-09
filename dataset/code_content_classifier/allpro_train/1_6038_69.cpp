#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=305;
int n,cnt[4];
double dp[N][N][N];
bool vis[N][N][N];
double dfs(int i,int j,int k){
	if(i==0&&j==0&&k==0) return 0;
	if(vis[i][j][k]) return dp[i][j][k];
	vis[i][j][k]=1;
	if(k!=0) dp[i][j][k]+=(k*1.0*dfs(i,j+1,k-1)/n);
	if(j!=0) dp[i][j][k]+=(j*1.0*dfs(i+1,j-1,k)/n);
	if(i!=0) dp[i][j][k]+=(i*1.0*dfs(i-1,j,k)/n);
	dp[i][j][k]++;
	dp[i][j][k]/=1.0*(i+j+k)/n;
	return dp[i][j][k];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {int x;scanf("%d",&x);cnt[x]++;}
	printf("%.14lf\n",dfs(cnt[1],cnt[2],cnt[3]));
	
}