#include<bits/stdc++.h>
#define N 210
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
vector<int> e[N];
const ll mod=1e9+7;
int n,now;
ll dd;
int dis[N][N];
ll b[N];
bool vis[N];
int flag[N];
ll f[N][N];
vector<int>vec[N][N];
int ff[N];
ll ans;
ll qpow(ll xx,ll yy){
    ll res=1;
    while(yy){
        if(yy&1){
            res*=xx;
            res%=mod;
        }
        xx*=xx;
        xx%=mod;
        yy>>=1;
    }
    return res;
}
void dfs(int u,int fa,int d){
    dis[now][u]=dis[u][now]=d;
    ff[u]=fa;
    int tmpu=u;
    while(tmpu!=now){
        vec[now][u].push_back(tmpu);
        tmpu=ff[tmpu];
    }
    for(int v:e[u]){
        if(v==fa) continue;
        dfs(v,u,d+1);
    }
}
void dfs_2(int u,int fa){
    ans+=qpow(n,mod-2);
    ans%=mod;
    for(int v:e[u]){
        if(vis[v]||v==fa) continue;
        dfs_2(v,u);
    }
}
void dfs_3(int u,int fa){
    ans+=dd;
    ans%=mod;
    for(int v:e[u]){
        if(vis[v]||v==fa) continue;
        dfs_3(v,u);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n+1;++i){
        b[i]=qpow(2,i);
    }
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        now=i;
        dfs(i,-1,0);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            reverse(vec[i][j].begin(),vec[i][j].end());
        }
    }
    f[0][1]=0;
    for(int i=1;i<=n;++i){
        f[i][0]=1;
        for(int j=1;j<=n;++j){
            f[i][j]=(f[i-1][j]+f[i][j-1])*qpow(2,mod-2);
            f[i][j]%=mod;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            dd=0;

//            cout<<dd<<endl;
//            cout<<i<<" "<<j<<"..\n";
//            for(int k=1;k<=n;++k){
//                cout<<k<<" "<<flag[k]<<"...\n";
//            }
            for(int k=1;k<=n;++k){
                vis[k]=0;
            }
            vis[j]=1;
            for(int item:vec[j][i]){
                //cout<<j<<" "<<i<<" "<<item<<"..\n";
                vis[item]=1;
            }
            dfs_2(j,-1);
            int re=dis[i][j]-1;
            int nn=1;
            for(int idx=0;idx+1<vec[j][i].size();++idx){
                dd=f[re][nn];
                //cout<<dd<<"...\n";
                dd*=qpow(n,mod-2);
                dd%=mod;
                //cout<<dd<<"...\n";
                dfs_3(vec[j][i][idx],-1);
                nn++;
                re--;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
