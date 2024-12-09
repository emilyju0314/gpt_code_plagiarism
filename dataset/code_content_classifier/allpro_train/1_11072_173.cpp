#include <cstdio>
#include <cstring>
int dp[50][3001];
int main() {
	int n,m,s;
	while(scanf("%d %d %d",&n,&m,&s),n) {
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=m;i++)
			for(int j=n*n;j>=1;j--)
				for(int k=i;k<=s;k++) {
					dp[j][k]+=dp[j-1][k-i];
					if(dp[j][k]>=100000)dp[j][k]-=100000;
				}
		printf("%d\n",dp[n*n][s]);
	}
}