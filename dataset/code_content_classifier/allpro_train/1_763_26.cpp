#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge{
	int to, cost;
	edge(){}
	edge(int to_, int cost_){
		to = to_; cost = cost_;
	}
};

vector<edge> G[200];
int V, m, n, k, d, cal[10];

void add_edge(int u, int v, int c){
	G[u].push_back(edge(v, c));
	G[v].push_back(edge(u, c));
}

struct State{
	int cost, v, bits;
	State(){}
	State(int cost_, int v_, int bits_){
		cost = cost_; v = v_; bits = bits_;
	}
};
bool operator<(const State &a, const State &b){
	return a.cost > b.cost;
}

const int INF = 1e+8;
// dp[v][bits] := 頂点vにケーキ屋訪れる状態がbitsのときの最小値
int dp[200][1 << 8];

int solve(){
	for(int i = 0; i < 200; i++){
		for(int j = 0; j < (1 << 8); j++){
			dp[i][j] = INF;
		}
	}
	
	dp[0][0] = 0;
	priority_queue<State> q;
	q.push(State(0, 0, 0));
	
	int res = INF;
	while( !q.empty() ){
		int cost = q.top().cost, v = q.top().v, bits = q.top().bits; q.pop();
		
		// ゴールのとき
		if( v == n + m + 1 ){
			res = min(res, cost);
		}
		if( dp[v][bits] < cost ) continue;
		
		for(int i = 0; i < G[v].size(); i++){
			int next_cost = cost + G[v][i].cost;
			int to = G[v][i].to;
			
			if( 1 <= to && to <= m ){ // ケーキ屋のとき
				if( !(bits & (1 << to)) ){ // まだ訪れていない
					int next_bits = bits | (1 << to);
					next_cost -= cal[to-1];
					if( next_cost < dp[to][next_bits] ){
						//cout << "v:" << v << ", cost:" << cost << ", to:" << to << ", next cost:" << next_cost << endl;
						dp[to][next_bits] = next_cost;
						q.push(State(next_cost, to, next_bits));
					}
				}
			}else{ // それ以外のとき
				if( next_cost < dp[to][bits] ){
					//cout << "v:" << v << ", cost:" << cost << ", to:" << to << ", next cost:" << next_cost << endl;
					dp[to][bits] = next_cost;
					q.push(State(next_cost, to, bits));
				}
			}
		}
	}
	return res;
}

int get(string s){
	if( s[0] == 'H' ) return 0;
	if( s[0] == 'D' ) return n + m + 1;
	if( s[0] == 'L' ) return m + atoi(s.substr(1).c_str());
	if( s[0] == 'C' ) return atoi(s.substr(1).c_str());
}

int main(){
	while( cin >> m >> n >> k >> d , n ){
		// 頂点数
		V = n + m + 2;
		for(int i = 0; i < 200 ; i++) G[i].clear();
		
		for(int i = 0; i < m; i++) cin >> cal[i];
		
		for(int i = 0; i < d; i++){
			string s, t;
			int c;
			cin >> s >> t >> c;
			
			c *= k;
			int u = get(s), v = get(t);
			add_edge(u, v, c);
		}
		int ans = solve();
		cout << ans << endl;
	}
}