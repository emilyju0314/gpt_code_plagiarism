#include <bits/stdc++.h>
int main() {
  int n, x1, x2;
  scanf("%d %d %d", &n, &x1, &x2);
  std ::vector<std::pair<int, int> > c(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i].first);
    c[i].second = i;
  }
  std ::sort(c.begin(), c.end());
  for (int rev = 0; rev < 2; rev++) {
    for (int i = 0; i < n; i++) {
      int sa = (x1 + c[i].first - 1) / c[i].first;
      if (i + sa >= n) continue;
      int sb = (x2 + c[i + sa].first - 1) / c[i + sa].first;
      if (i + sa + sb - 1 >= n) continue;
      printf("Yes\n");
      std ::vector<int> a, b;
      for (int j = 0; j < sa; j++) a.push_back(c[i + j].second);
      for (int j = 0; j < sb; j++) b.push_back(c[i + sa + j].second);
      if (rev) swap(a, b);
      std ::sort(a.begin(), a.end());
      std ::sort(b.begin(), b.end());
      printf("%d %d\n", (int)(a.size()), (int)(b.size()));
      for (auto e : a) printf("%d ", e + 1);
      printf("\n");
      for (auto e : b) printf("%d ", e + 1);
      return 0;
    }
    std ::swap(x1, x2);
  }
  printf("No");
  return 0;
}
