#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000007;
const long long INFL = 1000000000000000007;
const long double INFS = 0.00000001;
const long long MOD = 1000000007;
const long double PI = 3.14159265;
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int dir2[8][2] = {{1, 1},  {1, 0},  {1, -1}, {0, 1},
                        {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
long long min(long long x, long long y) { return x < y ? x : y; }
long long minr(vector<long long> x) {
  long long Min = INFL;
  for (auto i : x) Min = min(Min, i);
  return Min;
}
long long max(long long x, long long y) { return x > y ? x : y; }
long long maxr(vector<long long> x) {
  long long Max = -INFL;
  for (auto i : x) Max = max(Max, i);
  return Max;
}
void ex_gcd(long long a, long long b, long long &d, long long &x,
            long long &y) {
  if (!b)
    d = a, x = 1, y = 0;
  else
    ex_gcd(b, a % b, d, y, x), y -= x * (a / b);
}
long long modinv(long long x) {
  long long ret, tr1, tr2;
  ex_gcd(x, MOD, tr1, ret, tr2);
  while (ret < 0) ret += MOD;
  return ret;
}
pair<pair<int, int>, int> a[200001];
set<pair<int, int> > val;
bool ansone = true;
int ans[2][200001];
struct node {
  int l, r;
  int lc, rc;
  int i;
};
node seg[1000001];
void add(int p, int l, int r, int d) {
  if (seg[p].l >= l && seg[p].r <= r) {
    seg[p].i += d;
  } else {
    if (l < (seg[p].l + seg[p].r) / 2) add(seg[p].lc, l, r, d);
    if (r > (seg[p].l + seg[p].r) / 2) add(seg[p].rc, l, r, d);
    int x = seg[p].lc, y = seg[p].rc;
    seg[p].i = min(seg[x].i, seg[y].i);
  }
}
int mini(int p, int l, int r) {
  if (seg[p].l >= l && seg[p].r <= r)
    return seg[p].i;
  else {
    int ret = INF;
    if (l < (seg[p].l + seg[p].r) / 2) ret = min(ret, mini(seg[p].lc, l, r));
    if (r > (seg[p].l + seg[p].r) / 2) ret = min(ret, mini(seg[p].rc, l, r));
    return ret;
  }
}
void build(int p, int l, int r) {
  seg[p].l = l, seg[p].r = r;
  seg[p].lc = 0, seg[p].rc = 0;
  seg[p].i = 0;
  if (l + 1 < r) {
    seg[p].lc = 2 * p, seg[p].rc = 2 * p + 1;
    build(2 * p, l, (l + r) / 2);
    build(2 * p + 1, (l + r) / 2, r);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  int i, j;
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> a[i].first.first >> a[i].first.second, a[i].second = i;
  sort(a + 1, a + n + 1);
  build(1, 1, n + 1);
  int cur = 1;
  for (i = 1; i <= n; i++) {
    while (cur <= n && a[cur].first.first <= i)
      val.insert({a[cur].first.second, cur}), cur++;
    int f = val.begin()->second;
    val.erase(val.begin());
    ans[0][a[f].second] = i, ans[1][a[f].second] = i;
    add(1, i, i + 1, a[f].first.first);
  }
  for (i = 1; i <= n; i++) {
    int pos1 = ans[0][a[i].second];
    if (a[i].first.second > pos1 &&
        mini(1, pos1 + 1, a[i].first.second + 1) <= pos1) {
      for (j = 1; j <= n; j++) {
        int pos2 = ans[0][a[j].second];
        if (j != i && pos2 > pos1 && pos2 <= a[i].first.second &&
            a[j].first.first <= pos1) {
          int t = ans[1][a[i].second];
          ans[1][a[i].second] = ans[1][a[j].second];
          ans[1][a[j].second] = t;
          break;
        }
      }
      ansone = false;
      break;
    }
  }
  if (ansone) {
    cout << "YES" << endl;
    for (i = 1; i < n; i++) cout << ans[0][i] << " ";
    cout << ans[0][n] << endl;
  } else {
    cout << "NO" << endl;
    for (i = 1; i < n; i++) cout << ans[0][i] << " ";
    cout << ans[0][n] << endl;
    for (i = 1; i < n; i++) cout << ans[1][i] << " ";
    cout << ans[1][n] << endl;
  }
  return 0;
}
