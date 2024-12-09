#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

int n;
int m;
int l;

struct edge{
	int to;
	int cost;
	int damage;
};

int main(){
	while(cin >> n >> m >> l,n || m || l){
		vector<vector<int>> dist(n,vector<int>(l + 1,1e9));
		int s = 0;
		int t = n - 1;
		dist[s][l] = 0;

		vector<vector<edge>> edges(n);
		for(int i = 0;i < m;i++){
			int a,b,d,e;
			cin >> a >> b >> d >> e;
			a--;
			b--;
			edges[a].push_back({b,d,e});
			edges[b].push_back({a,d,e});
		}
		using P2 = pair<int,P>;
		priority_queue<P2,vector<P2>,greater<P2>> que;
		que.push({0,{s,l}});

		while(!que.empty()){
			int d = que.top().first;
			int v = que.top().second.first;
			int c = que.top().second.second;
			que.pop();
			if(dist[v][c] < d) continue;

			for(auto& e : edges[v]){
				//can use?
				if(c - e.cost >= 0 && dist[e.to][c - e.cost] > d){
					dist[e.to][c - e.cost] = d;
					que.push({dist[e.to][c - e.cost] , {e.to,c - e.cost}});
				}
				//dont use?
				if(dist[e.to][c] > d + e.damage){
					dist[e.to][c] = d + e.damage;
					que.push({dist[e.to][c] , {e.to,c}});
				}
			}
		}
		int result = 1e9;

		for(int i = 0;i <= l;i++){
			result = min(result , dist[t][i]);
		}

		cout << result << endl;
	}
}

