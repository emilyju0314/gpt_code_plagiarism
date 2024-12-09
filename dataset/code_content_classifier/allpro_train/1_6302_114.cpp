#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int n,m,A[5010],B[5010][210];
ll matrix[5010][5010];int l[5010],r[5010];
int st[5010],tp;
ll sum[5010];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=2;i<=n;i++) {scanf("%d",&A[i]);sum[i]=sum[i-1]+A[i];}
    for (int i=1;i<=n;i++) 
        for (int j=1;j<=m;j++)
            scanf("%d",&B[i][j]);
    for (int j=1;j<=m;j++)
    {
        tp=0;
        for (int i=1;i<=n;i++)
        {
            while (tp&&B[i][j]>B[st[tp]][j]) r[st[tp--]]=i-1;
            st[++tp]=i;
        }
        while (tp) r[st[tp--]]=n;
        tp=0;
        for (int i=n;i;i--)
        {
            while(tp&&B[i][j]>=B[st[tp]][j]) l[st[tp--]]=i+1;
            st[++tp]=i;
        }
        while (tp) l[st[tp--]]=1;
        for (int i=1;i<=n;i++)
        {
            matrix[i+1][r[i]+1]+=B[i][j];
            matrix[l[i]][i]+=B[i][j];
            matrix[l[i]][r[i]+1]-=B[i][j];
            matrix[i+1][i]-=B[i][j];
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            matrix[i][j]+=matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1];
            if (i<=j) ans=max(ans,matrix[i][j]-(sum[j]-sum[i]));
        }
    cout<<ans;
}