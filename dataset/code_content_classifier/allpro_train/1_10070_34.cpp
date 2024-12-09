#include <bits/stdc++.h>
#ifdef ALGO
#include "el_psy_congroo.hpp"
#else
#define DUMP(...) 1145141919810
#define CHECK(...) (__VA_ARGS__)
#endif

const int n = 32;

struct Edge {
  int u, v, w;
};
std::vector<Edge> edges;

void add_edge(int u, int v, int w) {
  CHECK(w > 0);
  CHECK(u < v);
  edges.emplace_back(Edge{.u = u, .v = v, .w = w});
}

void solve(int l, int r) {
  int cur = l;
  r -= l;
  add_edge(1, n, l);
  l = 1;
  if (l > r) return;
  for (int i = 0; i < 20; ++i) {
    add_edge(n - 1 - i, n, 1);
    int sum = 1;
    for (int j = i - 1; j >= 0; --j) {
      add_edge(n - 1 - i, n - 1 - j, sum);
      sum += 1 << j;
    }
  }
  for (int i = 19; i >= 0; --i) if ((1 << i) <= r) {
    add_edge(1, n - 1 - i, cur);
    cur += 1 << i;
    r -= 1 << i;
  }
  CHECK(r == 0);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int l, r;
  reader >> l >> r;
  solve(l, r);

  puts("YES");
  printf("%d %d\n", n, (int)edges.size());
  for (const auto& e : edges) {
    printf("%d %d %d\n", e.u, e.v, e.w);
  }
}

