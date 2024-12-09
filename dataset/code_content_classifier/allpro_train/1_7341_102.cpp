#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int x[N],a[N][N],b[N][N],f[N],p[N],r,n,m,ans;
char c[N][N];
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%s",c[i]+1);
        for (int j=1;j<=m;j++) {
            b[i][j] = c[i][j]=='#'?1:0;
        }
    }
    for (int i=1;i<n;i++) 
        for (int j=1;j<m;j++) 
            if ((b[i][j]+b[i+1][j]+b[i][j+1]+b[i+1][j+1])%2==0) 
                a[i][j]=1;
    for (int i=1;i<m;i++) x[i]=0;
    for (int i=1;i<n;i++) {
        for (int j=1;j<m;j++) 
            if (a[i][j]) x[j]++;else x[j]=0;
        memset(f,0,sizeof f);
        memset(p,0,sizeof p);
        r=0;
        for (int j=1;j<=m;j++) {
            while (r && f[r]>=x[j]) {
                ans=max(ans,(j-p[r-1])*(f[r]+1));
                --r;
            }
            f[++r]=x[j];
            p[r]=j;
        }
  
    }
    printf("%d\n",max(ans,max(m,n)));
    return 0;
}