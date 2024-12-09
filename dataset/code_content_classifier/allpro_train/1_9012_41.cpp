#include <bits/stdc++.h>
using namespace std;
const int SZ = 1 << 19;
char buf[SZ], *ie = buf + SZ, *ip = ie - 1;
inline int in() {
  if (++ip == ie) fread(ip = buf, 1, SZ, stdin);
  while (*ip < '-')
    if (++ip == ie) fread(ip = buf, 1, SZ, stdin);
  register int x = *ip & 15;
  if (++ip == ie) fread(ip = buf, 1, SZ, stdin);
  while (*ip > '-') {
    x *= 10;
    x += *ip & 15;
    if (++ip == ie) fread(ip = buf, 1, SZ, stdin);
  }
  return x;
}
int c[300009];
int main() {
  register int n = in(), p;
  for (register int i = 1; i <= n; ++i) c[i] = in();
  for (p = 1; c[p] == c[n]; ++p)
    ;
  register int ans = n - p;
  for (p = n; c[p] == c[1]; --p)
    ;
  cout << max(ans, p - 1);
  return 0;
}
