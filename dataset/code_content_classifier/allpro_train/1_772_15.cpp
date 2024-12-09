#include<cstdio>
#include<algorithm>
using namespace std;
int x[1024],y[1024],dp[1024][1024];
int main()
{
    int n,minx=1e9,miny=1e9,ans;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            dp[i][j]=1e9;

    for(int i=1;i<=n;i++)
        dp[i][i]=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j+i<=n;j++)
            for(int k=j;k<j+i;k++)
                dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+y[k]-y[i+j]+x[k+1]-x[j]);

    printf("%d\n",dp[1][n]);
    return 0;
}