#include <bits/stdc++.h>
using namespace std;
const int N = 5e6;
int a[N], b[N], nm[N], m;
bool cl[N];
void add(int i) {
  for (; i; i >>= 1) ++a[i];
}
int main() {
  int n, k, i, j, v, u, l;
  scanf("%d%d", &n, &k);
  m = 1;
  while (m < n + k) m <<= 1;
  for (i = 0; i < N; ++i) a[i] = 0;
  for (i = k; i < n + k; ++i) {
    a[m + i] = 1;
    b[m + i] = i - k;
  }
  for (i = m - 1; i; --i) a[i] = a[i << 1] + a[(i << 1) + 1];
  for (i = 0; i < n; ++i) nm[i] = 0;
  for (i = 1; i <= n; ++i) cl[i] = 0;
  for (u = 0, l = m + k - 1; u < k; ++u) {
    scanf("%d%d", &i, &j);
    for (v = 1; v < m;) {
      --a[v];
      if (a[v << 1] >= j)
        v <<= 1;
      else {
        j -= a[v << 1];
        v = (v << 1) + 1;
      }
    }
    --a[v];
    j = b[v];
    if ((nm[j] && (nm[j] != i)) || (!nm[j] && cl[i])) {
      printf("-1\n");
      return 0;
    }
    cl[i] = 1;
    nm[j] = i;
    b[l] = b[v];
    add(l--);
  }
  for (i = 0, j = 1; i < n; ++i) {
    if (nm[i]) continue;
    while (cl[j]) ++j;
    nm[i] = j++;
  }
  for (i = 0; i < n; ++i) printf("%d ", nm[i]);
  printf("\n");
  return 0;
}
