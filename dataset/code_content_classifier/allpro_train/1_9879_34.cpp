#include <bits/stdc++.h>
using namespace std;
const int RLEN = 1 << 20 | 1;
inline char gc() {
  static char ibuf[RLEN], *ib, *ob;
  (ob == ib) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ob == ib) ? EOF : *ib++;
}
inline int read() {
  char ch = getchar();
  int res = 0, f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = getchar();
  return f ? res : -res;
}
template <class tp>
inline void chemx(tp &a, tp b) {
  a < b ? a = b : 0;
}
template <class tp>
inline void chemn(tp &a, tp b) {
  a > b ? a = b : 0;
}
const int N = 300005;
struct line {
  int l, r, id;
  line(int _l = 0, int _r = 0, int _i = 0) : l(_l), r(_r), id(_i) {}
  friend inline bool operator<(const line &a, const line &b) {
    return a.l == b.l ? (a.r == b.r ? a.id < b.id : a.r < b.r) : a.l < b.l;
  }
};
set<line> st;
set<line>::iterator it;
vector<pair<int, int> > p[N];
int n, K, a[N], b[N], len[N];
inline void init() {
  st.insert(line(0, 1e9, 0));
  for (int i = 1; i <= n; i++) {
    it = st.lower_bound(line(a[i], 1e9, 0));
    it--;
    if (it->r >= b[i]) {
      p[i].push_back(pair<int, int>(b[i] - a[i] + 1, it->id));
      if (it->l < a[i]) st.insert(line(it->l, a[i] - 1, it->id));
      if (it->r > b[i]) st.insert(line(b[i] + 1, it->r, it->id));
      st.insert(line(a[i], b[i], i));
      st.erase(it);
    } else {
      p[i].push_back(pair<int, int>(it->r - a[i] + 1, it->id));
      if (it->l < a[i]) st.insert(line(it->l, a[i] - 1, it->id));
      st.erase(it++);
      if (it->r < a[i]) it++;
      while (it->r < b[i])
        p[i].push_back(pair<int, int>(it->r - it->l + 1, it->id)),
            st.erase(it++);
      p[i].push_back(pair<int, int>(b[i] - it->l + 1, it->id));
      if (it->r > b[i]) st.insert(line(b[i] + 1, it->r, it->id));
      st.erase(it), st.insert(line(a[i], b[i], i));
    }
  }
}
inline bool check(int mid) {
  long long res = 0, num = 0;
  for (int i = 1; i <= n; i++) len[i] = b[i] - a[i] + 1;
  for (int i = 1, l = 1; i <= n; i++) {
    res += len[i];
    for (pair<int, int> &x : p[i]) {
      len[x.second] -= x.first;
      if (x.second >= l) res -= x.first;
    }
    while (res >= mid) res -= len[l++];
    num += l - 1;
  }
  return num >= K;
}
inline long long calc(int mid) {
  long long res = 0, num = 0, coef = 0, tot = 0;
  for (int i = 1; i <= n; i++) len[i] = b[i] - a[i] + 1;
  for (int i = 1, l = 1; i <= n; i++) {
    res += len[i];
    for (pair<int, int> &x : p[i]) {
      len[x.second] -= x.first;
      if (x.second >= l) res -= x.first;
      if (x.second && x.second < l) coef -= 1ll * x.second * x.first;
    }
    while (res >= mid) res -= len[l], coef += 1ll * l * len[l], l++;
    tot += coef + res * (l - 1), num += l - 1;
  }
  return tot - 1ll * mid * (num - K);
}
int main() {
  n = read(), K = read();
  for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read() - 1;
  init();
  int l = 1, r = 1e9, res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1, res = mid;
    else
      r = mid - 1;
  }
  cout << calc(res) << '\n';
}
