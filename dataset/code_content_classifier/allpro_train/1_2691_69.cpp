#include <bits/stdc++.h>
using namespace std;
const int N = 103, M = 998244353;
struct matrix {
  long long a[N][N];
  matrix() { memset(a, 0, sizeof(a)); }
};
matrix operator*(matrix a, matrix b) {
  matrix ans;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
        ans.a[i][j] = (ans.a[i][j] + a.a[i][k] * b.a[k][j]) % (M - 1);
  return ans;
}
matrix power(matrix base, int k) {
  if (k == 1) return base;
  matrix ans = power(base, k / 2);
  ans = ans * ans;
  if (k & 1) ans = ans * base;
  return ans;
}
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
long long powMod(long long a, long long b, long long p) {
  long long res = 1;
  while (b) {
    if (b & 1)
      res = (long long)(res * 1LL * a % p), --b;
    else
      a = (long long)(a * 1LL * a % p), b >>= 1;
  }
  return res;
}
long long generator(long long p) {
  vector<long long> fact;
  long long phi = p - 1, n = phi;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0) n /= i;
    }
  if (n > 1) fact.push_back(n);
  for (long long res = 2; res <= p; res++) {
    bool ok = true;
    for (size_t i = 0; i < fact.size() && ok; i++)
      ok &= powMod(res, phi / fact[i], p) != 1;
    if (ok) return res;
  }
  return -1;
}
long long discrete_log(long long a, long long b, long long m) {
  long long n = (long long)sqrt(m + .0) + 1;
  map<long long, long long> Hash;
  for (long long i = n; i >= 1; i--) Hash[powMod(a, i * n, m)] = i;
  for (long long i = 0; i <= n; i++) {
    long long cur = (powMod(a, i, m) * b) % m;
    if (Hash.count(cur)) {
      long long ans = Hash[cur] * n - i;
      if (ans < m) return ans;
    }
  }
  return -1;
}
long long discrete_root(long long a, long long b, long long p) {
  long long g = generator(p);
  assert(g != -1);
  long long k = discrete_log(powMod(g, a, p), b, p);
  if (k == -1) return -1;
  return powMod(g, k, p);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  matrix ank;
  for (int i = 0; i < n; i++) cin >> ank.a[0][i];
  for (int j = 1; j < n; j++) ank.a[j][j - 1] = 1;
  int k, x;
  cin >> k >> x;
  matrix ans = power(ank, k - n);
  long long pw = ans.a[0][0];
  cout << discrete_root(pw, x, M) << endl;
  return 0;
}
