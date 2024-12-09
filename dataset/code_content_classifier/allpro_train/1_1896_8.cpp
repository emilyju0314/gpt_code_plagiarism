#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>


using usize = std::size_t;
using i64 = std::int_fast64_t;

constexpr i64 Minf = std::numeric_limits<i64>::min() / 5;

struct segtree {
  std::vector<i64> c;

  segtree() = default;
  segtree(usize n) : c(n * 2, Minf) {}

  void set(usize i, i64 v) {
    i += c.size() / 2;
    c[i] = std::max(c[i], v);
    while (i != 1) {
      i /= 2;
      c[i] = std::max(c[i * 2], c[i * 2 + 1]);
    }
  }

  i64 get(usize l, usize r) const {
    i64 ret = Minf;
    l += c.size() / 2;
    r += c.size() / 2;
    while (l < r) {
      if (l % 2 == 1) {
        ret = std::max(ret, c[l]);
        l += 1;
      }
      l /= 2;
      if (r % 2 == 1) {
        r -= 1;
        ret = std::max(ret, c[r]);
      }
      r /= 2;
    }
    return ret;
  }

  void dump() const {
    for (usize i = 0; i < c.size() / 2; ++i) {
      std::cout << c[i + c.size() / 2] << ' ';
    }
    std::cout << std::endl;
  }
};

int main() {
  usize n, m;
  std::cin >> n >> m;
  i64 x, y;
  std::cin >> x >> y;

  struct inter_t {
    usize c;
    usize r;
  };
  std::vector<std::vector<inter_t>> is;
  std::vector<i64> zip;

  struct interval_t {
    usize c;
    i64 l, r;
  };
  std::vector<interval_t> intervals(m);
  for (auto& e : intervals) {
    std::cin >> e.c >> e.l >> e.r;
    --e.c;
    --e.l;
    zip.push_back(e.l);
    zip.push_back(e.r);
  }
  std::sort(zip.begin(), zip.end());
  zip.erase(std::unique(zip.begin(), zip.end()), zip.end());
  n = zip.size();
  const auto rzip = [&](const i64 x) -> usize {
    return std::lower_bound(zip.cbegin(), zip.cend(), x) - zip.cbegin();
  };
  is.resize(n);
  for (const auto& e : intervals) {
    is[rzip(e.l)].push_back({ e.c, rzip(e.r) });
  }

  std::array<segtree, 3> dp, dps;
  i64 curmax = Minf;
  for (usize i = 0; i < 3; ++i) {
    dp[i] = segtree(n);
    dps[i] = segtree(n);
    dp[i].set(0, -(x + x + y) * zip[0]);
    dps[i].set(0, -x * zip[0]);
  }
  for (usize i = 0; i < n; ++i) {
    for (usize d = 0; d < 3; ++d) {
      curmax = std::max(curmax, dps[d].get(i, i + 1) + x * zip[i]);
    }
    for (const auto& e : is[i]) {
      {
        const i64 t = curmax + x * (zip[e.r] - zip[i]);
        dp[e.c].set(e.r, t - (x + x + y) * zip[e.r]);
        dps[e.c].set(e.r, t - x * zip[e.r]);
      }
      for (usize d = 0; d < 3; ++d) {
        if (e.c == d) {
          const i64 t =
            dps[d].get(i, e.r + 1) + x * zip[i] + x * (zip[e.r] - zip[i]);
          dp[e.c].set(e.r, t - (x + x + y) * zip[e.r]);
          dps[e.c].set(e.r, t - x * zip[e.r]);
        }
        else {
          const i64 t = dp[d].get(i, e.r + 1) + (x + x + y) * zip[i] +
            x * (zip[e.r] - zip[i]);
          dp[e.c].set(e.r, t - (x + x + y) * zip[e.r]);
          dps[e.c].set(e.r, t - x * zip[e.r]);
        }
      }
    }
  }
  std::cout << curmax << std::endl;
  return 0;
}
