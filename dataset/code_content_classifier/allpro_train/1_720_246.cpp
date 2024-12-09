#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9) * 2;
const long long INF64 = (long long)(1e18);
template <class C>
inline C sqr(C x) {
  return x * x;
}
int n, x[110000], a[110000], k = 0, m;
double y;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d %lf", &x[i], &y);
  for (int i = 0; i < n; i++) {
    a[i] = 1;
    for (int j = 0; j < i; j++)
      if (x[j] <= x[i]) a[i] = max(a[i], a[j] + 1);
    k = max(k, a[i]);
  }
  printf("%d", n - k);
  return 0;
}
