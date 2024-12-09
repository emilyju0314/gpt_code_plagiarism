#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using P = pair<ll, ll>;
using P3 = pair<int,P>;
using PP = pair<P, P>;
constexpr ll INF = 1LL<<60;
constexpr ll MOD = ll(1e9)+7;
constexpr int di[] = {0,1,0,-1};
constexpr int dj[] = {1,0,-1,0};


bool solve(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<P> > row(n), col(m), g((k+2)*2);
    for(int i=0;i<k;i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        row[y].emplace_back(P(x,i*2));
        col[x].emplace_back(P(y,i*2+1));
        g[i*2].emplace_back(P(i*2+1,1));
        g[i*2+1].emplace_back(P(i*2,1));
    }
    int S = k, G = k+1;
    col[0].emplace_back(P(0,S*2));
    row[n-1].emplace_back(P(m-1,G*2));
    col[m-1].emplace_back(P(n-1,G*2+1));
    for(int i=0;i<n;i++){
        sort(row[i].begin(), row[i].end());
        int t = row[i].size();
        for(int j=0;j<t-1;j++){
            int l = row[i][j].first, u = row[i][j].second;
            int r = row[i][j+1].first, v = row[i][j+1].second;
            g[u].emplace_back(P(v,r-l));
            g[v].emplace_back(P(u,r-l));
        }
    }
    for(int i=0;i<m;i++){
        sort(col[i].begin(),col[i].end());
        int t = col[i].size();
        for(int j=0;j<t-1;j++){
            int l = col[i][j].first, u = col[i][j].second;
            int r = col[i][j+1].first, v = col[i][j+1].second;
            g[u].emplace_back(P(v,r-l));
            g[v].emplace_back(P(u,r-l));
        }
    }
    vector<ll> d((k+2)*2, INF);
    priority_queue<P, vector<P>, greater<P> > que;
    d[S*2] = 0;
    que.push(P(0,S*2));
    while(!que.empty()){
        auto p = que.top();
        que.pop();
        int v = p.second;
        if(p.first > d[v]) continue;
        for(auto e : g[v]){
            ll u = e.first, cost = e.second;
            if(d[u] > d[v]+cost){
                d[u] = d[v]+cost;
                que.push(P(d[u],u));
            }
        }
    }
    ll ans = min(d[G*2], d[G*2+1]);
    cout << (ans < INF ? ans : -1) << endl;
    return true;
}

int main(){
    solve();
    return 0;
}

