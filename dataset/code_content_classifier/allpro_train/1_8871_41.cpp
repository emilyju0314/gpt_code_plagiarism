#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int n, k, m;
long long s, arr[100009], fac[19], ans;
map<long long, map<int, int> > pm;
void f(int x, long long y, int z) {
  if (y > s or z > k) return;
  if (x > m) {
    pm[y][z]++;
    return;
  }
  if (arr[x] <= 18) f(x + 1, y + fac[arr[x]], z + 1);
  f(x + 1, y + arr[x], z);
  f(x + 1, y, z);
}
void f2(int x, long long y, int z) {
  if (y > s or z > k) return;
  if (x > n) {
    for (int i = 0; i <= k - z; i++) ans += pm[s - y][i];
    return;
  }
  if (arr[x] <= 18) f2(x + 1, y + fac[arr[x]], z + 1);
  f2(x + 1, y + arr[x], z);
  f2(x + 1, y, z);
}
int main() {
  fac[0] = 1;
  for (int i = 1; i < 19; i++) fac[i] = fac[i - 1] * i;
  scanf("%d%d%lld", &n, &k, &s);
  for (int i = 1; i <= n; i++) scanf("%lld", arr + i);
  m = (n + 1) / 2;
  f(1, 0, 0);
  f2(m + 1, 0, 0);
  printf("%lld\n", ans);
  return 0;
}
