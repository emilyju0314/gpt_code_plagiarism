#include <bits/stdc++.h>
using namespace std;
int a[100100], q[1000000], ql, qr, m[100100][2];
bool edge(int i, int j) { return m[i][0] == j || m[i][1] == j; }
void add(int i, int j) {
  if (m[i][0] == -1)
    m[i][0] = j;
  else
    m[i][1] = j;
}
int main() {
  int i, j, k, n, l, L, t, x = 1;
  for (i = 0; i < 100100; m[i][0] = -1, m[i][1] = -1, i++)
    ;
  for (scanf("%d%d", &n, &k), l = 0; l < k;
       scanf("%d%d", &i, &j), i--, j--, add(i, j), add(j, i), l++)
    ;
  for (i = 0; i < n; a[i] = i, i++)
    ;
  for (L = 0; L < 10000000;) {
    random_shuffle(a, a + n);
    L += n;
    ql = 0;
    qr = 0;
    for (i = 0; i < k; i++)
      if (edge(a[i], a[(i + 1) % n])) q[qr++] = i;
    for (t = 0; t < n && ql < qr;
         t++, L++, x = ((long long)x * 123121 + 412412) % 1000000007) {
      i = q[ql++];
      if (!edge(a[i], a[(i + 1) % n])) continue;
      if (x % 2) i = (i + 2) % n;
      swap(a[(i + n - 1) % n], a[i % n]);
      for (j = i - 2; j <= i; j += 2)
        if (edge(a[(j + 2 * n) % n], a[(j + 1 + 2 * n) % n]))
          q[qr++] = (j + 2 * n) % n;
    }
    if (ql == qr) break;
  }
  if (L < 10000000) {
    for (i = 0; i < k; printf("%d %d\n", a[i] + 1, a[(i + 1) % n] + 1), i++)
      if (edge(a[i], a[(i + 1) % n])) throw;
  } else
    printf("-1\n");
  return 0;
}
