#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  size_t n = 0, m = 0;
  uint16_t k = 0, s = 0;
  std::cin >> n >> m >> k >> s;
  std::vector<std::vector<uint32_t>> goods(k);
  for (size_t i = 0; i < n; i++) {
    uint16_t t = 0;
    std::cin >> t;
    goods[t - 1].emplace_back(i);
  }
  std::vector<std::vector<uint32_t>> roads(n);
  for (size_t i = 0; i < m; i++) {
    size_t a = 0, b = 0;
    std::cin >> a >> b;
    roads[a - 1].emplace_back(b - 1);
    roads[b - 1].emplace_back(a - 1);
  }
  std::vector<std::array<uint32_t, 100>> dp(n);
  std::queue<std::pair<uint32_t, uint16_t>> queue;
  const auto visit_good = [&dp, &roads, &goods,
                           &queue](const uint16_t good_type) {
    for (const auto road_to : goods[good_type]) {
      queue.emplace(road_to, 1);
    }
    while (!queue.empty()) {
      const auto& p = queue.front();
      if (!dp[p.first][good_type]) {
        dp[p.first][good_type] = p.second;
        for (const auto road_to : roads[p.first]) {
          queue.emplace(road_to, p.second + 1);
        }
      }
      queue.pop();
    }
  };
  for (uint16_t i = 0; i < k; i++) {
    visit_good(i);
  }
  for (auto& l : dp) {
    std::sort(l.begin(), l.begin() + k);
    auto ret =
        std::accumulate(l.begin(), l.begin() + s, 0, std::plus<uint32_t>());
    printf("%u ", ret - s);
  }
  putchar('\n');
  return 0;
}
