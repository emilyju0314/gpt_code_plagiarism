#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
const int maxn = 3e5 + 7;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
void solve() {
  int n = read();
  int c1 = 0, c2 = 0;
  for (int i = 1; i <= n; ++i) {
    int a = read();
    if (a & 1)
      c1++;
    else
      c2++;
  }
  if (c1 && c2)
    printf("NO\n");
  else
    printf("YES\n");
}
int main() {
  int T = read();
  while (T--) solve();
}
