#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline bool chkmin(T1 &x, T2 y) {
  return y < x ? (x = y, true) : false;
};
template <typename T1, typename T2>
inline bool chkmax(T1 &x, T2 y) {
  return y > x ? (x = y, true) : false;
};
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 2e5 + 10;
long long ans[N];
mt19937 gen;
long long rt = -1;
struct nd {
  long long k, sz;
  long long l, r;
  long long pr;
  nd(long long _k = 0) : k(_k), sz(1), l(-1), r(-1), pr(gen()) {}
};
nd t[N];
void upd(long long v) {
  if (v == -1) return;
  t[v].sz = 1;
  if (t[v].l != -1) t[v].sz += t[t[v].l].sz;
  if (t[v].r != -1) t[v].sz += t[t[v].r].sz;
}
long long cnt = 0;
void split(long long v, long long &l, long long &r, long long x) {
  if (v == -1) {
    l = r = -1;
    return;
  }
  if (t[v].k < x) {
    split(t[v].r, t[v].r, r, x);
    l = v;
    upd(l);
  } else {
    split(t[v].l, l, t[v].l, x);
    r = v;
    upd(r);
  }
}
long long merge(long long l, long long r) {
  if (l == -1) return r;
  if (r == -1) return l;
  if (t[l].pr > t[r].pr) {
    t[l].r = merge(t[l].r, r);
    upd(l);
    return l;
  } else {
    t[r].l = merge(l, t[r].l);
    upd(r);
    return r;
  }
}
long long get(long long v, long long k) {
  if (v == -1) exit(-1);
  long long lsz = 0;
  if (t[v].l != -1) lsz = t[t[v].l].sz;
  if (lsz > k) {
    return get(t[v].l, k);
  }
  k -= lsz;
  if (k == 0) return t[v].k;
  k--;
  return get(t[v].r, k);
}
void add(long long i) {
  long long nv = cnt++;
  t[nv] = nd(i);
  long long l = -1, r = -1;
  split(rt, l, r, i);
  rt = merge(merge(l, nv), r);
}
struct query {
  long long k, pos, i;
};
bool comp1(query q1, query q2) { return q1.k < q2.k; }
bool comp2(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first > b.first || (a.first == b.first && a.second < b.second);
}
void print(long long v = rt) {
  if (v == -1) return;
  print(t[v].l);
}
long long a[N];
pair<long long, long long> b[N];
signed main() {
  srand(time(0));
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = make_pair(a[i], i);
  }
  sort(b, b + n, comp2);
  long long m;
  cin >> m;
  vector<query> qq;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    qq.push_back({x, y - 1, i});
  }
  sort(qq.begin(), qq.end(), comp1);
  long long curlen = 0;
  for (long long i = 0; i < m; i++) {
    while (curlen < qq[i].k) {
      add(b[curlen].second);
      curlen++;
    }
    ans[qq[i].i] = get(rt, qq[i].pos);
  }
  for (long long i = 0; i < m; i++) {
    cout << a[ans[i]] << '\n';
  }
  return 0;
}
