#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using P = pair<int, int>;

double p, z = 0;
vector<vector<P> > g;

double dfs(int now, int pre){
    double res = 0;
    for(auto e : g[now]){
        int nxt = e.first, c = e.second;
        if(nxt == pre) continue;
        res += p*(dfs(nxt,now)+c);
    }
    return res + z;
}

bool solve(){
    int n;
    cin >> p >> n;
    g.resize(n);
    for(int i=0;i<n-1;i++){
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        g[x].push_back(P(y,c));
        g[y].push_back(P(x,c));
    }
    z = dfs(0,-1);
    printf("%.9lf\n",dfs(0,-1));
    return true;
}

int main(){
    solve();
    return 0;
}
