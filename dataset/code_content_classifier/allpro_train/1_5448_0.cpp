#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define pb  push_back

const int INF = 1001001001;
const int N = 110, MAX_V = 2 * N;
const int src = 210, sink = 211;

typedef pair<int, int> P;

struct Edge { int to, cap, cost, rev; };

int h[MAX_V];   // potential
vector<Edge> G[MAX_V];

void add_edge(int from, int to, int cap, int cost)
{
    G[from].pb((Edge){ to, cap, cost, (int)G[to].size() });
    G[to].pb((Edge){ from, 0, -cost, (int)G[from].size()-1 });
}

int min_cost_flow()
{
    int res = 0;
    int dist[MAX_V], prevv[MAX_V], preve[MAX_V];
    bool first = true;
    
    while(true)
    {
        priority_queue<P, vector<P>, greater<P> > que;
        fill_n(dist, MAX_V, INF);
        dist[src] = 0;
        que.push(P(0, src));
        
        // dijkstra
        while(!que.empty())
        {
            P p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            rep(i, G[v].size())
            {
                Edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v; preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
        
        if(!first) rep(v, MAX_V) h[v] += dist[v];
        first = false;
        if(h[sink] >= 0) return res;
        
        int f = INF;
        for(int v = sink; v != src; v = prevv[v])
            f = min(f, G[prevv[v]][preve[v]].cap);
        res -= f * h[sink];
        for(int v = sink; v != src; v = prevv[v]) {
            Edge &e = G[prevv[v]][preve[v]];
            e.cap -= f;
            G[v][e.rev].cap += f;
        }
    }
}

int main()
{
    int Nn, Np, Kn[N], Kp[N], M, P, L, In, Ip, NJ;
    string A, J;
    
    while(cin >> Nn >> Np && Nn)
    {
        map<string, int> table;
        fill_n(h, MAX_V, 0);
        rep(i, MAX_V) G[i].clear();
        
        rep(i, Nn) cin >> Kn[i], add_edge(src, i, Kn[i], 0);
        rep(i, Np) cin >> Kp[i], add_edge(Nn+i, sink, Kp[i], 0);
        cin >> M;
        rep(i, M) cin >> A >> P, table[A] = P;
        cin >> L; int vmax = 0;
        rep(i, L) {
            int v = 0;
            cin >> In >> Ip >> NJ;
            rep(j, NJ) cin >> J, v += table[J];
            add_edge(In-1, Nn+Ip-1, INF, -v);   // reverse sign of cost
            h[Nn+Ip-1] = min(h[Nn+Ip-1], -v);
            vmax = max(vmax, v);
        }
        
        h[sink] = -vmax;
        cout << min_cost_flow() << endl;
    }
}