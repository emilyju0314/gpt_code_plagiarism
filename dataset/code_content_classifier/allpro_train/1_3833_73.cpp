#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &FF) {
  T RR = 1;
  FF = 0;
  char CH = getchar();
  for (; !isdigit(CH); CH = getchar())
    if (CH == '-') RR = -1;
  for (; isdigit(CH); CH = getchar()) FF = (FF << 1) + (FF << 3) + (CH ^ 48);
  FF *= RR;
}
template <typename T>
inline void write(T FF) {
  if (FF < 0) {
    FF *= -1, putchar('-');
  }
  if (FF > 9) write(FF / 10);
  putchar(FF % 10 + 48);
}
unsigned long long s[500010];
vector<long long> v[500010];
bool f;
long long dfs(unsigned long long x, unsigned long long y) {
  if (f) return 0;
  if (!v[x].size()) {
    if (y < s[x]) {
      f = 1;
      return 0;
    }
    return y - s[x];
  }
  unsigned long long s = 0;
  for (int i : v[x]) {
    unsigned long long z = dfs(i, y);
    if (z < 0) {
      f = 1;
      return 0;
    }
    s += z;
  }
  if (s < ::s[x]) {
    f = 1;
    return 0;
  }
  return s - ::s[x];
}
bool check(unsigned long long x) {
  f = 0;
  dfs(1, x);
  return !f;
}
signed main() {
  unsigned long long n, s = 0;
  read(n);
  for (int i = 2; i <= n; i++) {
    long long x;
    read(x);
    v[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) read(::s[i]);
  unsigned long long l = 0, r = 100188730122209;
  while (l + 1 < r) {
    unsigned long long mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (check(0))
    puts("0");
  else
    cout << r;
  return 0;
}
