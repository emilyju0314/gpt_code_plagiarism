#include <bits/stdc++.h>
int main(int argc, char **argv) {
  unsigned m, n;
  while (std::cin >> n >> m) {
    std::vector<unsigned> vert;
    std::vector<std::vector<unsigned>> edges(n);
    unsigned x, y;
    for (unsigned i = 0; i < n; ++i) {
      std::cin >> x;
      vert.push_back(x);
    }
    unsigned total = 0;
    for (unsigned i = 0; i < m; ++i) {
      std::cin >> x >> y;
      const unsigned lower = std::min(x - 1, y - 1);
      const unsigned higher = std::max(x - 1, y - 1);
      total += std::min(vert[lower], vert[higher]);
    }
    std::cout << total << std::endl;
  }
  return 0;
}
