#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
inline int nxt() {
  int wow;
  scanf("%d", &wow);
  return wow;
}
inline long long int lxt() {
  long long int wow;
  scanf("%lld", &wow);
  return wow;
}
int main() {
  long long int n = lxt();
  if (n < 0) n = 360 - (-n) % 360;
  n %= 360;
  if (n >= 315) {
    cout << 0 << endl;
    return 0;
  }
  int ans = n / 90;
  if (n % 90 > 45) ans++;
  cout << ans << endl;
  return 0;
}
