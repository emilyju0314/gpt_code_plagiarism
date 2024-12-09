#include <bits/stdc++.h>
using namespace std;
vector<long long int> b;
vector<long long int> g;
int main() {
  long long int i, j, k, l, m, n;
  scanf("%lld%lld", &n, &m);
  long long int maximum = -1, flag = 0;
  for (i = 0; i < n; i++) {
    scanf("%lld", &k);
    b.push_back(k);
    if (k > maximum) {
      maximum = k;
    }
  }
  for (i = 0; i < m; i++) {
    scanf("%lld", &k);
    g.push_back(k);
    if (k < maximum) {
      flag = 1;
    }
  }
  if (flag == 1) {
    printf("-1\n");
    return 0;
  } else {
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    long long int ans = 0, l1 = 0, l2 = -1;
    for (i = n - 1; i >= 0; i--) {
      ans += (b[i] * m);
    }
    for (i = 0; i < m; i++) {
      if (g[i] == b[n - 1]) {
        l2 = i;
        break;
      }
    }
    if (l2 != -1) {
      for (i = m - 1; i >= 0; i--) {
        ans -= b[n - 1];
        ans += g[i];
      }
    } else {
      for (i = m - 2; i >= 0; i--) {
        ans -= b[n - 1];
        ans += g[i];
      }
      ans -= b[n - 2];
      ans += g[m - 1];
    }
    printf("%lld\n", ans);
  }
}
