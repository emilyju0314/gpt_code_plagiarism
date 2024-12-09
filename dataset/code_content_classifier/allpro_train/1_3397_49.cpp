#include <bits/stdc++.h>
using namespace std;
long long MOD;
inline void modulas(long long a) { MOD = a; }
inline void normal(long long &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long modMul(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long modAdd(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long modSub(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, MOD - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
vector<bool> isPrime(10000010, true);
inline void seivePrime(long long L, long long R) {
  long long lim = sqrt(R);
  for (long long i = 2; i <= lim; ++i) {
    for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
      isPrime[j - L] = false;
  }
  if (L == 1) isPrime[0] = false;
}
inline long long chckPrime(long long L, long long prme) {
  return isPrime[prme - L];
}
inline long long cntPrime(long long L, long long R) {
  return count(isPrime.begin(), isPrime.begin() + R - L + 1, true);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    long long w;
    cin >> n >> w;
    pair<int, int> ar[n + 100];
    for (int i = 0; i < n; i++) {
      cin >> ar[i].first;
      ar[i].second = i + 1;
    }
    sort(ar, ar + n);
    int ok = 0;
    for (int i = 0; i < n; i++) {
      if (ar[i].first >= (w + 1) / 2 && ar[i].first <= w) {
        ok = 1;
        cout << "1\n" << ar[i].second << "\n";
        break;
      }
    }
    if (ok == 0) {
      long long s = 0;
      for (int i = 0; i < n && ar[i].first < (w + 1) / 2; i++) {
        s += ar[i].first;
        if (s >= (w + 1) / 2 && s <= w) {
          ok = 1;
          cout << i + 1 << "\n";
          for (int j = 0; j <= i; j++) cout << ar[j].second << " ";
          cout << "\n";
          break;
        }
      }
    }
    if (ok == 0) cout << "-1\n";
  }
  return 0;
}
