#include<bits/stdc++.h>
#define ll long long
#define maxn 55
#define limit 2500
using namespace std;
struct edge {
	int v,a,b;
};
vector<edge> G[maxn];
int value[maxn],cost[maxn];
struct state {
	int u,num;
	ll tim;
	bool operator < (const state& a) const{
		return tim > a.tim;
	}
};
ll dis[maxn][maxn*maxn];
void dijkstra(int s) {
	s = min(s,limit);
	
	memset(dis,-1,sizeof dis);
	dis[1][s] = 0;
	priority_queue<state> pq;
	pq.push(state{1,s,0});
	
	while(!pq.empty()) {
		state now = pq.top();
		pq.pop();
		
		int u = now.u , num = now.num;
		ll tim = now.tim;
		if(dis[u][num] != tim)	continue;
		
		for(edge e : G[u]) {
			int v = e.v , a = e.a , b = e.b;
			if(num >= a) {
				if(dis[v][num - a] == -1 || dis[v][num - a] > tim + b) {
					dis[v][num - a] = tim + b;
					pq.push(state{v,num - a,tim + b});
				}
			}
		}
		
		num += value[u] , tim += cost[u];
		if(num <= limit && (dis[u][num] == -1 || dis[u][num] > tim)) {
			dis[u][num] = tim;
			pq.push(state{u,num,tim});
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,s;
	cin >> n >> m >> s;
	while(m--) {
		int u,v,a,b;
		cin >> u >> v >> a >> b;
		G[u].push_back(edge{v,a,b});
		G[v].push_back(edge{u,a,b});
	}
	for(int i=1;i<=n;i++)
		cin >> value[i] >> cost[i];
	
	dijkstra(s);
	
	for(int i=2;i<=n;i++) {
		ll ans = -1;
		for(int j=0;j<=limit;j++)
			if(dis[i][j] != -1 && (ans == -1 || ans > dis[i][j]))
				ans = dis[i][j];
		cout << ans << endl;
	}
	return 0;
}