#include <bits/stdc++.h>
using namespace std;
long long n;
long long powe(long long n, long long p) {
  if (p == 0) return 1ll;
  long long a = (powe(n, p / 2));
  if (p & 1) return a * a * n;
  return a * a;
}
int main() {
  cin >> n;
  long long ans = 1;
  if (n == 0) {
    puts("1");
    return 0;
  }
  ans += n * n * 2;
  ans += (n + 1) * (n + 2);
  ans -= 2;
  cout << ans;
  return 0;
}
