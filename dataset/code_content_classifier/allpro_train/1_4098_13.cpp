#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T &x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T &x, L y) {
  return x > y ? (x = y, 1) : 0;
}
const int maxn = 1e6 + 17;
int n, nq;
long long ans[maxn];
pair<int, int> a[maxn];
set<int> pos;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i].first), a[i].second = i;
  sort(a, a + n);
  pos.insert(-1), pos.insert(n);
  for_each(a, a + n, [](pair<int, int> &x) {
    auto it = pos.lower_bound(x.second);
    int r = *it - x.second, l = x.second - *--it;
    pos.insert(x.second);
    ans[1] += x.first, ans[l + r + 1] += x.first;
    ans[l + 1] -= x.first, ans[r + 1] -= x.first;
  });
  for (int t = 0; t < 2; t++)
    for (int i = 1; i <= n; i++) ans[i] += ans[i - 1];
  scanf("%d", &nq);
  for (int k; nq--;)
    scanf("%d", &k), printf("%.9f\n", (double)ans[k] / (n - k + 1));
  return 0;
}
