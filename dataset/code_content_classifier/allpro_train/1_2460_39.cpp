#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const int inf = 0x3f3f3f3f;
int memo[1000005];
inline int go(int n) {
  if (n == 0) return 0;
  int &ret = memo[n];
  if (ret != -1) return ret;
  int y = min(n - 1, (int)sqrt(n));
  int x = pow(n, 1.0 / 4);
  if (x * x * x * x < n) ++x;
  bool arr[200];
  memset(arr, 0, sizeof arr);
  for (int i = (x), __ = (y + 1); i < __; ++i) arr[go(i)] = 1;
  ret = 0;
  while (arr[ret]) ++ret;
  return ret;
}
int mark[1000005], passo = 0;
int calc(int x, int y) {
  if (x >= 6724) return 0;
  if (x >= 82) {
    if (y <= 50625) return 1;
    return 2;
  }
  if (x >= 16) {
    if (y <= 81) return 0;
    if (y <= 50625) return 1;
    return 4;
  }
  if (x >= 4) {
    if (y <= 81) return 0;
    if (y <= 6723) return 3;
    return 4;
  }
  if (y <= 3) return 1;
  if (y <= 15) return 2;
  if (y <= 6723) return 3;
  return 4;
}
int main() {
  memset(memo, -1, sizeof memo);
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = (0), __ = (n); i < __; ++i) {
    long long a;
    cin >> a;
    long long y = min(a - 1, (long long)sqrt(a));
    long long x = pow(a, 1.0 / 4);
    if (x * x * x * x != a) ++x;
    int _xor = 0;
    if (x <= y) _xor = calc(x, y);
    ans ^= _xor;
  }
  if (ans)
    puts("Furlo");
  else
    puts("Rublo");
  return 0;
}
