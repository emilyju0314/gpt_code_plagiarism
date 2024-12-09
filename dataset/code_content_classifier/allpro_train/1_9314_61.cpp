#include <bits/stdc++.h>
using namespace std;
template <typename T>
using pair2 = pair<T, T>;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
T sgn(T x) {
  return x > 0 ? 1 : (x < 0 ? -1 : 0);
}
const double pi = acos(-1.0);
int n;
int m;
int c[101][101];
int main() {
  int a, b;
  scanf("%d%d%d", &n, &a, &b);
  if (n > a * b) {
    printf("-1\n");
    return 0;
  }
  int cnt = 1;
  int par = (b + 1) % 2;
  for (int i = 0; i < a; i++) {
    if (par)
      for (int j = 0; j < b; j++) c[i][j] = cnt <= n ? cnt : 0, cnt++;
    else
      for (int j = b - 1; j >= 0; j--) c[i][j] = cnt <= n ? cnt : 0, cnt++;
    par ^= (b + 1) % 2;
  }
  for (int i = 0; i < a; i++, printf("\n"))
    for (int j = 0; j < b; j++) printf("%d ", c[i][j]);
  return 0;
}
