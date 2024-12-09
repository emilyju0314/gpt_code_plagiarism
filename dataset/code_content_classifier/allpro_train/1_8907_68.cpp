#ifndef ___Rank_Union_Find
#define ___Rank_Union_Find

// ------ Required ------ //
#include <vector>

// ------ Class ------ //
class RankUnionFind {
private:
	std::size_t size_; std::vector<std::size_t> par, rank;
public:
	RankUnionFind() : size_(0), par(std::vector<std::size_t>()), rank(std::vector<std::size_t>()) {};
	RankUnionFind(std::size_t size__) : size_(size__) {
		par.resize(size_); rank.resize(size_);
		for (std::size_t i = 0; i < size_; i++) par[i] = i, rank[i] = 0;
	}
	std::size_t size() { return size_; }
	std::size_t root(std::size_t x) { return par[x] == x ? x : par[x] = root(par[x]); }
	bool same(std::size_t x, std::size_t y) { return root(x) == root(y); }
	void unite(std::size_t x, std::size_t y) {
		x = root(x), y = root(y);
		if (x == y) return;
		if (rank[x] < rank[y]) par[x] = y;
		else if (rank[x] == rank[y]) par[y] = x, rank[x]++;
		else par[y] = x;
	}
	bool operator==(const RankUnionFind &u) { return par == u.par; }
	bool operator!=(const RankUnionFind &u) { return par != u.par; }
};

#endif

#include <iostream>
#include <algorithm>
using namespace std;
struct Edge { int a, b, w; };
bool operator<(const Edge& e1, const Edge& e2) { return e1.w < e2.w; }
int N, M, a, b, w; Edge G[5000];
int main() {
	while (cin >> N >> M, N | M) {
		for (int i = 0; i < M; i++) cin >> G[i].a >> G[i].b >> G[i].w, G[i].a--, G[i].b--;
		sort(G, G + M);
		int ret = 999999999;
		for (int i = 0; i < M; i++) {
			int r = 0, c = 0;
			RankUnionFind uf(N);
			for (int j = i; j < M; j++) {
				if (!uf.same(G[j].a, G[j].b)) {
					uf.unite(G[j].a, G[j].b);
					r = G[j].w; c++;
				}
			}
			if (c == N - 1) ret = min(ret, r - G[i].w);
		}
		if (ret == 999999999) cout << -1 << endl;
		else cout << ret << endl;
	}
	return 0;
}