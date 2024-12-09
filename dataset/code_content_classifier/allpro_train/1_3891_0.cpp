#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

const double EPS = 1.0e-10;
const double INF = DBL_MAX / 1000;

class Edge
{
public:
    int to, cost, experience;
    Edge(){};
    Edge(int to0, int cost0, int experience0){
        to = to0;
        cost = cost0;
        experience = experience0;
    }
};

void shortestPath(const vector<vector<Edge> >& edges, int start, vector<int>& dist)
{
    dist.assign(edges.size(), INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push(make_pair(0, start));

    while(!q.empty()){
        pair<int, int> p = q.top();
        q.pop();
        int v = p.second;
        if(dist[v] < p.first)
            continue;
        for(unsigned i=0; i<edges[v].size(); ++i){
            Edge e = edges[v][i];
            if(dist[v] + e.cost < dist[e.to]){
                dist[e.to] = dist[v] + e.cost;
                q.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    replace(dist.begin(), dist.end(), INT_MAX, -1);
}

int main()
{
    int c;
    cin >> c;

    while(--c >= 0){
        int n, m;
        cin >> n >> m;

        int start, goal;
        cin >> start >> goal;

        vector<vector<Edge> > edges(n);
        for(int i=0; i<m; ++i){
            int u, v, e, t;
            cin >> u >> v >> e >> t;
            edges[u].push_back(Edge(v, t, e));
            edges[v].push_back(Edge(u, t, e));
        }

        vector<int> dist; // ゴールまでの距離
        shortestPath(edges, goal, dist);
        vector<pair<int, int> > d(n);
        for(int i=0; i<n; ++i)
            d[i] = make_pair(dist[i], i);
        sort(d.rbegin(), d.rend());

        // 効率の値effを2分探索
        // Σexp/Σcost >= eff ⇔ Σexp >= eff*Σcost ⇔ Σ(exp - eff*cost) >= 0

        double left = 0.0;
        double right = 1000000.0;
        while(left < right - EPS){
            double eff = (left + right) / 2.0;

            vector<double> dp(n, -INF);
            dp[start] = 0.0;
            for(int i=0; i<n; ++i){
                int a = d[i].second;
                for(unsigned j=0; j<edges[a].size(); ++j){
                    int b = edges[a][j].to;
                    if(dist[b] < dist[a])
                        dp[b] = max(dp[b], dp[a] + (edges[a][j].experience - eff * edges[a][j].cost));
                }
            }

            if(dp[goal] >= 0.0)
                left = eff;
            else
                right = eff;
        }

        printf("%.10f\n", (left + right) / 2.0);
    }

    return 0;
}