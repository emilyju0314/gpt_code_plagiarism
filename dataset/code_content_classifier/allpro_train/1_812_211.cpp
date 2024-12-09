#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 10;
int d[mx];
int ft[mx];
void upd(int i, int v) {
  i = mx - i - 2;
  for (; i < mx; i += (i & -i)) ft[i] = max(ft[i], v);
}
int qry(int i) {
  int a = 0;
  i = mx - i - 2;
  for (; i > 0; i -= (i & -i)) a = max(a, ft[i]);
  return a;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", d + i);
  }
  int ans = 1;
  for (int i = n - 1; i >= 0; i--) {
    int fi = 1 + qry(d[i]);
    ans = max(ans, fi);
    upd(d[i], fi);
  }
  printf("%d\n", ans);
  return 0;
}
