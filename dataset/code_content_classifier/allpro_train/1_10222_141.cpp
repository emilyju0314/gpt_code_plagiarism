#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

class LowestCommonAncestor
{
public:
    const int N;
    vector<vector<int>> G;
    vector<int> parent,depth;
    const int LOG;
    vector<vector<int>> dp;

    LowestCommonAncestor(vector<vector<int>> G):N(G.size()),G(G),parent(N),depth(N),LOG(32-__builtin_clz(N))
    {
        dfs(0,-1,0);
        dp.assign(LOG,vector<int>(N,-1));
        for(int i=0;i<N;i++) dp[0][i]=parent[i];
        for(int i=0;i+1<LOG;i++){
            for(int j=0;j<N;j++){
                if(dp[i][j]==-1) dp[i+1][j]=-1;
                else dp[i+1][j]=dp[i][dp[i][j]];
            }
        }
    }
    void dfs(int v,int p,int d)
    {
        parent[v]=p;
        depth[v]=d;
        for(int u:G[v]) if(u!=p){
            dfs(u,v,d+1);
        }
    }
    int query(int u,int v)
    {
        if(depth[u]>depth[v]) swap(u,v);
        for(int i=0;i<LOG;i++){
            if((depth[v]-depth[u])>>i&1) v=dp[i][v]; 
        }
        if(u==v) return u;
        for(int i=LOG-1;i>=0;i--){
            if(dp[i][u]!=dp[i][v]){
                u=dp[i][u];
                v=dp[i][v];
            }
        }
        return dp[0][u];
    }
};

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin>>N;
    vector<vector<int>> G(N);
    for(int i=0;i<N;i++){
        int k; cin>>k;
        while(k--){
            int j; cin>>j;
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }
    LowestCommonAncestor lca(G);
    int Q; cin>>Q;
    while(Q--){
        int u,v; cin>>u>>v;
        cout<<lca.query(u,v)<<endl;
    }
    return 0;
}
