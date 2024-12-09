#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
struct node{
    int to,nxt;
}sq[200200];
int all=0,head[100100];

int n,m,pre[100100],siz[100100],root=0,maxson[100100],now,tax[2][100100],
    sum=0,nowlen[2][100100],tot1=0,tot0=0,maxsiz,val[100100];
bool vis[100100];
char s[100100];
ll ans=0;
vector<int> sav;

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

void add(int u,int v)
{
    all++;sq[all].to=v;sq[all].nxt=head[u];head[u]=all;
}

void findrt(int u,int fu)
{
    int i;siz[u]=1;maxson[u]=0;
    for (i=head[u];i;i=sq[i].nxt)
    {
        int v=sq[i].to;
        if ((v==fu) || (vis[v])) continue;
        findrt(v,u);siz[u]+=siz[v];
        maxson[u]=max(maxson[u],siz[v]);
    }
    maxson[u]=max(maxson[u],now-siz[u]);
    if (maxson[u]<maxsiz) {root=u;maxsiz=maxson[u];}
}

bool insert(int u,int fu,int val)
{
    sum+=val;
    pre[u]=min(pre[fu],val-sum);
    return pre[u]+sum>=0;
}

void getdis(int u,int fu,int op)
{
    int nowv;
    if (op) nowv=val[u];else nowv=-val[u];
    if (insert(u,fu,nowv))
    {
        if (op) nowlen[1][++tot1]=sum;else nowlen[0][++tot0]=sum;
        sav.pb(sum);
    }
    int i;
    for (i=head[u];i;i=sq[i].nxt)
    {
        int v=sq[i].to;
        if ((vis[v]) || (v==fu)) continue;
        getdis(v,u,op);
    }
    sum-=nowv;
}

void calc(int u)
{
    tax[0][0]=tax[1][0]=1;int i;
    for (i=head[u];i;i=sq[i].nxt)
    {
        int v=sq[i].to;
        if (vis[v]) continue;
        tot0=0;tot1=0;
        sum=0;pre[u]=0;getdis(v,u,1);
        sum=0;pre[u]=0;getdis(v,u,0);
        rep(j,1,tot1)
            ans+=tax[0][nowlen[1][j]+val[u]];
        rep(j,1,tot0)
            ans+=tax[1][nowlen[0][j]-val[u]];
        rep(j,1,tot0) tax[0][nowlen[0][j]]++;
        rep(j,1,tot1) tax[1][nowlen[1][j]]++;
    }
    rep(i,0,(int)sav.size()-1) tax[0][sav[i]]=tax[1][sav[i]]=0;sav.clear();
}

void divide(int u)
{
    vis[u]=1;calc(u);int i;
    for (i=head[u];i;i=sq[i].nxt)
    {
        int v=sq[i].to;
        if (vis[v]) continue;
        maxsiz=maxd;now=siz[v];
        findrt(v,u);divide(root);
    }
}

int main()
{
    n=read();scanf("%s",s+1);
    rep(i,1,n)
        if (s[i]=='(') val[i]=1;else val[i]=-1;
    rep(i,1,n-1)
    {
        int u=read(),v=read();
        add(u,v);add(v,u);
    }
    maxsiz=maxd;now=n;
    findrt(1,0);divide(root);
    printf("%lld\n",ans);
    return 0;
}
