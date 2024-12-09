#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<bitset>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
    int f=1,ans=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return f*ans;
}
const int MAXN=1e5+11;
bitset<100001> f[501],ww; vector<int> vec[MAXN],V[MAXN],VV[MAXN];
int N,siz[MAXN],cnt[MAXN],dep[MAXN],Num[MAXN],tot,K,vis[MAXN],Ans[MAXN];
pii sta[MAXN];
void dfs(int u,int fath){
    siz[u]=1,dep[u]=dep[fath]+1; cnt[dep[u]]++;
    for(auto v:vec[u]) if(v!=fath) dfs(v,u),siz[u]+=siz[v]; return;
}
bool cmp(int x,int y){return siz[x]<siz[y];}
int main(){
    //freopen("1.in","r",stdin);
    N=read(),K=read(); for(int i=2;i<=N;i++){int u=read(),v=i;vec[u].pb(v),vec[v].pb(u);}
    dfs(1,0); int Maxn=0; for(int i=1;i<=N;i++) Maxn=max(Maxn,dep[i]);
    for(int i=1;i<=Maxn;i++) V[cnt[i]].pb(i);
    for(int i=1;i<=N;i++) if(V[i].size()){++tot;sta[tot].fi=i,sta[tot].se=V[i].size();}
    f[0][0]=1;
    for(int i=1;i<=tot;i++){
        int v=sta[i].fi,c=sta[i].se;
        for(int j=0;j<=c;j++) f[i]|=f[i-1]<<(j*v);
    }
    if(f[tot][K]){
        printf("%d\n",Maxn); int now=K;
        for(int i=tot;i>=1;i--){
            int v=sta[i].fi,c=sta[i].se,ps=-1;
            for(int j=0;j<=c;j++) if(f[i-1][now-j*v]){ps=j;break;}
            for(int j=1;j<=ps;j++) vis[V[v][j-1]]=1;
            now-=ps*v;
        }
        for(int i=1;i<=N;i++) printf(vis[dep[i]]?"a":"b");printf("\n"); return 0;
    }
    printf("%d\n",Maxn+1); pii a=mp(0,K),b=mp(1,N-K);
    for(int i=1;i<=N;i++) V[i].clear(); for(int i=1;i<=N;i++) V[siz[i]].pb(i);
    for(int i=1;i<=N;i++) for(auto v:V[i]) VV[dep[v]].pb(v);
    for(int i=1;i<=Maxn;i++){
        if(a.se<b.se) swap(a,b);
        while(VV[i].size()&&a.se) Ans[VV[i].back()]=a.fi,a.se--,VV[i].pop_back();
        while(VV[i].size()&&b.se) Ans[VV[i].back()]=b.fi,b.se--,VV[i].pop_back();
    }
    for(int i=1;i<=N;i++) printf(!Ans[i]?"a":"b"); printf("\n"); return 0;
}

