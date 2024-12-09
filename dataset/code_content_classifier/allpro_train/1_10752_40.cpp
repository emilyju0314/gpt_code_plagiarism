#include <bits/stdc++.h>
using namespace std;
const int n = 2e5 + 5;
const long long MOD = 998244353;
long long mod(long long a, long long b) { return ((a % b) + b) % b; }
int extended_euclid(int a, int b, int &x, int &y) {
  int xx = y = 0;
  int yy = x = 1;
  while (b) {
    int q = a / b;
    int t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
int mod_inverse(int a, int n) {
  int x, y;
  int d = extended_euclid(a, n, x, y);
  if (d > 1) return -1;
  return mod(x, n);
}
long long N, K, M;
long long F[n], P_K_2[n], P_2[n];
long long H[n];
int main() {
  cin >> N >> K;
  M = 0;
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  for (int i = 0; i < N; ++i) {
    M += H[(i + 1) % N] != H[i];
  }
  P_K_2[0] = P_2[0] = 1;
  F[0] = 1;
  for (int i = 1; i <= N; ++i) {
    P_K_2[i] = (P_K_2[i - 1] * (K - 2)) % MOD;
    P_2[i] = (P_2[i - 1] * 2) % MOD;
    F[i] = (F[i - 1] * i) % MOD;
  }
  long long K_Rest = 1;
  for (int i = 0; i < N - M; ++i) {
    K_Rest = (K_Rest * K) % MOD;
  }
  long long inv2 = mod_inverse(2, MOD);
  long long r = 0;
  for (int i = 1; i <= M; ++i) {
    long long v;
    if (i % 2 == 1) {
      v = P_2[i - 1];
    } else {
      long long invF = mod_inverse(F[i / 2], MOD);
      long long invFsq = (invF * invF) % MOD;
      long long f2 = (inv2 * F[i]) % MOD;
      v = (P_2[i - 1] - f2 * invFsq) % MOD;
      v = (v + MOD) % MOD;
    }
    long long m_i = (F[M] * mod_inverse(F[M - i], MOD)) % MOD;
    m_i = (m_i * mod_inverse(F[i], MOD)) % MOD;
    v = (v * m_i) % MOD;
    v = (v * P_K_2[M - i]) % MOD;
    v = (v * K_Rest) % MOD;
    r = (r + v) % MOD;
  }
  cout << r << endl;
  return 0;
}
