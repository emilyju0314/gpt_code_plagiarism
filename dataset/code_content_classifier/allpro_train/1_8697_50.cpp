#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
inline T LCM(T a, T b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return a * (b / gcd(a, b));
}
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a == b) {
    printf("infinity");
    return 0;
  }
  if (a < b) {
    printf("0");
    return 0;
  }
  a -= b;
  int ans = 0;
  for (int i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      if (i > b) {
        ans++;
      }
      if (a / i != i && a / i > b) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
