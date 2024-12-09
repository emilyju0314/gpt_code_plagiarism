#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
using ull = unsigned long long int;
using P = pair<int, int>;
using P3 = pair<int,P>;
using PP = pair<P ,P>;
constexpr ll MOD = ll(1e9+7);
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e6) + 5;
constexpr double EPS = 1e-8;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

int n, m;
vector<ll> d, len, color;
vector<P> ord;
vector<vector<P> > g;
vector<bool> used;

int main(){
    cin >> n >> m;
    d.resize(n);
    g.resize(n);
    used.resize(n);
    color.resize(n,-1);
    len.resize(m);
    for(int i=0;i<n;i++){
        cin >> d[i];
        ord.push_back(P(d[i],i));
    }
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(P(v,i));
        g[v].push_back(P(u,i));
    }
    SORT(ord);
    bool ok = true;
    for(int i=0;i<n;i++){
        int idx = ord[i].second;
        if(used[idx]) continue;
        for(auto &e : g[idx]){
            int v = e.first;
            if(d[v] <= d[idx]){
                len[e.second] = d[idx];
                if(used[v]){
                    color[idx] = color[v]^1;
                }else{
                    color[idx] = 0;
                    color[v] = 1;
                    used[v] = true;
                }
                used[idx] = true;
                break;
            }
        }
        if(!used[idx]) ok = false;
    }
    if(ok){
        for(int i=0;i<n;i++){
            cout << (color[i]==0 ? 'W' : 'B');
        }
        cout << endl;
        for(int i=0;i<m;i++){
            cout << (len[i]>0 ? len[i] : int(1e9)) << endl;
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}