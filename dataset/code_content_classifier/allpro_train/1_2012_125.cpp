#include <bits/stdc++.h>
using namespace std;
struct ts {
  int x;
  int n, t;
  ts(int x, int t, int n) : x(x), t(t), n(n){};
};
bool operator<(const ts &a, const ts &b) {
  if (a.x < b.x) return true;
  if (a.x > b.x) return false;
  return (a.t < b.t);
}
double binpow(double a, int n) {
  double res = 1.0;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
int n, m;
vector<ts> lf, rf;
vector<pair<int, int> > pr;
vector<int> pows;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a, h, l, r;
    cin >> a >> h >> l >> r;
    lf.push_back(ts(a - h, 0, i));
    lf.push_back(ts(a, 1, i));
    rf.push_back(ts(a + h, 1, i));
    rf.push_back(ts(a, 0, i));
    pr.push_back(make_pair(l, r));
  }
  for (int i = 0; i < m; i++) {
    int b, z;
    cin >> b >> z;
    lf.push_back(ts(b, 5, i));
    rf.push_back(ts(b, -3, i));
    pows.push_back(z);
  }
  double sum[10010];
  for (int i = 0; i < m; i++) sum[i] = 1.0;
  sort(lf.begin(), lf.end());
  int cnt[101];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < lf.size(); i++) {
    int t = lf[i].n;
    if (lf[i].t == 0)
      ++cnt[100 - pr[t].first];
    else if (lf[i].t == 1)
      --cnt[100 - pr[t].first];
    else
      for (int k = 0; k <= 100; k++)
        if (cnt[k] > 0) sum[t] *= binpow(k / 100.0, cnt[k]);
  }
  sort(rf.begin(), rf.end());
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < rf.size(); i++) {
    int t = rf[i].n;
    if (rf[i].t == 0)
      ++cnt[100 - pr[t].second];
    else if (rf[i].t == 1)
      --cnt[100 - pr[t].second];
    else
      for (int k = 0; k <= 100; k++)
        if (cnt[k] > 0) sum[t] *= binpow(k / 100.0, cnt[k]);
  }
  double res = 0;
  for (int i = 0; i < m; i++) res += sum[i] * pows[i];
  cout << fixed << setprecision(5) << res << endl;
}
