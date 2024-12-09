//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int>P;

class MCF{
public:
	class edge{
	public:
		int to, cap, cost, rev;
		edge(){};
		edge(int _to, int _cap, int _cost, int _rev){
			to = _to;
			cap = _cap;
			cost = _cost;
			rev = _rev;
		}
	};

	vector<vector<edge> >G;
	vector<int>h;
	vector<int>dist;
	vector<int>prevv;
	vector<int>preve;
	MCF(int n){
		G.resize(n);
		preve.resize(n, 0);
		prevv.resize(n, 0);
	}
	void addEdge(int from, int to, int cap, int cost){
		G[from].push_back(edge(to, cap, cost, G[to].size()));
		G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
	}
	int flow(int s, int t, int f){
		int res = 0;
		h.clear();
		h.resize(G.size(), 0);
		while (f > 0){
			priority_queue<P, vector<P>, greater<P> >que;
			dist.clear();
			dist.resize(G.size(), 1145141919);
			dist[s] = 0;
			que.push(P(0, s));
			while (!que.empty()){
				P p = que.top();
				que.pop();
				int v = p.second;
				if (dist[v] < p.first)continue;
				for (int i = 0; i < G[v].size(); i++){
					edge &e = G[v][i];
					if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
						dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
						prevv[e.to] = v;
						preve[e.to] = i;
						que.push(P(dist[e.to], e.to));
					}
				}
			}
			if (dist[t] == 1145141919){
				return res;
                return -1;
			}
			for (int v = 0; v < G.size(); v++)h[v] += dist[v];
			int d = f;
			for (int v = t; v != s; v = prevv[v]){
				d = min(d, G[prevv[v]][preve[v]].cap);
			}
			f -= d;
			res += d*h[t];
			for (int v = t; v != s; v = prevv[v]){
				edge &e = G[prevv[v]][preve[v]];
				e.cap -= d;
				G[v][e.rev].cap += d;
			}
		}
		return res;
	}
};

int main(){

    for(int n;cin>>n,n;){
        MCF mcf(202);
        vector<vector<int> >mt(n);
        vector<int>vol(n, 1);
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j = 0; j< 3;j++){
                int tmp;
                cin>>tmp;
                mt[i].push_back(tmp);
                vol[i]*=tmp;
            }
            sort(mt[i].begin(), mt[i].end());
            sum += vol[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int f = 0;
                for(int k = 0; k < 3; k++){
                    if(mt[i][k] >= mt[j][k])f=1;
                }
                if(f)continue;
                mcf.addEdge(i, 100+j, 1, -vol[i]);
            }
            mcf.addEdge(200, i, 1, 0);
            mcf.addEdge(100+i, 201, 1, 0);
        }
        cout<<sum + mcf.flow(200, 201, 100)<<endl;
    }

	return 0;
}
