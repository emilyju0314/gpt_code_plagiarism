#ifdef DEBUG
#include "redirect.h"
#endif

#include<bits/stdc++.h>
#define N 1000
using namespace std;

int f[N][N],g[N][N],n;

int upd(int i,int j) {
    int tmp=f[i][j];
    if (i==0 || i==n+1 || j==0 || j==n+1) return 0;
    f[i][j]=min(f[i][j],f[i-1][j]+g[i-1][j]);
    f[i][j]=min(f[i][j],f[i+1][j]+g[i+1][j]);
    f[i][j]=min(f[i][j],f[i][j-1]+g[i][j-1]);
    f[i][j]=min(f[i][j],f[i][j+1]+g[i][j+1]);
    if (f[i][j]<tmp) return 1; else return 0;
}

void dfs(int i,int j) {
    if (upd(i-1,j)) dfs(i-1,j);
    if (upd(i+1,j)) dfs(i+1,j);
    if (upd(i,j-1)) dfs(i,j-1);
    if (upd(i,j+1)) dfs(i,j+1);
}

int main(int argc, char *argv[]) {
#ifdef DEBUG
    init(argc, argv);
#endif
    register int i,j,k,p,ans=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++) f[i][j]=N,g[i][j]=1;
    for (k=1;k<=n;k++) {
        for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) upd(i,j);
    }

    for (k=1;k<=n*n;k++) {
        scanf("%d",&p); p--;
        i=p/n+1; j=p %n+1;
        ans+=f[i][j];
        g[i][j]=0;
        dfs(i,j);
    }
    printf("%d",ans);
    return 0;
}
