#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <utility>
#include <cassert>
using namespace std;

vector<array<int,8>> G;
vector<int> colors;
vector<int> gens;
int gen;

int getcolor(int u){
	int c = 15;
	for(int v : G[u]){
		if(v >= 0 && colors[v] >= 0){
			c &= ~(1 << colors[v]);
		}
	}
	if(c == 0){ return -1; }
	for(int i = 0; ; ++i){
		if(c >> i & 1){ return i; }
	}
}

template <class A>
void dfs(int u, int c1, int c2, A action){
	++gen;
	vector<int> s;
	s.push_back(u);
	gens[u] = gen;
	while(!s.empty()){
		u = s.back();
		s.pop_back();
		action(u);
		for(int v : G[u]){
			if(v >= 0 && gens[v] != gen && (colors[v] == c1 || colors[v] == c2)){
				gens[v] = gen;
				s.push_back(v);
			}
		}
	}
}

void flip(int from, int other){
	assert(from >= 0 && other >= 0);
	int c1 = colors[from], c2 = colors[other];
	dfs(from, c1, c2, [&](int x){ colors[x] ^= c1 ^ c2; });
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	gens.assign(n, -1);

	vector<pair<int,int>> pts(n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &pts[i].second, &pts[i].first);
	}

	array<int,8> defarr;
	fill(defarr.begin(), defarr.end(), -1);
	G.assign(n, defarr);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		
		int d;
		if(pts[u].first == pts[v].first){
			d = pts[u].second < pts[v].second ? 0 : 4;
		}
		else if(pts[u].second == pts[v].second){
			d = pts[u].first < pts[v].first ? 2 : 6;
		}
		else if(pts[u].first < pts[v].first){
			d = pts[u].second < pts[v].second ? 1 : 3;
		}
		else{
			d = pts[u].second < pts[v].second ? 7 : 5;
		}

		G[u][d] = v;
		G[v][(d + 4) & 7] = u;
	}

	vector<int> ids(n);
	iota(ids.begin(), ids.end(), 0);
	sort(ids.begin(), ids.end(), [&](int x, int y){ return pts[x] > pts[y]; });
	colors.assign(n, -1);
	for(int u : ids){
		int c = getcolor(u);
		if(c >= 0){
			colors[u] = c;
			continue;
		}
		int from = G[u][0], to = G[u][2];
		assert(from >= 0 && to >= 0);
		bool vis = false;
		dfs(from, colors[from], colors[to], [&](int x){ vis |= x == to; });
		if(!vis){
			flip(from, to);
		}
		else{
			flip(G[u][1], G[u][3]);
		}
		c = getcolor(u);
		assert(c >= 0);
		colors[u] = c;
	}
	for(int c : colors){ printf("%d\n", c + 1); }
}

