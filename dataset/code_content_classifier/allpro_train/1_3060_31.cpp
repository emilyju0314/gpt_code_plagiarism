#include <bits/stdc++.h>
using namespace std;
int N, M;
int mas[100000];
int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long cnt(long long x) {
  long long res = 0;
  while (x < M) {
    res += M - x;
    x *= 2;
  }
  return res;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%d", &mas[i]);
  int g = mas[0] - 1;
  for (int i = 1; i < N; i++) g = gcd(g, mas[i] - 1);
  while (g % 2 == 0) g /= 2;
  long long res = 0;
  for (int i = 1; i * i <= g; i++)
    if (g % i == 0) {
      int p = i;
      int q = g / i;
      res += cnt(p);
      if (q != p) res += cnt(q);
    }
  cout << res << "\n";
  return 0;
}
