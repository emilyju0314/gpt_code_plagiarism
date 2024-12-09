#include <bits/stdc++.h>
using namespace std;

#define int ll 
#define f first
#define s second
#define pb push_back
#define ar array
#define all(x) x.begin(), x.end()
#define siz(x) (int) x.size()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define FOR(i, a, b) for(auto i=(a); i<(b); i++)
#define ROF(i, a, b) for(auto i=(b)-1; i>=(a); i--)
#define F0R(i, n) FOR(i, 0, n)
#define R0F(i, n) ROF(i, 0, n)

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using vi=vector<int>;
using vl=vector<ll>;
using vpii=vector<pii>;

template<class T> bool ckmin(T&a, const T&b) {return b<a?a=b,1:0;}
template<class T> bool ckmax(T&a, const T&b) {return b>a?a=b,1:0;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN=2e5+10;
const int MOD=1e9+7; 
const ll infLL=1e18;
const ld eps=1e-6;

void solve(){
    int N; cin >> N;
    vector<vi> adj(N); 
    F0R(i, N-1){
        int e1, e2; cin >> e1 >> e2;
        adj[e1].pb(e2);
        adj[e2].pb(e1); 
    }
    vi sz(N), tin(N), tout(N), anc(N), par(N); int tim=0;
    function<void(int, int)> dfs=[&](int u, int p){
        tin[u]=tim++;
        par[u]=p;
        for(auto v:adj[u]){
            if(v==p) continue;
            dfs(v, u);
            sz[u]+=sz[v];
        }
        sz[u]++;
        tout[u]=tim++;
    };
    function<void(int, int, int)> dfs_zero=[&](int u, int p, int c){
        anc[u]=c;
        for(auto v:adj[u]){
            if(v==p) continue;
            dfs_zero(v, u, c);
        }
    };
    auto is_anc=[&](int u, int p){
        if(tin[p]<tin[u]&&tout[u]<tout[p]) return 1;
        return 0;
    };
    dfs(0, -1);
    vl ans(N+1);
    for(auto c:adj[0]) 
        ans[0]+=(1LL*sz[c]*(sz[c]-1))/2;
    for(auto c:adj[0]) 
        dfs_zero(c, 0, c);
    vi vis(N); 
    // int mex=1;
    auto trav=[&](int i, int Y){
        int X=i;
        while(X!=Y){
            vis[X]=1;
            // while(vis[mex]&&mex<N) mex++;
            X=par[X];
        }
    };
    // F0R(i, N) cout << anc[i] << ' ';
    // cout << "\n";
    // F0R(i, N) cout << sz[i] << ' ';
    // cout << "\n";
    {
        ll p=0;
        trav(1, 0);
        for(auto c:adj[0]){
            int cur=sz[c];
            if(c==anc[1]){
                cur-=sz[1];
                sz[0]-=sz[c];
            }
            ans[1]+=p*cur;
            ans[1]+=cur;
            p+=cur;
        }
        // cout << "siz 0: " << sz[0] << "\n";
    }
    int X=0, Y=1;
    FOR(i, 2, N){
        if(vis[i])
            continue;
        if(is_anc(Y, X)) swap(X, Y);
        // cout << X << ' ' << Y << ' ' << i << endl;
        bool b=0;
        if(Y==0){
            if(anc[i]==anc[1]) b=1;
        }
        if(is_anc(i, X)){
            // cout << "CHK: " << i << ' ' << X << "\n";
            ans[i]+=1LL*(sz[X]-sz[i])*(sz[Y]);
            trav(i, X);
            X=i;
        }
        else if(is_anc(i, Y)&&b==0){
            // cout << "CHK: " << i << ' ' << Y << "\n";
            ans[i]+=1LL*(sz[Y]-sz[i])*sz[X];
            trav(i, Y);
            Y=i;
        }
        else{
            ans[i]+=1LL*sz[Y]*sz[X];
            break;
        }
    }
    {
        ll p=0;
        F0R(i, N+1){
            p+=ans[i];
        }
        ans[N]=1LL*N*(N-1)/2-p;
    }
    F0R(i, N+1) cout << ans[i] << ' ';
    cout << "\n";
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();    
    return 0; 
}

