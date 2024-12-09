#include <bits/stdc++.h>
const double eps = 1e-10;
const float epsf = 1e-6;
using namespace std;
inline long long int __gcd(long long int a, long long int b) {
  if (a == 0 || b == 0) {
    return max(a, b);
  }
  long long int tempa, tempb;
  while (1) {
    if (a % b == 0)
      return b;
    else {
      tempa = a;
      tempb = b;
      a = tempb;
      b = tempa % tempb;
    }
  }
}
inline int compfloat(float& x, float& y) {
  if (fabs(x - y) < epsf)
    return 0;
  else if (x - y > 0)
    return 1;
  return -1;
}
inline int compdouble(double x, double y) {
  if (fabs(x - y) < eps)
    return 0;
  else if (x - y > 0)
    return 1;
  else
    return -1;
}
bool prime(long long int k) {
  for (long long int i = 2; i * i <= k; i++)
    if (k % i == 0) {
      return false;
    }
  return true;
}
void pdash(int n = 1) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      cout << "-";
    }
    cout << "\n";
  }
}
long long int power(long long int x, long long int y) {
  long long int result = 1;
  while (y > 0) {
    if (y & 1) {
      result = (result * x);
    }
    y = y >> 1;
    x = (x * x);
  }
  return result;
}
long long int power(long long int x, long long int y, long long int z) {
  long long int result = 1;
  x = x % z;
  while (y > 0) {
    if (y & 1) {
      result = (result * x) % z;
    }
    y = y >> 1;
    x = (x * x) % z;
  }
  return result;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrF(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int f[n + 1];
  f[0] = 1;
  for (long long int i = 1; i <= n; i++) f[i] = f[i - 1] * i % p;
  return (f[n] * modInverse(f[r], p) % p * modInverse(f[n - r], p) % p) % p;
}
void cordinate_compression(vector<int>& v) {
  vector<int> p = v;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  for (int i = 0; i < (int)((v).size()); i++)
    v[i] = (int)(lower_bound(p.begin(), p.end(), v[i]) - p.begin());
}
const long long int mod = 1e9 + 7;
void solve() {
  long long int n, m;
  cin >> n >> m;
  int a1[n + 1], a2[n + 1];
  for (int i = 1; i <= n; i++) cin >> a1[i];
  for (int i = 1; i <= n; i++) cin >> a2[i];
  vector<long long int> matched(n + 2), blank(n + 2);
  blank[n + 1] = 0;
  for (int i = n; i; i--) {
    blank[i] = blank[i + 1] + (a1[i] == 0) + (a2[i] == 0);
  }
  matched[0] = 1;
  long long int pp;
  for (int i = 1; i <= n; i++) {
    if (a1[i] == 0 and a2[i] == 0) {
      pp = m;
    } else if (a1[i] == 0 || a2[i] == 0) {
      pp = 1;
    } else if (a1[i] == a2[i]) {
      pp = 1;
    } else
      pp = 0;
    matched[i] = (matched[i - 1] * pp) % mod;
  }
  long long int p = 0;
  bool bz = 1;
  int casee;
  for (int i = 1; i <= n and bz; i++) {
    if (a1[i] == 0 and a2[i] == 0) {
      casee = 1;
    } else if (a1[i] == 0) {
      casee = 3;
    } else if (a2[i] == 0) {
      casee = 2;
    } else {
      casee = 4;
    }
    switch (casee) {
      case 1:
        p = (p + ((((matched[i - 1] * (((m * m - m) / 2) % mod)) % mod) *
                   power(m, blank[i + 1], mod)) %
                  mod)) %
            mod;
        break;
      case 2:
        p = (p + ((((matched[i - 1] * ((a1[i] - 1) % mod)) % mod) *
                   power(m, blank[i + 1], mod)) %
                  mod)) %
            mod;
        break;
      case 3:
        p = (p + ((((matched[i - 1] * ((m - a2[i]) % mod)) % mod) *
                   power(m, blank[i + 1], mod)) %
                  mod)) %
            mod;
        break;
      case 4:
        if (a1[i] > a2[i]) {
          p = (p + ((((matched[i - 1] * ((1) % mod)) % mod) *
                     power(m, blank[i + 1], mod)) %
                    mod)) %
              mod;
          bz = 0;
        }
        break;
    }
  }
  p = (p * modInverse(power(m, blank[1], mod), mod)) % mod;
  cout << p << "\n";
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
