#include<bits/stdc++.h>
 
using namespace std;
 
#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};
 
int n, m, k;
// int row_edge[510][510], col_edge[510][510];
set< pair<LL, pair<int, int> > > edge;
int idx[510][510];
pair<int, int> ulta_idx[SZ];
vector<int> adjl[SZ];
vector<int>  cost[SZ];
 
LL ans[SZ][22];
 
LL res[510][510];
 
 
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
 
    int idid = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            idx[i][j] = idid;
            ulta_idx[idid] = {i, j};
            idid++;
        }
    }
 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < m; j++) {
            // cin >> row_edge[i][j];
            // row_st.insert({row_edge[i][j], {i, j}});
            int w;cin >> w;
            int u = idx[i][j];
            int v = idx[i][j + 1];
            
            adjl[u].push_back(v);
            adjl[v].push_back(u);
            
            cost[u].push_back(w);
            cost[v].push_back(w);
 
            edge.insert({w, {u, v}});
        }
    }
 
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            // cin >> col_edge[i][j];
            // col_st.insert({col_edge[i][j], {i, j}});
 
            int w;cin >> w;
            int u = idx[i][j];
            int v = idx[i + 1][j];
            
            adjl[u].push_back(v);
            adjl[v].push_back(u);
            
            cost[u].push_back(w);
            cost[v].push_back(w);
 
            edge.insert({w, {u, v}});
        }
    }
 
    if(k % 2) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << -1 << " ";
            }
            cout << endl;
        }
        return 0;
    }
 
 
    for(int i = 1; i <= n * m; i++) {
        for(int j = 0; j <= k; j++) {
            ans[i][j] = LLONG_MAX;
        }
    }
 
    while(!edge.empty()) {
        pair< LL, pair<int, int> > top = *edge.begin();
        edge.erase(edge.begin());
 
        int uu = top.second.first;
        int vv = top.second.second;
        LL ww = top.first;
 
        // cout << "edge : " << uu << " " << vv << " " << ww << endl;
 
        queue< pair< pair<int, LL>, int> > q;
        
        for(int i = 2; i <= k; i += 2) {
            if(ans[uu][i] > ww * i) {
                ans[uu][i] = ww * i;
                q.push({{uu, ww * i}, i});
            }
            if(ans[vv][i] > ww * i) {
                ans[vv][i] = ww * i;
                q.push({{vv, ww * i}, i});
            }
        }
        
        while(!q.empty()) {
            pair< pair<int, LL>, int> front = q.front();
            q.pop();
            int u = front.first.first;
            LL wcc = front.first.second;
            int lev = front.second + 2;
            if(lev > k) {
                continue;
            }
 
            // if(wcc < 0) {
            //     continue;
            // }
 
            // cout << "queue u : " << u << " " << wcc << " " << lev - 2 << endl;
 
            for(int i = 0; i < (int)adjl[u].size(); i++) {
                int v = adjl[u][i];
                LL w = cost[u][i];
                // cout << "queue v : " << v << " " << w << " " << (wcc + (2 * w)) << endl;
                if(ans[v][lev] > (wcc + (2 * w))) {
                    ans[v][lev] = (wcc + (2 * w));
                    q.push({{v, wcc + (2 * w)}, lev});
                }
            }
        }
    }
 
    for(int i = 1; i <= m * n; i++) {
        PII ulta = ulta_idx[i];
        if(ans[i][k] == LLONG_MAX) {
            ans[i][k] = -1;
        }
        res[ulta.first][ulta.second] = ans[i][k];
    }
 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
 
 
 
    return 0;
}
/**
 * 400000000
*/