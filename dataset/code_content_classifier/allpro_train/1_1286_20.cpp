#include<bits/stdc++.h>
using namespace std;
int n,m,f[100001];
long long cot[100001];
long long ans[100001];
struct node
{
    int x,y;
}a[100001];
int getf(int x)
{
    return f[x]==x?x:f[x]=getf(f[x]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) f[i]=i,cot[i]=1,ans[m]+=i;
    ans[m]-=n;
    for(int i=1;i<=m;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    long long t=ans[m];
    for(int i=m;i>1;i--)
    {
        int fx=getf(a[i].x),fy=getf(a[i].y);
        if(fx!=fy) t-=cot[fx]*cot[fy],cot[fx]+=cot[fy],f[fy]=f[fx];
        ans[i-1]=t;
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
}
