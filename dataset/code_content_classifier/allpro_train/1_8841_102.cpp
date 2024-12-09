#include <bits/stdc++.h>
using namespace std;
const long M = 998244353;
long long dd(long x) {
  long long d = 0, he = 11;
  while (x) {
    d += he * (x % 10) % M;
    d %= M;
    he *= 100;
    he %= M;
    x /= 10;
  }
  return d;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  long x;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ans += dd(x);
    ans %= M;
  }
  cout << n * ans % M;
}
