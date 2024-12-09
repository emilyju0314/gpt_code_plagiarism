#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<(b);++i)
#define for_rev(i,a,b) for(int i=a;i>=(b);--i)
#define allof(a) (a).begin(),(a).end()

template< typename T >
class MinimumSpanningArborescence {
public:
	struct Result {
		int root;
		vector< int > parent;
		T min_cost;
	};
	
private:
	struct Edge { int from, to; T cost; };
	
	int N;
	vector< vector< Edge > > edges;
	
private:
	vector< vector< int > > vid;
	vector< vector< int > > parent;
	vector< vector< T > > in_cost;
	vector< vector< int > > check;
	
	bool Chu_Liu_Edmonds(int root, T INF) {
		vector< vector< int > > id_to_v(N, vector< int >());
		for_(v,0,N) id_to_v[v].push_back(v);
		
		for_(i,0,N) {
			// construct part
			parent[i].assign(N, -1);
			in_cost[i].assign(N, INF);
						
			for (const Edge& e : edges[i]) {
				if (e.to == root) continue;
				
				int to_id = vid[i][e.to];
				
				if (in_cost[i][to_id] > e.cost) {
					in_cost[i][to_id] = e.cost;
					parent[i][to_id] = e.from;
				}
			}
						
			bool no_answer = false;
			
			for_(v,0,N) {
				if (v == root) continue;
				int id = vid[i][v];
				no_answer |= (in_cost[i][id] == INF);
			}
			
			if (no_answer) return false;
			
			// loop check part
			check[i].assign(N, 0);
			vid[i + 1] = vid[i];
			
			vector< vector< int > > next_id_to_v(N, vector< int >());
			
			int cycle_count = 0;
			
			for_(v,0,N) {
				if (v == root) {
					next_id_to_v[root].push_back(root);
					continue;
				}
				
				int id = vid[i][v];
				if (check[i][id] > 0) continue;
				
				stack< int > visited;
				
				while (parent[i][id] != -1 && check[i][id] == 0) {
					check[i][id] = 2;
					visited.push(id);
					id = vid[i][parent[i][id]];
				}
				
				bool is_loop = (check[i][id] == 2);
				int loop_term = id;
				cycle_count += is_loop;
				
				int cycle_id = visited.top();
				
				while (!visited.empty()) {
					id = visited.top(); visited.pop();
					
					if (is_loop) check[i][id] += cycle_count;
					else check[i][id] = 1;
					
					for (int u : id_to_v[id]) {
						next_id_to_v[(is_loop ? cycle_id : id)].push_back(u);
						vid[i + 1][u] = (is_loop ? cycle_id : id);
					}
					
					is_loop &= (loop_term != id);
				}
			}
			
			if (cycle_count == 0) break;
			
			// contract part
			for (const Edge& e : edges[i]) {
				if (e.to == root) continue;
				
				int from_id = vid[i][e.from], to_id = vid[i][e.to];
				
				if (check[i][from_id] >= 3 && check[i][from_id] == check[i][to_id]) continue;
				
				if (check[i][to_id] >= 3) {
					edges[i + 1].push_back(Edge{e.from, e.to, e.cost - in_cost[i][to_id]});
				} else {
					edges[i + 1].push_back(e);
				}
			}
			
			swap(next_id_to_v, id_to_v);
		}
		
		return true;
	}
	
	T restoration(int root, T INF) {
		int rec_cnt = 0;
		for_(i,0,N) if (edges[i].size() > 0) ++rec_cnt;
				
		for_rev(i,rec_cnt-1,1) {
			for (Edge& e : edges[i]) {
				int to_id = vid[i][e.to];
				
				if (parent[i][to_id] != e.from) continue;
				if (in_cost[i][to_id] != e.cost) continue;
				
				int prv_to_id = vid[i - 1][e.to];
				
				parent[i - 1][prv_to_id] = parent[i][to_id];
				
				if (check[i - 1][prv_to_id] >= 3) {
					in_cost[i - 1][prv_to_id] += in_cost[i][to_id];
				} else {
					in_cost[i - 1][prv_to_id] = in_cost[i][to_id];
				}
				
				parent[i][to_id] = -1;
				in_cost[i][to_id] = INF;
			}
		}
				
		T res = 0;
		for_(v,0,N) if (v != root) res += in_cost[0][v];
		return res;
	}
	
public:
	MinimumSpanningArborescence(int _N_) : N(_N_), edges(N, vector< Edge >()) {}
	
	void addEdge(int from, int to, T cost) {
		edges[0].push_back(Edge{from, to, cost});
	}
	
	Result construct(int root, T INF) {
		for_(i,1,N) edges[i].clear();
		
		vid.assign(N, vector< int >());
		vid[0].assign(N, -1);
		for_(v,0,N) vid[0][v] = v;
		
		parent.assign(N, vector< int >());
		in_cost.assign(N, vector< T >());
		check.assign(N, vector< int >());
		
		T min_cost = INF;
		if (Chu_Liu_Edmonds(root, INF)) min_cost = restoration(root, INF);
		
		return Result{root, parent[0], min_cost};
	}
};

struct Edge : pair< int, int >{
	Edge(int v, int c) : pair< int, int >(c, v) {}
	int v() const { return second; }
	int c() const { return first; }
};

int N, M, in_deg[10010], cost[55][10010];
vector< vector< Edge > > adj;

void dijkstra(int id, int s) {
	for_(v,0,N) cost[id][v] = 1L << 30;
	
	priority_queue< Edge, vector< Edge >, greater< Edge > > que;
	que.push(Edge(s, 0));
	cost[id][s] = 0;
		
	while (!que.empty()) {
		Edge state = que.top(); que.pop();
		int v = state.v(), c = state.c();
		
		if (cost[id][v] < c) continue;
		
		for (const Edge& e : adj[v]) {
			if (cost[id][e.v()] > c + e.c()) {
				cost[id][e.v()] = c + e.c();
				que.push(Edge(e.v(), c + e.c()));
			}
		}
	}
}

void solve() {
	vector< int > cand;
	for_(v,0,N) if (in_deg[v] == 0) cand.push_back(v);
	
	int C = cand.size();
	for_(i,0,C) dijkstra(i, cand[i]);
		
	MinimumSpanningArborescence< int > msa(C);
	
	for_(i,0,C) for_(j,0,C) if (i != j) {
		msa.addEdge(i, j, cost[i][cand[j]]);
	}
	
	int min_cost = 1L << 30;
	vector< int > ans;
	
	for_(i,0,C) {
		int ci = msa.construct(i, 1L << 30).min_cost;
		
		if (min_cost > ci) {
			min_cost = ci;
			ans.clear();
		}
		
		if (min_cost == ci) ans.push_back(cand[i]);
	}
	
	int A = ans.size();
	cout << A << " " << min_cost << endl;
	for_(i,0,A) cout << ans[i] << (i < A - 1 ? " " : "\n");
}

int main() {
	cin >> N >> M;
	
	memset(in_deg, 0, sizeof(in_deg));
	adj.assign(N, vector< Edge >());
	
	for_(i,0,M) {
		int a, b;
		cin >> a >> b;
		++in_deg[b];
		adj[a].push_back(Edge(b, 0));
		adj[b].push_back(Edge(a, 1));
	}
	
	solve();
}