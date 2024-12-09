#include <bits/stdc++.h>
using namespace std;
const long long N = 3e3 + 100;
const long long NN = 50;
vector<long long> v;
long long c[N];
long long g(long long n) {
  long long ans = 0;
  if (n == 1) return 0;
  for (long long i = (long long)v.size() - 1; i >= 0; i--) {
    if (v[i] == 1) {
      ans += c[i];
    }
    if (i != 0) c[i] += c[i - 1];
  }
  return ans + g(n / 2);
}
long long f2(long long n, long long k) {
  v.clear();
  long long x = k;
  while (x % 2 == 0) {
    v.push_back(x);
    x /= 2;
  }
  v.push_back(x);
  for (long long i = 0; i < v.size(); i++) c[i] = 0;
  c[0] = 1;
  return g(n);
}
long long f(long long n, long long k) {
  long long ans = f2(n, k);
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  n++;
  long long ans = 0;
  long long x = k;
  for (long long i = NN; i >= 1; i--) {
    if ((1LL << i) - 1 > n) continue;
    ans += f((1LL << i), k);
    n -= (1LL << i);
    if (k == 1 && n >= 0) ans++;
    if (k % 2 != 0 || n < 0) {
      break;
    }
    k /= 2;
    i++;
  }
  if (x == 1) ans--;
  cout << ans << "\n";
  return 0;
}
