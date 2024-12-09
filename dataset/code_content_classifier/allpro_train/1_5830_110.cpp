#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
struct NN {
  int l, r, t;
} nn[maxn];
int cmp(NN a, NN b) { return a.t < b.t; }
int q[maxn];
int L[maxn], R[maxn], T[maxn];
int fa[maxn];
int fin(int n) {
  if (n == fa[n]) return n;
  return fa[n] = fin(fa[n]);
}
set<pair<long long, long long> > q1, q2;
int main() {
  int n, m, i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++)
    scanf("%d%d%d", &nn[i].l, &nn[i].r, &nn[i].t), q[i] = nn[i].l,
                                                   q[i + m] = nn[i].r;
  sort(nn + 1, nn + 1 + m, cmp);
  sort(q + 1, q + 1 + m + m);
  int num = unique(q + 1, q + 1 + m + m) - q - 1;
  memset(T, -1, sizeof(T));
  for (i = 1; i <= num; i++) fa[i] = i, L[i] = q[i], R[i] = q[i + 1];
  for (i = 1; i <= m; i++) {
    j = lower_bound(q + 1, q + 1 + num, nn[i].l) - q;
    j = fin(j);
    k = lower_bound(q + 1, q + 1 + num, nn[i].r) - q;
    while (j < k) T[j] = nn[i].t, fa[j] = k, j = fin(j + 1);
  }
  long long ans = 0;
  for (i = 1; i < num; i++)
    if (T[i] >= 0) {
      if (L[i] - T[i] >= 0)
        ans += R[i] - L[i];
      else if (R[i] - T[i] > 0)
        q2.insert(make_pair(T[i] - L[i], i)), ans += R[i] - T[i];
      else
        q1.insert(make_pair(T[i] - R[i], i));
    }
  long long lz1 = 0, lz2 = 0;
  int pre = 0;
  while (n--) {
    scanf("%d", &k);
    k -= pre;
    if (k) {
      while (!q2.empty()) {
        if ((*q2.begin()).first - lz2 <= k) {
          ans += (*q2.begin()).first - lz2;
          q2.erase(q2.begin());
        } else
          break;
      }
      lz2 += k;
      ans += (q2.size() + 0ll) * k;
      while (!q1.empty()) {
        if ((*q1.begin()).first - lz1 <= k) {
          pair<long long, long long> tmp = (*q1.begin());
          q1.erase(q1.begin());
          j = tmp.second;
          long long sheng = k - tmp.first + lz1;
          if (sheng >= R[j] - L[j]) {
            ans += R[j] - L[j];
            continue;
          }
          ans += sheng;
          tmp.first = R[j] - L[j] - sheng + lz2;
          q2.insert(tmp);
        } else
          break;
      }
      lz1 += k;
    }
    pre += k;
    printf("%I64d\n", ans);
  }
}
