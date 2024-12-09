#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
#define LL double
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sqr(x) (x)*(x)
const int MAX=1005;
const LL inf=1e30;
struct node
{
    int u,v;
    LL w;
}g[MAX*MAX];
int e,ans;
int vis[MAX],id[MAX],pre[MAX];
LL in[MAX],sum,res,gg[105][105];
void add(int u,int v,LL w)
{
    g[e].u=u; g[e].v=v; g[e++].w=w;
    //cout<<u<<"->"<<v<<" "<<w<<endl;
    gg[u][v]=w;
}
double ZL(int root,int n)
{
    int i,j,k,u,v,vn;
    res=0;
    while(1)
    {
        for(i=0;i<n;i++)
            in[i]=inf;
        for(i=0;i<e;i++)
        {
            u=g[i].u; v=g[i].v;
            if(g[i].w<in[v]&&u!=v)
            {
                pre[v]=u;
                in[v]=g[i].w;
            }
        }
        for(i=0;i<n;i++)
        {
            if(i!=root&&in[i]==inf)
                return false;
        }
        vn=0;
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        in[root]=0;
        for(i=0;i<n;i++)
        {
            res+=in[i];
            v=i;
            while(vis[v]!=i&&id[v]==-1&&v!=root)
            {
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root&&id[v]==-1)
            {
                for(u=pre[v];u!=v;u=pre[u])
                {
                    id[u]=vn;
                }
                id[v]=vn++;
            }
        }
        if(vn==0)
            break;
        for(i=0;i<n;i++)
        {
            if(id[i]==-1)
                id[i]=vn++;
        }
        for(i=0;i<e;i++)
        {
            v=g[i].v;
            g[i].u=id[g[i].u];
            g[i].v=id[g[i].v];
            if(g[i].u!=g[i].v)
            {
                g[i].w-=in[v];
            }
        }
        n=vn;
        root=id[root];
    }
    return res;
}
double a[105][105],len[105];
int main()
{
    int n,m,i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        e=0;
        rep (i, m) {
            len[i] = 0;
            rep (j, n) {
                scanf ("%lf", &a[i][j]);
                len[i] += a[i][j] * a[i][j];
            }
            len[i] = sqrt(len[i]);
        }
        rep (i, m) {
            rep (j, m) {
                if (i == j) continue;
                double now = 0.0;
                rep (k, n) {
                    now += a[i][k] * a[j][k];
                }
                now /= len[i] * len[j];
                now = sqrt (1.0 - now * now);
                gg[j + 1][i + 1] = sqr(len[i] * now);
                add(j+1,i+1,gg[j+1][i+1]);
            }
            gg[0][i + 1] = sqr(len[i]);
            add(0,i+1,gg[0][i+1]);
            //gg[i + 1][0] = -1;
            //gg[i + 1][i + 1] = -1;
        }
        //for(int i=0;i<=m;i++)
            //for(int j=0;j<=m;j++)
                //printf("%d->%d %lf\n",i,j,gg[i][j]);
        printf("%.8f\n",ZL(0,m+1));
    }
    return 0;
}