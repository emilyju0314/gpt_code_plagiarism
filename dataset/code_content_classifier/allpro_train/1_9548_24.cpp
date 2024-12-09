#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
pair<int, long long> a[200001];
bool vis[200001];
struct get1 {
  int l, r, id;
  long long val;
  get1() {}
  get1(int l, int r, int id, long long val) : l(l), r(r), id(id), val(val) {}
} b[200001];
int f[2][200001], pr[2][200001], res[200001];
vector<int> str[2][200001];
bool check(long long s, int l, int r) {
  if (s <= 0) return !s && r - l + 1 >= 0;
  long long L = 1, R = r - l + 1, mid, ans = 0;
  while (L <= R) {
    mid = (L + R) >> 1;
    if ((l + l + mid - 1) * mid <= s * 2)
      ans = mid, L = mid + 1;
    else
      R = mid - 1;
  }
  return s * 2 <= (r + r - ans + 1) * ans;
}
void change(long long s, int l, int r, vector<int> &tar, int start) {
  long long L = 1, R = r - l + 1, mid, ans = 0;
  while (L <= R) {
    mid = (L + R) >> 1;
    if ((l + l + mid - 1) * mid <= s * 2)
      ans = mid, L = mid + 1;
    else
      R = mid - 1;
  }
  for (int i = l; i <= r; i++)
    if (ans && (i + i + ans - 2) * (ans - 1) <= (s - i) * 2 &&
        (s - i) * 2 <= (r + r - ans + 2) * (ans - 1)) {
      ans--;
      s -= i;
      tar.push_back(1);
    } else
      tar.push_back(0);
}
void update(int i, int ti, int ti_1, int pos, long long d) {
  if (pos <= f[ti][i]) return;
  str[ti][i].clear();
  f[ti][i] = pos;
  pr[ti][i] = ti_1;
  str[ti][i].push_back(1);
  for (int j = f[ti][i] + 1; j <= b[i].r; j++) str[ti][i].push_back(0);
  change(d - f[ti][i], b[i].r + 1, f[ti_1][i - 1] - 1, str[ti][i], f[ti][i]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long y;
    scanf("%lld", &y);
    if (!y) continue;
    a[++m] = make_pair(n - i + 1, y);
    vis[n - i + 1] = 1;
  }
  if (!m) {
    for (int i = 1; i <= n; i++) putchar('0');
    return 0;
  }
  sort(a + 1, a + m + 1);
  b[cnt = 1] = get1(a[m].first, a[m].first, 2, a[m].second);
  for (int i = m - 1; i; i--) {
    if (a[i].second == a[i + 1].second)
      b[cnt].l = a[i].first, b[cnt].id = 0;
    else if (a[i].second == a[i + 1].second - 1)
      b[cnt].l = a[i].first, b[cnt].id = 1, b[cnt].val--;
    else
      b[++cnt] = get1(a[i].first, a[i].first, 2, a[i].second);
  }
  b[cnt + 1] = get1(-1, -1, 0, 0);
  bool error = 0;
  f[0][0] = -1;
  f[1][0] = n + 1;
  for (int i = 1; i <= cnt; i++) {
    f[0][i] = f[1][i] = -1;
    for (int t = 0; t <= 1; t++)
      if (f[t][i - 1] > b[i].r) {
        if (b[i].id == 0 || b[i].id == 2) {
          long long d = (b[i].val - 1) - (b[i - 1].val - 1 + t);
          int pos = -1;
          for (int j = min(b[i].l - 1ll, d); j > b[i + 1].r; --j)
            if (check(d - j, b[i].r + 1, f[t][i - 1] - 1)) {
              pos = j;
              break;
            }
          update(i, 0, t, pos, d);
        }
        if (b[i].id == 1 | b[i].id == 2) {
          long long d = b[i].val - (b[i - 1].val - 1 + t);
          if (check(d - b[i].l, b[i].r + 1, f[t][i - 1] - 1))
            update(i, 1, t, b[i].l, d);
        }
      }
    if (f[0][i] < 0 && f[1][i] < 0 && i == cnt && !b[i].id) error = 1;
  }
  if (error) {
    for (int t = 0; t <= 1; t++)
      if (f[t][cnt - 1] > b[cnt].r) {
        long long d = (b[cnt].val - 1) - (b[cnt - 1].val - 1 + t);
        int pos = -1;
        for (int j = min((long long)b[cnt].r, d); j >= b[cnt].l; --j) {
          if (vis[j]) continue;
          if (check(d - j, b[cnt].r + 1, f[t][cnt - 1] - 1)) {
            pos = j;
            break;
          }
        }
        update(cnt, 0, t, pos, d);
      }
  }
  int cur = (f[1][cnt] > 0);
  for (int i = 1; i < f[cur][cnt]; i++) res[i] = 0;
  for (int i = cnt; i > 0; i--) {
    for (int j = 0; j < (int)str[cur][i].size(); j++)
      res[j + f[cur][i]] = str[cur][i][j];
    cur = pr[cur][i];
  }
  for (int i = n; i > 0; i--) putchar(res[i] + '0');
  return 0;
}
