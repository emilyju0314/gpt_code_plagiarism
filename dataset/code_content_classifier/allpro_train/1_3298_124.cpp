#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[600000], *p1, *p2;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 600000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
long long rd() {
  long long x = 0;
  char ch = nc();
  while (ch < '0' || ch > '9') ch = nc();
  while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = nc();
  return x;
}
const long long MAX_N = 5e5 + 25;
long long n, m, q;
long long cnt[MAX_N];
long long ans[MAX_N];
set<pair<long long, long long> > city;
set<pair<long long, long long> >::iterator it;
long long Fen[MAX_N];
long long num;
long long Min;
set<pair<long long, long long> > Q;
void add(long long tmp) {
  tmp++;
  for (; tmp < MAX_N; tmp += tmp & -tmp) Fen[tmp]++;
}
long long get(long long tmp) {
  long long res = 0;
  long long id = 0;
  for (long long i = 20; ~i; i--)
    if (id + (1 << i) < MAX_N && ((id >> i) & 1) == 0)
      if (res + Fen[id + (1 << i)] < tmp) {
        res += Fen[id + (1 << i)];
        id += (1 << i);
      }
  return id;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  n = rd();
  m = rd();
  q = rd();
  for (long long i = 0; i < n; i++) {
    long long tmp;
    tmp = rd();
    tmp--;
    cnt[tmp]++;
  }
  for (long long i = 0; i < q; i++) {
    long long t;
    t = rd();
    t -= n;
    Q.insert({t, i});
  }
  for (long long i = 0; i < m; i++) city.insert({cnt[i], i});
  num = 1;
  it = city.begin();
  add(it->second);
  Min = it->first;
  city.erase(it);
  while (city.size() && city.begin()->first == Min) {
    num++;
    it = city.begin();
    add(it->second);
    city.erase(it);
  }
  long long Y = 0;
  while (num != m) {
    while (Q.size() && Q.begin()->first <= Y + num) {
      it = Q.begin();
      ans[it->second] = get(it->first - Y);
      Q.erase(it);
    }
    if (!Q.size()) break;
    Y += num;
    Min++;
    while (city.size() && city.begin()->first == Min) {
      num++;
      it = city.begin();
      add(it->second);
      city.erase(it);
    }
  }
  while (Q.size()) {
    it = Q.begin();
    ans[it->second] = (((it->first - Y) % m - 1) + m) % m;
    Q.erase(it);
  }
  for (long long i = 0; i < q; i++) printf("%lld ", ans[i] + 1);
  return 0;
}
