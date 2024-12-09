#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
void ingraph(vector<long long> graph[], long long m) {
  long long x, y;
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    x--, y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long modmulti(long long a, long long b) {
  return ((a % mod) * 1ll * (b % mod)) % mod;
}
long long modadd(long long a, long long b) {
  long long asdfgh = ((a % mod) + (b % mod) + mod + mod) % mod;
  asdfgh = (asdfgh + mod) % mod;
  return asdfgh;
}
long long modpower(long long a, long long n) {
  if (n == 0) return 1;
  if (n == 1) return a % mod;
  long long b = modpower(a, n / 2);
  b = modmulti(b, b);
  if (n % 2 == 0) return b;
  return modmulti(a, b);
}
long long modinv(long long a) { return modpower(a, mod - 2); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> vec(n);
    long long tmp = 0, flag = 0;
    for (long long i = 0; i < n; i++) {
      cin >> vec[i];
      if (n == 1 && vec[i] == k) flag++;
      if (vec[i] < k)
        vec[i] = -1;
      else if (vec[i] > k)
        vec[i] = 1;
      else {
        vec[i] = 1;
        tmp++;
      }
    }
    long long sum = 0;
    long long f = 0, l = 0;
    for (long long i = 0; i < n; i++) {
      sum += vec[i];
      l++;
      if (sum < 0) {
        f = 0;
        sum = 0;
        l = 0;
      } else if (sum > 0 && l != 1) {
        flag++;
      }
    }
    if (tmp != 0 && flag > 0)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
