#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, w[N], h[N], prefix[N], suffix[N];
long long cum = 0;
void build_pre() {
  for (int i = 1; i <= n; i++) prefix[i] = max(prefix[i - 1], h[i - 1]);
}
void build_suff() {
  for (int i = n; i >= 1; i--) suffix[i] = max(suffix[i + 1], h[i + 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &w[i], &h[i]);
    cum += w[i];
  }
  build_pre();
  build_suff();
  for (int i = 1; i <= n; i++)
    printf("%I64d ", (cum - w[i]) * (long long)max(suffix[i], prefix[i]));
  return 0;
}
