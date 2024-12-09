#include<bits/stdc++.h>
using namespace std;

const int maxn=3005;
const int inf=1e6;
int dp[maxn][maxn],a[maxn];

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n+1;i++)dp[1][i]=0;
	for(int i=2;i<=n+1;i++){
		for(int j=i;j<=n+1;j++)dp[i][j]=inf;
		int cnt=0;
		for(int j=i-1;j;j--){
			if(a[j]+j>=i){
				dp[i][j+a[j]]=min(dp[i][a[j]+j],dp[j][i-1]+cnt);
				cnt++;
			}
		}
		for(int j=i;j<=n;j++)dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
	}
		printf("%d\n",dp[n][n]);
	}
	return 0;
}
