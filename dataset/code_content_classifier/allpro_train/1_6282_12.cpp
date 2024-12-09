#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
pair<int, int> a[maxN];
pair<int, int> b[maxN];
string s[maxN];
int c[maxN];
int n, m;
string tmp;
int cm;
inline bool cmp(pair<int, int> x, pair<int, int> y) {
  if (x.first == y.first) return (s[x.second] > s[y.second]);
  return (x.first < y.first);
}
inline int solve1() {
  for (int i = 0; i < n; i++) b[i] = a[i];
  for (int i = 0; i < n; i++)
    if (b[i].second == cm) b[i].first += c[0];
  int st = 0, cnt = 1;
  while (cnt < m) {
    if (b[st].second == cm) {
      st++;
      continue;
    }
    b[st].first += c[cnt];
    st++;
    cnt++;
  }
  sort(b, b + n, cmp);
  for (int i = 0; i < n; i++)
    if (b[i].second == cm) return n - i;
}
inline bool check(int t) {
  for (int i = 0; i < n; i++) b[i] = a[i];
  int ps = 0;
  for (int i = 0; i < n; i++)
    if (b[i].second == cm) ps = i;
  if (ps - t > m) return false;
  int st = 0;
  for (int i = t; i < ps; i++) b[i].first += c[st++];
  for (int i = 0; i < t && st < m; i++) b[i].first += c[st++];
  for (int i = ps + 1; i < n && st < m; i++) b[i].first += c[st++];
  if (st < m) b[ps].first += c[m - 1];
  sort(b, b + n, cmp);
  for (int i = 0; i <= t; i++)
    if (b[i].second == cm) return true;
  return false;
}
inline int solve2() {
  int hi = 0, lo = -1;
  for (int i = 0; i < n; i++)
    if (a[i].second == cm) hi = i;
  while (hi - lo > 1) {
    int mid = (hi + lo) >> 1;
    if (check(mid))
      hi = mid;
    else
      lo = mid;
  }
  return n - hi;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i] >> a[i].first, a[i].second = i;
  sort(a, a + n, cmp);
  cin >> m;
  for (int i = 0; i < m; i++) cin >> c[i];
  sort(c, c + m, greater<int>());
  cin >> tmp;
  for (int i = 0; i < n; i++)
    if (s[a[i].second] == tmp) cm = a[i].second;
  cout << solve1() << ' ' << solve2() << endl;
  return 0;
}
