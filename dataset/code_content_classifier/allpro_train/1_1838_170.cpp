#include <bits/stdc++.h>
using namespace std;
int tc;
int n;
int a[3005];
vector<int> pre[3005], suf[3005];
int main() {
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      --a[i];
    }
    for (int i = 0; i < n; i++) {
      pre[i].assign(n, 0);
      suf[i].assign(n, 0);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        pre[i][a[j]]++;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= i; j--) {
        suf[i][a[j]]++;
      }
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        ans += (long long)pre[i - 1][a[j]] * (long long)suf[j + 1][a[i]];
      }
    }
    printf("%lld\n", ans);
  }
}
