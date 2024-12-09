#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1e6 + 10;
long long n;
int k;
int main() {
  scanf("%lld%d", &n, &k);
  int cnt = 0;
  map<int, int, greater<int> > s;
  for (int i = 0; i <= 62; ++i)
    if (n >> i & 1) ++s[i], ++cnt;
  if (k < cnt) return puts("No"), 0;
  while (cnt < k) {
    auto t = s.begin();
    int tt = t->first;
    if (!--s[tt]) s.erase(t);
    s[tt - 1] += 2;
    ++cnt;
  }
  set<int, greater<int> > r;
  int mx = s.begin()->first;
  for (auto &t : s)
    if (t.first != mx && t.second >= 2) r.insert(t.first);
  while (r.size()) {
    int first = *r.begin();
    ++s[first + 1], s[first] -= 2;
    if (s[first] < 2) r.erase(first);
    if (first + 1 != mx && s[first + 1] >= 2) r.insert(first + 1);
    if (!s[first]) s.erase(first);
    auto t = --s.end();
    int tt = t->first;
    if (tt == first + 1) {
      --s[first + 1], s[first] += 2;
      break;
    }
    if (--s[tt] < 2 && r.count(tt)) r.erase(tt);
    if (!s[tt]) s.erase(tt);
    s[tt - 1] += 2, r.insert(tt - 1);
  }
  puts("Yes");
  for (auto &t : s) {
    while (t.second--) printf("%d ", t.first);
  }
  putchar(10);
}
