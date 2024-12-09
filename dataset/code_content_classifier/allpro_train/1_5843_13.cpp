#include <bits/stdc++.h>
using namespace std;
const int maxn = 100086;
struct T {
  long long key;
  int index;
  friend bool operator<(T a, T b) { return a.key < b.key; }
} dx[maxn], dy[maxn];
long long ans = 2147483647LL * 2147483647LL;
int n, k;
void calc(int l1, int r1, int l2, int r2) {
  set<int> check;
  long long tmp;
  if (l1 + r1 > k) return;
  if (l2 + r2 > k) return;
  for (int i = 1; i <= l1; i++) check.insert(dx[i].index);
  for (int i = 1; i <= l2; i++) check.insert(dy[i].index);
  for (int i = n; i >= n - r1 + 1; i--) check.insert(dx[i].index);
  for (int i = n; i >= n - r2 + 1; i--) check.insert(dy[i].index);
  if (check.size() > k) return;
  tmp = max(1LL, (dx[n - r1].key - dx[l1 + 1].key + 1) / 2) *
        max(1LL, ((dy[n - r2].key - dy[l2 + 1].key + 1) / 2));
  if (ans > tmp) ans = tmp;
}
int main() {
  int u, v, p, q;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d %d", &u, &v, &p, &q);
    dx[i] = (T){(long long)u + p, i};
    dy[i] = (T){(long long)v + q, i};
  }
  sort(dx + 1, dx + 1 + n);
  sort(dy + 1, dy + 1 + n);
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= k; j++)
      for (int l = 0; l <= k; l++)
        for (int c = 0; c <= k; c++) calc(i, j, l, c);
  cout << ans << endl;
  return 0;
}
