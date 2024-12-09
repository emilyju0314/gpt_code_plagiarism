#include <bits/stdc++.h>
const int MAXN = 1e3 + 10;
int n;
namespace solver1 {
std::vector<int> query(const std::vector<int>& v) {
  printf("%lu\n", v.size());
  for (auto i : v) {
    printf("%d ", i);
  }
  printf("\n");
  fflush(stdout);
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ans[i]);
  }
  return ans;
}
void main() {
  static int ans[MAXN];
  memset(ans, 63, sizeof ans);
  for (int i = 9; i >= 0; i--) {
    std::vector<int> v1, v2;
    for (int j = 1; j <= n; j++) {
      if (j & (1 << i))
        v1.push_back(j);
      else
        v2.push_back(j);
    }
    if (v1.empty() || v2.empty()) continue;
    auto ans1 = query(v1);
    for (auto i : v2) {
      ans[i] = std::min(ans[i], ans1[i]);
    }
    auto ans2 = query(v2);
    for (auto i : v1) {
      ans[i] = std::min(ans[i], ans2[i]);
    }
  }
  puts("-1");
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  fflush(stdout);
}
}  // namespace solver1
int main() {
  scanf("%d", &n);
  solver1::main();
}
