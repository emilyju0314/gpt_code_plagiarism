#include <bits/stdc++.h>
#define INF 1e+9
using namespace std;

struct edge{ int to,cost; };
typedef pair<int,int> P;

int main(){
	int n,m;
	while(cin >> n >> m,n){
		int mi = INF,d[100];
		vector<edge> G[100];
		for(int i = 0;i < m;i++){
			int a,b,c;
			cin >> a >> b >> c; a--; b--;
			G[a].push_back({b,c});
			G[b].push_back({a,c});
		}
		if(n == 2){
			cout << G[0][0].cost << endl;
			continue;
		}
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				set<int> st;
				bool flag = false;
				for(int k = 0;k < G[i].size();k++) st.insert(G[i][k].to);
				for(int k = 0;k < G[j].size();k++){
					if(st.count(G[j][k].to)) flag = true;
				}
				if(!flag) continue;
				vector<edge> G2[100];
				for(int k = 0;k < n;k++){
					d[k] = INF;
					G2[k] = G[k];
				}
				G2[i].push_back({j,0});
				G2[j].push_back({i,0});
				d[0] = 0;
				priority_queue<P,vector<P>,greater<P> > que;
				que.push(P(0,0));
				while(!que.empty()){
					P p = que.top();que.pop();
					int v = p.second;
					if(d[v] < p.first) continue;
					for(int k = 0;k < G2[v].size();k++){
						edge e = G2[v][k];
						if(d[e.to] > d[v] + e.cost){
							d[e.to] = d[v] + e.cost;
							que.push(P(d[e.to],e.to));
						}
					}
				}
				mi = min(mi,d[n - 1]);
			}
		}
		cout << mi << endl;
	}
	return 0;
}