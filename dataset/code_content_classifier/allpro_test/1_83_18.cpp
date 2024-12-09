#include <bits/stdc++.h>
constexpr int Block = 1e6;
constexpr int Mod[] = {998244353, 1000000007};
long long n, cnt;
std::vector<int> val[7];
int res, sum[7];
void DFS1(int d, int v) {
  val[d].emplace_back((++cnt - v + Mod[0]) % Mod[0]);
  if (d == 6) return;
  for (int c = 0; c < 10; ++c) DFS1(d + 1, v * 10 + c);
}
void DFS2(int d, long long v) {
  if (v > n) return;
  if (d != 0) {
    if (v * Block > n / 10 && (v + 1) * Block - 1 <= n) {
      for (int i = 0, p = 1; i <= 6; ++i, p *= 10) {
        int coef = (cnt - v * p % Mod[0] + Mod[0]) % Mod[0];
        auto iter =
            std::lower_bound(val[i].begin(), val[i].end(), Mod[0] - coef);
        res = (res + 1LL * coef * val[i].size() + sum[i]) % Mod[1];
        res = (res - 1LL * Mod[0] * (val[i].end() - iter) % Mod[1] + Mod[1]) %
              Mod[1];
      }
      for (int i = 0; i <= 6; ++i) cnt += val[i].size();
      return;
    }
    res = (res + (++cnt - v % Mod[0] + Mod[0]) % Mod[0]) % Mod[1];
  }
  for (int c = !d; c < 10; ++c) DFS2(d + 1, v * 10 + c);
}
int main() {
  scanf("%lld", &n);
  DFS1(0, 0);
  for (int d = 0; d <= 6; ++d) {
    std::sort(val[d].begin(), val[d].end());
    for (int x : val[d]) sum[d] = (sum[d] + x) % Mod[1];
  }
  cnt = 0;
  DFS2(0, 0);
  printf("%d\n", res);
}
