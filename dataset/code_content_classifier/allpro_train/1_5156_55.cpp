#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int b[N];
map<long long, int> m;
int main() {
  int n;
  scanf("%d", &n);
  m.clear();
  int tot = 0, x;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (m[x])
      m[x]++;
    else {
      m[x] = 1;
      b[tot++] = x;
    }
  }
  long long ans = 0;
  for (int i = 0; i < tot; ++i) {
    for (int j = 1; j <= 32; ++j) {
      long long v = 1;
      for (int k = 1; k <= j; ++k) v *= 2;
      long long need = v - b[i];
      if (need <= 0) continue;
      if (need == b[i]) {
        ans += (1ll * m[need] * (m[need] - 1));
        continue;
      }
      ans += 1ll * m[need] * m[b[i]];
    }
  }
  printf("%I64d\n", ans / 2);
  return 0;
}
