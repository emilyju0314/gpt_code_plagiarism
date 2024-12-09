#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res % mod) * (a % mod), res %= mod;
    a = (a % mod) * (a % mod);
    a %= mod;
    b >>= 1;
  }
  return res;
}
long long divide(long long a, int b) {
  return ((a % mod) * binpow(b, mod - 2) % mod) % mod;
}
long long nCr(long long n, long long k) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; ++i) {
    res = ((res % mod) * ((n - i) % mod)) % mod;
    res = divide(res, i + 1);
  }
  return res;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n;
  k = n;
  bool can = (n == 1);
  multiset<long long> st;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      n /= i;
      st.insert(i);
    }
  }
  if (n > 1) st.insert(n);
  if (n == k) can = 1;
  if (can) {
    return cout << "1\n0\n", 0;
  }
  if (st.size() == 2) {
    cout << "2\n";
  } else {
    cout << "1\n";
    int cnt = 0;
    long long mul = 1;
    for (auto i : st) {
      mul *= i;
      cnt++;
      if (cnt == 2) break;
    }
    cout << mul;
  }
}
