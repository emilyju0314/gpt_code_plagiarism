#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N], t[N];
int main() {
  int n;
  scanf("%d", &n);
  stack<int> s;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    t[i] = max(t[i - 1], a[i] + 1);
  }
  for (int i = n; i > 1; i--) {
    if (t[i] - t[i - 1] > 1) t[i - 1] = t[i] - 1;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += t[i] - a[i] - 1;
  printf("%lld\n", ans);
  return 0;
}
