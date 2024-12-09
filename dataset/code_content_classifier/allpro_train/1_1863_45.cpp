#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000 * 1000;
pair<int, int> a[MaxN];
int b[MaxN];
int t[(MaxN + 2) * 4];
int sum(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v];
  int mid = (tl + tr) / 2;
  return sum(v * 2, tl, mid, l, min(r, mid)) +
         sum(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
}
void add(int v, int tl, int tr, int pos, int val) {
  if (tl == tr)
    t[v] += val;
  else {
    int mid = (tl + tr) / 2;
    if (pos <= mid)
      add(v * 2, tl, mid, pos, val);
    else
      add(v * 2 + 1, mid + 1, tr, pos, val);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) b[a[i].second] = i + 1;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    add(1, 0, n + 1, b[i], 1);
    res += sum(1, 0, n + 1, b[i] + 1, n + 1) * 1ll *
           (b[i] - 1 - sum(1, 0, n + 1, 0, b[i] - 1));
  }
  printf("%lld", res);
}
