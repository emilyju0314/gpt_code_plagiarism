#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long y) {
  long long base = 1;
  a %= y;
  while (b) {
    if (b & 1) (base *= a) %= y;
    (a *= a) %= y;
    b >>= 1;
  }
  return base;
}
struct node {
  long long l, r;
  mutable long long v;
  node(long long L, long long R = -1, long long V = 0) : l(L), r(R), v(V) {}
  bool operator<(const node& o) const { return l < o.l; }
};
set<node> s;
set<node>::iterator split(long long pos) {
  set<node>::iterator it = s.lower_bound(node(pos));
  if (it != s.end() && it->l == pos) return it;
  --it;
  long long l = it->l, r = it->r;
  long long V = it->v;
  s.erase(it);
  s.insert(node(l, pos - 1, V));
  return s.insert(node(pos, r, V)).first;
}
void assign(long long l, long long r, long long V = 0) {
  set<node>::iterator itr = split(r + 1), itl = split(l);
  s.erase(itl, itr);
  s.insert(node(l, r, V));
}
void add(long long l, long long r, long long V) {
  set<node>::iterator itr = split(r + 1), itl = split(l);
  for (; itl != itr; ++itl) itl->v += V;
}
long long Rank(long long l, long long r, long long x) {
  vector<pair<long long, long long> > vec;
  vec.clear();
  set<node>::iterator itr = split(r + 1), itl = split(l);
  for (; itl != itr; ++itl)
    vec.push_back(pair<long long, long long>(itl->v, itl->r - itl->l + 1));
  sort(vec.begin(), vec.end());
  for (vector<pair<long long, long long> >::iterator it = vec.begin();
       it != vec.end(); ++it)
    if (x <= it->second)
      return it->first;
    else
      x -= it->second;
  return -1LL;
}
long long sum(long long l, long long r, long long x, long long y) {
  set<node>::iterator itr = split(r + 1), itl = split(l);
  long long res = 0;
  for (; itl != itr; ++itl)
    (res += (long long)power(itl->v, x, y) * (itl->r - itl->l + 1) % y) %= y;
  return res;
}
const long long N = 1e5 + 5;
long long seed, vmax, a[N];
long long l, r, x, y, n, m, op;
long long rnd() {
  long long ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}
void init() {
  op = rnd() % 4 + 1;
  l = rnd() % n + 1, r = rnd() % n + 1;
  if (l > r) swap(l, r);
  if (op == 3)
    x = rnd() % (r - l + 1) + 1;
  else
    x = rnd() % vmax + 1;
  if (op == 4) y = rnd() % vmax + 1;
}
int main() {
  scanf("%lld%lld%lld%lld", &n, &m, &seed, &vmax);
  for (long long i = 1; i <= n; ++i) {
    a[i] = rnd() % vmax + 1;
    s.insert(node(i, i, a[i]));
  }
  while (m--) {
    init();
    if (op == 1)
      add(l, r, x);
    else if (op == 2)
      assign(l, r, x);
    else if (op == 3)
      printf("%lld\n", Rank(l, r, x));
    else
      printf("%lld\n", sum(l, r, x, y));
  }
  return 0;
}
