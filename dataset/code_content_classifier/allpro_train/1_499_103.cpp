#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// ------ Class ------ //
class Graph2 {
public:
	static const long long INF = 1000000000000000000;
	int V, E; vector<vector<pair<int, long long> > > G;
	Graph2() : V(0), E(0), G(vector<vector<pair<int, long long> > >()) {}
	Graph2(int v) : V(v), E(0), G(vector<vector<pair<int, long long> > >(v)) {}
	Graph2(vector<vector<pair<int, long long> > > g) : V(g.size()), G(g) { for (int i = 0; i < g.size(); i++) E += g[i].size(); }
	int size() { return V; }
	void add1(int v1, int v2, long long w) { G[v1].push_back(make_pair(v2, w)); E++; }
	void add2(int v1, int v2, long long w) { add1(v1, v2, w); add1(v2, v1, w); }
	bool operator==(const Graph2& g) const { return G == g.G; }
	bool operator!=(const Graph2& g) const { return G != g.G; }
	vector<pair<int, long long> > operator[](int x) { return G[x]; }
	vector<long long> dist(int s) {
		priority_queue<pair<long long, int> > que; que.push(make_pair(0, s));
		vector<long long> d(V, INF); d[s] = 0;
		while (!que.empty()) {
			pair<long long, int> t = que.top(); que.pop();
			int u = t.second;
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i].first; long long e = G[u][i].second;
				if (d[v] > d[u] + e) {
					d[v] = d[u] + e;
					que.push(make_pair(-d[v], v));
				}
			}
		}
		return d;
	}
};

// ------ Main ------ //
int H, W, g; string s[100];
int main() {
	while (cin >> W >> H, H) {
		for (int i = 0; i < H; i++) cin >> s[i];
		Graph2 G(H * W + 1);
		for (int i = 0; i < H; i++) {
			for (int j = 1; j < W; j++) {
				G.add1(i * W + j - 1, i * W + j, (s[i][j - 1] == '#' && s[i][j] != '#') ? 1 : 0);
				G.add1(i * W + j, i * W + j - 1, (s[i][j - 1] != '#' && s[i][j] == '#') ? 1 : 0);
			}
		}
		for (int i = 1; i < H; i++) {
			for (int j = 0; j < W; j++) {
				G.add1(i * W + j - W, i * W + j, (s[i - 1][j] == '#' && s[i][j] != '#') ? 1 : 0);
				G.add1(i * W + j, i * W + j - W, (s[i - 1][j] != '#' && s[i][j] == '#') ? 1 : 0);
			}
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i == 0 || i + 1 == H || j == 0 || j + 1 == W) G.add1(H * W, i * W + j, 0);
				if (s[i][j] == '&') g = i * W + j;
			}
		}
		cout << G.dist(H * W)[g] << endl;
	}
}