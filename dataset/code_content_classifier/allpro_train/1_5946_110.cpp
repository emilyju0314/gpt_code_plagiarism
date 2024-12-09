#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=500010;
int tree[N];
int a[N],last[N];
int ans[N];
int n,m;
struct node
{
    int l,r,k;
    bool operator <(const node& o)const
    {
        return r<o.r;
    }
}q[N];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int c)
{
    for(;x<=n;x+=lowbit(x)) tree[x]+=c;
}
int sum(int x)
{
    int res=0;
    for(;x;x-=lowbit(x)) res+=tree[x];
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        q[i]={l,r,i};
    }
    sort(q,q+m);
    int k=1;
    for(int i=0;i<m;i++)
    {
        for(;k<=q[i].r;k++)
        {
            int x=a[k];
            if(last[x]) add(last[x],-1);
            add(k,1);
            last[x]=k;
        }
        ans[q[i].k]=sum(q[i].r)-sum(q[i].l-1);
    }
    for(int i=0;i<m;i++) printf("%lld\n",ans[i]);
    return 0;
}
