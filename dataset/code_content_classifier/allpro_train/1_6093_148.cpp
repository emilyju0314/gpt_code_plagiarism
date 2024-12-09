#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5 + 10;
struct node {
  pair<long long, long long> val;
  long long lazy;
  node() {
    val = make_pair(0LL, 0LL);
    lazy = 0;
  }
};
node segt[4 * MAXN];
set<pair<long long, long long> > s;
vector<long long> w;
pair<long long, long long> e[MAXN];
long long l[MAXN];
long long v[MAXN];
long long r[MAXN];
void lzu(long long id) {
  segt[2 * id + 1].val.first += segt[id].lazy;
  segt[2 * id + 2].val.first += segt[id].lazy;
  segt[2 * id + 1].lazy += segt[id].lazy;
  segt[2 * id + 2].lazy += segt[id].lazy;
  segt[id].lazy = 0;
}
void update(long long id, long long L, long long R, long long l, long long r,
            pair<long long, long long> d) {
  if (L > r || R < l) {
    return;
  }
  if (L >= l && R <= r) {
    segt[id].val.first += d.first;
    segt[id].val.second += d.second;
    segt[id].lazy += d.first;
    return;
  }
  lzu(id);
  long long mid = (L + R) / 2;
  update(2 * id + 1, L, mid, l, r, d);
  update(2 * id + 2, mid + 1, R, l, r, d);
  segt[id].val = max(segt[2 * id + 1].val, segt[2 * id + 2].val);
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> l[i] >> v[i] >> r[i];
    e[i] = make_pair(v[i], i);
  }
  for (long long i = 0; i < MAXN; i++) {
    update(0, 0, MAXN - 1, i, i, make_pair(0, i));
  }
  sort(e, e + n);
  pair<pair<long long, long long>, long long> res =
      make_pair(make_pair(0, 0), 0);
  for (long long i = 0; i < n; i++) {
    long long id = e[i].second;
    set<pair<long long, long long> >::iterator d = s.begin();
    while (d != s.end() && d->first < v[id]) {
      update(0, 0, MAXN - 1, l[d->second], v[d->second], make_pair(-1, 0));
      s.erase(d);
      d = s.begin();
    }
    s.insert(make_pair(r[id], id));
    update(0, 0, MAXN - 1, l[id], v[id], make_pair(1, 0));
    res = max(res, make_pair(segt[0].val, v[id]));
  }
  for (long long i = 0; i < n; i++) {
    if (l[i] <= res.first.second && r[i] >= res.second &&
        v[i] >= res.first.second && v[i] <= res.second) {
      w.push_back(i + 1);
    }
  }
  cout << (long long)(w.size()) << endl;
  for (long long i = 0; i < w.size(); i++) {
    cout << w[i] << " ";
  }
}
