#include <bits/stdc++.h>
using namespace std;
typedef struct OBJ {
  long long price, std, beauty;
  OBJ() { price = std = beauty = 0; }
} OBJ;
typedef struct PRS {
  long long inc, pref, idx;
} PRS;
bool comp(PRS a, PRS b) { return a.inc < b.inc; }
OBJ br[100005];
PRS ar[100005];
long long n, m, val1, val2, ans[100005], temp[100005];
pair<int, int> vr1[20][100005], vr2[20][100005];
void handle(pair<int, int> ar[], long long mark[], long long l, long long r,
            long long val);
void build(long long lvl, long long idx, long long l, long long r);
void query(long long lvl, long long idx, long long l, long long r,
           long long low, long long high);
void solve(long long lvl, long long idx, long long l, long long r);
int main() {
  scanf("%lld %lld", &n, &m);
  for (int i = 0; i < n; i++) scanf("%lld", &br[i].price);
  for (int i = 0; i < n; i++) scanf("%lld", &br[i].std);
  for (int i = 0; i < n; i++) scanf("%lld", &br[i].beauty);
  for (int i = 0; i < m; i++) {
    ar[i].idx = i;
    scanf("%lld", &ar[i].inc);
  }
  for (int i = 0; i < m; i++) {
    scanf("%lld", &ar[i].pref);
  }
  sort(ar, ar + m, comp);
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < m; j++) {
      vr1[i][j] = make_pair(ar[j].inc - ar[j].pref, ar[j].idx);
      vr2[i][j] = make_pair(ar[j].inc + ar[j].pref, ar[j].idx);
    }
  build(0, 0, 0, m - 1);
  for (int i = 0; i < n; i++) {
    val1 = br[i].price - br[i].beauty;
    val2 = br[i].price + br[i].beauty;
    query(0, 0, 0, m - 1, br[i].price, br[i].std);
  }
  solve(0, 0, 0, m - 1);
  long long tot = 0;
  for (int i = 0; i < m; i++) {
    tot += temp[i];
    ans[ar[i].idx] += tot;
  }
  for (int i = 0; i < m; i++) printf("%lld ", ans[i]);
}
long long q1[20][100005], q2[20][100005];
void query(long long lvl, long long idx, long long l, long long r,
           long long low, long long high) {
  if (low <= ar[l].inc && ar[r].inc <= high) {
    temp[l] -= 1;
    temp[r + 1] += 1;
    handle(vr1[lvl], q1[lvl], l, r, val1);
    handle(vr2[lvl], q2[lvl], l, r, val2);
    return;
  }
  if (high < ar[l].inc || low > ar[r].inc) return;
  long long mid = (l + r) / 2;
  query(lvl + 1, 2 * idx + 1, l, mid, low, high);
  query(lvl + 1, 2 * idx + 2, mid + 1, r, low, high);
}
void build(long long lvl, long long idx, long long l, long long r) {
  if (l == r) {
    return;
  }
  long long mid = (l + r) / 2;
  build(lvl + 1, 2 * idx + 1, l, mid);
  build(lvl + 1, 2 * idx + 2, mid + 1, r);
  sort(vr1[lvl] + l, vr1[lvl] + r + 1);
  sort(vr2[lvl] + l, vr2[lvl] + r + 1);
}
void handle(pair<int, int> ar[], long long mark[], long long l, long long r,
            long long val) {
  long long low = l, high = r, ans = -1, mid;
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (ar[mid].first >= val) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  if (ans != -1) {
    mark[ans] += 1;
  }
}
void solve(long long lvl, long long idx, long long l, long long r) {
  long long tot = 0;
  for (int i = l; i < r + 1; i++) {
    tot += q1[lvl][i];
    ans[vr1[lvl][i].second] += tot;
  }
  tot = 0;
  for (int i = l; i < r + 1; i++) {
    tot += q2[lvl][i];
    ans[vr2[lvl][i].second] += tot;
  }
  if (l == r) return;
  long long mid = (l + r) / 2;
  solve(lvl + 1, 2 * idx + 1, l, mid);
  solve(lvl + 1, 2 * idx + 2, mid + 1, r);
}
