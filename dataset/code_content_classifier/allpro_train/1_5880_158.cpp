#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int NUM=110;
const int MAX=2010;
const int INF=0x7ffffff;
int dis[NUM][NUM],p[MAX],t[MAX];
int access[MAX][MAX],vis[MAX],match[MAX];
void init(int n);
bool dfs(int now,int m);
int main()
{
    int n,m,l,u,v,x;
    while(~scanf("%d%d%d",&n,&m,&l)&&n+m+l)
    {
        init(n);
        for (int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&x);
            dis[u][v]=dis[v][u]=x;
        }
        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    if (dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
        for (int i=0; i<l; i++)
            scanf("%d%d",&p[i],&t[i]);
        for (int i=0; i<l; i++)
            for (int j=0; j<l; j++)
                if (i!=j&&t[i]+dis[p[i]][p[j]]<=t[j])
                    access[2*i][2*j+1]=access[2*j+1][2*i]=1;
        int num=0;
        for (int i=0; i<2*l; i++)
        {
            if (match[i]<0)
            {
                memset(vis,0,sizeof vis);
                if (dfs(i,2*l))
                    num++;
            }
        }
        printf("%d\n",l-num);
    }
    return 0;
}
void init(int n)
{
    memset(access,0,sizeof access);
    memset(vis,0,sizeof vis);
    memset(match,-1,sizeof match);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i!=j)
                dis[i][j]=INF;
}
bool dfs(int now,int m)
{
    vis[now]=1;
    for (int i=0; i<m; i++)
    {
        if (access[now][i])
        {
            if (match[i]==-1||!vis[match[i]]&&dfs(match[i],m))
            {
                match[i]=now;
                match[now]=i;
                return true;
            }
        }
    }
    return false;
}

