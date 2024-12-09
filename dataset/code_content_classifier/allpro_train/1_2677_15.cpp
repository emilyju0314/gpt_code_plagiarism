#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using P = pair<int, int>;
using P3 = pair<ll,P>;
using PP = pair<P, P>;
constexpr int INF = 1 << 30;
constexpr ll MOD = ll(1e9) + 7;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};
constexpr double EPS = 1e-8;

int V, E;
vector<vector<int> > g;
vector<char> ch;

bool solve(){
    cin >> V >> E;
    g.resize(V);
    ch.resize(V);
    for(int i=0;i<V;i++){
        cin >> ch[i];
    }
    for(int i=0;i<E;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> used(26);
    for(int i=0;i<V;i++){
        if(ch[i] != '?') continue;
        fill(used.begin(),used.end(),false);
        for(auto j : g[i]){
            if(ch[j]=='?') continue;
            used[ch[j]-'a'] = true;
        }
        for(int j=0;j<26;j++){
            if(!used[j]){
                ch[i] = char('a'+j);
                break;
            }
        }
    }
    for(auto c: ch){
        cout << c;
    }
    cout << endl;
    return false;
}

int main(){
    solve();
    // while(!solve());
    // int t; cin >> t; for(;t>0;t--) solve();
    return 0;
}
