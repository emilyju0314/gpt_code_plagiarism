#include <bits/stdc++.h>
template <typename T>
T Abs(T a) {
  return (a < 0 ? -a : a);
}
template <typename T>
T MAX(T a, T b) {
  return (a > b ? a : b);
}
template <typename T>
T MIN(T a, T b) {
  return (a < b ? a : b);
}
template <typename T>
T GCD(T a, T b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  char c;
  x = 0;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
using fl = float;
using db = double;
using ll = long long;
using ull = unsigned long long;
const int mx = 1000005;
const int inf = 99999999;
const int intlim = 2147483648;
const db PI = acos(-1);
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  int fs = -1, ls = 0;
  int c = 0;
  int m = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (!a[i]) {
      if (fs == -1) fs = m;
      c = MAX(c, m), m = 0;
    } else
      m++;
  }
  int x = n - 1;
  int cnt = 0;
  while (a[x--] != 0) cnt++;
  ;
  cout << MAX(fs + cnt, c) << endl;
  return 0;
}
