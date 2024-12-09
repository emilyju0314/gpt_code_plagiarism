#include "bits/stdc++.h"
using namespace std;
struct bus {
	int from;
	int to;
	int depart;
	int arrive;
};
bool operator<(const bus&l, const bus&r) {
	return l.depart < r.depart;
}
struct edge {
	int from;
	int to;
	int cost;
};
struct aa {
	int now;
	int time;
};
class Compare {
public:
	bool operator()(const aa&l, const aa&r) {
		return l.time> r.time;
	}
};	//aa?????????????????¶


int N, M, S, G;

int  dfs(const int start,const int goal, const vector<vector<edge>>&edges,vector<int>&memo,const vector<int>&node_id) {
	int ans = 1e7;
	priority_queue<aa,vector<aa>,Compare>que;
	que.push(aa{ start,0 });
	while (!que.empty()) {
		aa atop(que.top());
		que.pop();
		for (auto e : edges[atop.now]) {
			if (e.to==goal) {
				return atop.time;
			}
			if (memo[e.to] > atop.time + e.cost) {
				memo[e.to] = atop.time + e.cost;
				que.push(aa{ e.to,atop.time+e.cost });
			}
		}
	}
	return -1;
	
}
int main() {cin >> N >> M >> S >> G;
	S--; G--;
	vector<vector<bus>>buss(N);
	for (int i = 0; i < M; ++i) {
		int u, v, t, c; cin >> u >> v >> t >>c;
		buss[u-1].push_back(bus{ u - 1,v - 1,t,t+c });
	}
	for (int i = 0; i < N; ++i) {
		sort(buss[i].begin(), buss[i].end());
	}
	
	const int start = 0;
	vector<int>node_id(N);
	int num = 1;
	for (int i = 0; i < N; ++i) {
		node_id[i] = num;
		num += buss[i].size();
	}
	const int goal = num;
	vector<vector<edge>>edges(num+1);
	vector<int>memo(num, 1e8);
	edges[start].push_back(edge{ start,node_id[S],buss[S][0].depart });
	

	for (int from_stop = 0; from_stop < N; ++from_stop) {
		for (int i = 0; i < buss[from_stop].size(); ++i) {
			bus b(buss[from_stop][i]);
			const int from_id = node_id[from_stop] +i;

			if (i != buss[from_stop].size() - 1) {
				edges[from_id].push_back(edge{ from_id,from_id + 1,buss[from_stop][i + 1].depart - buss[from_stop][i].depart });
			}

			auto it = lower_bound(buss[b.to].begin(), buss[b.to].end(), bus{ -1,-1,b.arrive,-1 });
			if (b.to == G) {
				edges[from_id].push_back(edge{ from_id,goal,0 });
			}
			else {
				if (it != buss[b.to].end()) {
					const int to_id = node_id[b.to] + (it - buss[b.to].begin());
					const int acost = it->depart-b.arrive;
					edges[from_id].push_back(edge{ from_id, to_id, acost });
				}
			}
			
		}
	}
	int ans=dfs(0,goal, edges, memo,node_id);
	cout << ans << endl;
	return 0;
}