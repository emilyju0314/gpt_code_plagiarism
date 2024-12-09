#include<bits/stdc++.h>
using namespace std;

void fmin(int&a,int b)
{
    if(b<a)a=b;
}
int s[46][46],dp[46][46][46][46];
char str[46];

inline int read()
{
    register int res=0,flag=1;
    register char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')
        {
            flag=-1;
        }
        ch=getchar();
    }
    while(isdigit(ch))
    {
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar();
    }
    return res*flag;
}

inline int get(register int i,register int j,register int k,register int l)
{
    if(i>k||j>l)return 0;
    return s[k][l]-s[i-1][l]-s[k][j-1]+s[i-1][j-1];
}

int main()
{
    register int n,m,i,j,k,l,x,y,xx,yy,ans;
    n=read();
    m=read();
    for(i=1;i<=n;++i)
    {
        scanf("%s",str+1);
        for(j=1;j<=m;++j)
        {
            if(str[j]=='P')
            {
                xx=i;
                yy=j;
            }
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(str[j]=='#');
        }
    }
    memset(dp,0x3f,sizeof(dp));
    ans=dp[0][0][0][0];
    dp[1][1][n][m]=0;
    for(i=1;i<=xx;++i)
    {
        for(j=1;j<=yy;++j)
        {
            for(k=n;k>=xx;--k)
            {
                for(l=m;l>=yy;--l)
                {
                    fmin(ans,dp[i][j][k][l]+min(min(get(i,j,xx,yy),get(i,yy,xx,l)),min(get(xx,j,k,yy),get(xx,yy,k,l))));
                    for(x=i;x<=k;++x)
                    {
                        for(y=j;y<=l;++y)
                        {
                            if(xx<=x&&yy<=y)fmin(dp[i][j][x][y],dp[i][j][k][l]+get(i,y+1,x,l)+get(x+1,j,k,y));
                            if(xx<=x&&y<=yy)fmin(dp[i][y][x][l],dp[i][j][k][l]+get(i,j,x,y-1)+get(x+1,y,k,l));
                            if(x<=xx&&y<=yy)fmin(dp[x][y][k][l],dp[i][j][k][l]+get(i,y,x-1,l)+get(x,j,k,y-1));
                            if(x<=xx&&yy<=y)fmin(dp[x][j][k][y],dp[i][j][k][l]+get(i,j,x-1,y)+get(x,y+1,k,l));
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}