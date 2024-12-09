#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
template <typename T>
T gcd(T a, T b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
int set_bits(long long n) {
  long long ans = 0;
  while (n > 0) {
    if (n % 2) ans++;
    n /= 2;
  }
  return ans;
}
long long no_factors(long long n) {
  if (n == 1) return 1;
  long long ans = 2;
  for (int i = 2; i < sqrt(n); i++) {
    if (n % i == 0) ans += 2;
  }
  if (sqrt(n) == (int)sqrt(n)) ans++;
  return ans;
}
class pairs {
 public:
  long long x, y;
};
int main() {
  long long m, n;
  cin >> m >> n;
  int ansRocket;
  vector<bool> p(n);
  for (int i = 0; i < n; i++) {
    cout << 1 << endl;
    cin >> ansRocket;
    if (ansRocket == 0)
      break;
    else {
      p[i] = (ansRocket == 1) ? 1 : 0;
    }
  }
  if (ansRocket != 0) {
    long long beg = 1, end = m;
    int i = -1;
    while (beg <= end && ansRocket != 0) {
      long long mid = (beg + end) / 2;
      cout << mid << endl;
      cin >> ansRocket;
      i++;
      i %= n;
      if (p[i] == 0) {
        ansRocket = -ansRocket;
      }
      if (ansRocket == 0)
        break;
      else if (ansRocket == -1) {
        end = mid - 1;
      } else
        beg = mid + 1;
    }
  }
  return 0;
}
