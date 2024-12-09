#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
using ull = unsigned long long int;
using P = pair<int, int>;
using P3 = pair<int,P>;
using PP = pair<P ,P>;
constexpr ll MOD = ll(1e9+7);
constexpr int IINF = INT_MAX;

vector<vector<P> > g;
int dist[105][15];

int main(){
    int c, n, m, s, d;
    while(cin >> c >> n >> m >> s >> d, n){
        s--; d--;
        g.clear();
        g.resize(n);
        for(int i=0;i<m;i++){
            int a, b, f;
            cin >> a >> b >> f;
            a--; b--;
            g[a].push_back(P(b,f));
            g[b].push_back(P(a,f));
        }
        for(int i=0;i<n;i++){
            fill(dist[i], dist[i]+c+1, IINF/2);
        }
        dist[s][c] = 0;
        priority_queue<P3, vector<P3>, greater<P3> > que;
        que.push(P3(0, P(s, c)));
        while(!que.empty()){
            auto p = que.top();
            que.pop();
            int now = p.second.first, r = p.second.second;
            if(dist[now][r] < p.first) continue;
            for(auto e : g[now]){
                int nxt = e.first, f = e.second;
                if(dist[nxt][r] > dist[now][r] + f){
                    dist[nxt][r] = dist[now][r] + f;
                    que.push(P3(dist[nxt][r], P(nxt,r)));
                }
                if(r>0 && dist[nxt][r-1] > dist[now][r] + f/2){
                    dist[nxt][r-1] = dist[now][r] + f/2;
                    que.push(P3(dist[nxt][r-1], P(nxt,r-1)));
                }
            }
        }
        int ans = IINF;
        for(int i=0;i<=c;i++){
            ans = min(ans, dist[d][i]);
        }
        cout << ans << endl;
    }

    return 0;
}
