#include <bits/stdc++.h>
using namespace std;
template <class T>
T gi() {
  T x = 0;
  bool f = 0;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') f = 1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f ? -x : x;
}
const int N = 135;
unsigned int C[N];
unsigned int gcd(unsigned int x, unsigned int y) {
  return !y ? x : gcd(y, x % y);
}
vector<int> a, b;
unsigned int calc(int n, int m) {
  for (int i = n; i > n - m; i--) a.push_back(i);
  for (int i = 2; i <= m; i++) b.push_back(i);
  for (auto &i : a)
    for (auto &j : b) {
      int d = gcd(i, j);
      i /= d, j /= d;
    }
  unsigned int res = 1;
  for (auto i : a) res *= i;
  a.clear(), b.clear();
  return res;
}
int main() {
  int n = gi<int>(), p = gi<int>(), q = gi<int>();
  unsigned int ans = 0;
  for (int j = 0; j <= min(n - 1, p); j++) C[j] = calc(n, j);
  for (int i = 1; i <= q; i++) {
    unsigned int t = 0, z = 1;
    for (int j = 0; j <= min(n - 1, p); j++, z = z * i) t += C[j] * z;
    ans ^= t * i;
  }
  cout << ans << endl;
  return 0;
}
