#include <bits/stdc++.h>
using namespace std;
int sign[5000];
int main() {
  int n, v;
  scanf("%d%d", &n, &v);
  int a, b;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    sign[a] += b;
  }
  int ans = 0;
  for (int i = 1; i < 5000; i++) {
    int tmp = v;
    if (sign[i - 1] > 0) {
      ans += min(sign[i - 1], tmp);
      tmp -= min(sign[i - 1], tmp);
    }
    if (tmp > 0) {
      ans += min(sign[i], tmp);
      sign[i] -= min(sign[i], tmp);
    }
  }
  printf("%d", ans);
  return 0;
}
