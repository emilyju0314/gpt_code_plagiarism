#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;

const int MAX_N=1e5+10;

int n,m,u,v,ok=1; ll s;
vector<vector<pair<int,ll>>> G(MAX_N);
vector<vector<ll>> cnt(2,vector<ll>(MAX_N,INF));

void dfs(int v,int p){
    for (auto e:G[v]){
        int u=e.first,update=0;
        if (u==p) continue;
        if (cnt[0][v]!=INF){
            ll x=e.second-cnt[0][v];
            if (cnt[1][u]!=INF&&cnt[1][u]!=x) ok=0;
            else if (cnt[1][u]==INF) cnt[1][u]=x,update=1;
        }
        if (cnt[1][v]!=INF){
            ll x=e.second-cnt[1][v];
            if (cnt[0][u]!=INF&&cnt[0][u]!=x) ok=0;
            else if (cnt[0][u]==INF) cnt[0][u]=x,update=1;
        }
        if (update) dfs(u,v);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<m;++i){
        cin >> u >> v >> s; --u,--v;
        G[u].emplace_back(v,s);
        G[v].emplace_back(u,s);
    }
    cnt[0][0]=0;
    dfs(0,-1);
    if (!ok){cout << 0 << '\n'; return 0;}
    ll x=INF;
    for (int v=0;v<n;++v) if (cnt[0][v]!=INF&&cnt[1][v]!=INF){
        if ((cnt[1][v]-cnt[0][v])%2!=0) ok=0;
        x=(cnt[1][v]-cnt[0][v])/2; break;
    }
    if (x!=INF){
        for (int v=0;v<n;++v){
            if (cnt[0][v]!=INF&&x+cnt[0][v]<1) ok=0;
            if (cnt[1][v]!=INF&&-x+cnt[1][v]<1) ok=0;
            if (cnt[0][v]!=INF&&cnt[1][v]!=INF){
                if ((cnt[1][v]-cnt[0][v])%2!=0) ok=0;
                if (x!=(cnt[1][v]-cnt[0][v])/2) ok=0;
            }
        }
        if (!ok){cout << 0 << '\n'; return 0;}
        cout << 1 << '\n'; return 0;
    }
    ll Min=INF,Max=0;
    for (int v=0;v<n;++v){
        Min=min(Min,cnt[1][v]);
        Max=max(Max,-cnt[0][v]);
    }
    cout << max(0LL,Min-Max-1) << '\n';
}