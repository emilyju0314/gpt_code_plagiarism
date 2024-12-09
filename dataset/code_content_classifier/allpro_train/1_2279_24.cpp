#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 220;
const int mod = 1e9+7;

int n,dp[maxn][maxn];
vector<int> g[maxn];
int siz[maxn],dep[maxn],top[maxn],son[maxn],fa[maxn];


int qpow(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        k >>= 1;
    }
    return res;
}

void dfs1(int now,int f,int deep){
    dep[now] = deep;
    fa[now] = f;
    siz[now] = 1;
    int maxsize = -1;
    for(auto to:g[now]){
        if(to==f) continue;
        dfs1(to,now,deep+1);
        siz[now]+=siz[to];
        if(maxsize<siz[to])
            maxsize = siz[to] , son[now] = to;
    }
}

void dfs2(int now,int topf){
    top[now] = topf;
    if(!son[now]) return ;  //!
    dfs2(son[now],topf);
    for(auto to:g[now]){
        if(to==fa[now]||to==son[now]) continue;
        dfs2(to,to);
    }
}

int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) //!
            swap(x,y);
        x = fa[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    return y;
}
void init(){
    for(int i=0;i<=n;i++)
        siz[i]=dep[i]=top[i]=son[i]=fa[i]=0;
}

signed main(){
    scanf("%lld",&n);
    for(int i=1,u,v;i<n;i++){
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int mod2 = qpow(2,mod-2);

    for(int i=1;i<=n;i++) dp[i][0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])*mod2%mod;

    int ans = 0, modn = qpow(n,mod-2);
    for(int r=1;r<=n;r++){
        init();
        dfs1(r,0,1);
        dfs2(r,r);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int x = lca(i,j);
                int p = dp[dep[i]-dep[x]][dep[j]-dep[x]]*modn%mod;
                if(p)
                    ans = (ans+p)%mod;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
  	  		 		       			 	 	    	 	