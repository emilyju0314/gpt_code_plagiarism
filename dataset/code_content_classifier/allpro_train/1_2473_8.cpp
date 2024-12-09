#include <bits/stdc++.h>
using namespace std;
const int MX = 1200000;
long long pri[MX + 9], pal[MX + 9];
bool isprime[MX + 9];
long long gcd(long long u, long long v) {
  long long t;
  while (v) {
    t = u;
    u = v;
    v = t % v;
  }
  return u;
}
int ipal(int o) {
  char x[64];
  int i = 0;
  while (o) {
    x[i++] = o % 10;
    o /= 10;
  }
  for (int u = 0, v = i - 1; u < v; u++, v--)
    if (x[u] != x[v]) return 0;
  return 1;
}
void initialize() {
  memset(pal, 0, sizeof(pal));
  for (int i = 1; i <= MX; i++) pal[i] = pal[i - 1] + ipal(i);
  memset(pri, 0, sizeof(pri));
  memset(isprime, 0, sizeof(isprime));
  isprime[0] = isprime[1] = 1;
  for (int i = 2; i <= MX; i++)
    if (!isprime[i])
      for (int j = 2; i * j <= MX; j++) isprime[i * j] = 1;
  for (int i = 1; i <= MX; i++) {
    pri[i] = pri[i - 1];
    if (!isprime[i]) pri[i]++;
  }
}
int main() {
  int i, a, b;
  initialize();
  scanf("%d%d", &a, &b);
  for (i = MX; i; i--) {
    long long x = gcd(pri[i], pal[i]);
    if ((pri[i] / x) * b <= a * (pal[i] / x)) break;
  }
  printf("%d\n", i);
  return 0;
}
