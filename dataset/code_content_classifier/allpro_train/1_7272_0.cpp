#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <limits>
#include <random>
#include <utility>
#include <vector>

namespace procon {
  class UnionFind {
  private:
    struct nodeinfo {
      int par;
      int rank;
      nodeinfo(int par) : par(par), rank(0) {}
    };
    std::vector<nodeinfo> node;

  public:
    UnionFind(int n) : node() {
      node.reserve(n);
      for (int i = 0; i < n; ++i) {
	node.push_back(nodeinfo(i));
      }
    }
    int root(int x) {
      if (node[x].par == x) {
	return x;
      }
      return node[x].par = root(node[x].par);
    }
    void unite(int x, int y) {
      x = root(x);
      y = root(y);
      if (x == y) {
	return;
      }
      if (node[x].rank < node[y].rank) {
	node[x].par = y;
      } else {
	node[y].par = x;
	if (node[x].rank == node[y].rank) {
	  ++node[x].rank;
	}
      }
    }
    bool is_same_set(int x, int y) { return root(x) == root(y); }
  };
}

int main(void) {
  int log_size;
  int n_query;
  int seed;
  std::cin >> log_size >> n_query >> seed;

  assert(0 <= log_size && log_size <= 30);
  assert(0 <= n_query);

  const int size = 1 << log_size;
  const int mask = size - 1;
  uint64_t res = 123456789;

  std::mt19937 mt(seed);
  procon::UnionFind uf(size);
  while (n_query--) {
    const int com = mt() & 1;
    const int x = mt() & mask;
    const int y = mt() & mask;
    if (com) {
      res = res * 17 + (uf.is_same_set(x, y) ? 1 : 0);
    } else {
      uf.unite(x, y);
    }
  }
  std::cout << res << std::endl;
  return 0;
}

