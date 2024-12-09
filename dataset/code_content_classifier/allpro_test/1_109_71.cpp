#include <bits/stdc++.h>
const int MOD = 998244353;
using ll = long long;
ll factorialNumInverse[100500 + 1];
ll naturalNumInverse[100500 + 1];
ll fact[100500 + 1];
void InverseofNumber(ll p) {
  naturalNumInverse[0] = naturalNumInverse[1] = 1;
  for (int i = 2; i <= 100500; i++)
    naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p) {
  factorialNumInverse[0] = factorialNumInverse[1] = 1;
  for (int i = 2; i <= 100500; i++)
    factorialNumInverse[i] =
        (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(ll p) {
  fact[0] = 1;
  for (int i = 1; i <= 100500; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
ll Binomial(ll N, ll R, ll p) {
  if (N < R) return 0;
  ll ans =
      ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
  return ans;
}
bool existe[100500][2][2];
int tab[100500][2][2];
int N;
std::string ss[100500];
int dp(int pos, int x, int y) {
  if (pos == N) {
    if (x && y) return 1;
    return 0;
  }
  if (existe[pos][x][y]) return tab[pos][x][y];
  existe[pos][x][y] = true;
  long long res = 0;
  if (ss[pos][0] != 'B' && ss[pos][1] != 'B') {
    res += dp(pos + 1, 1, y);
  }
  if (ss[pos][0] != 'W' && ss[pos][1] != 'W') {
    res += dp(pos + 1, x, 1);
  }
  return tab[pos][x][y] = res % MOD;
}
int main() {
  InverseofNumber(MOD);
  InverseofFactorial(MOD);
  factorial(MOD);
  std::cin >> N;
  int combs[3][2] = {};
  for (int i = 0; i != N; ++i) {
    std::string s;
    std::cin >> s;
    if (s[1] == 'W')
      s[1] = 'B';
    else if (s[1] == 'B')
      s[1] = 'W';
    ss[i] = s;
    for (int j = 0; j != 2; ++j) {
      switch (s[j]) {
        case 'W':
          combs[0][j]++;
          break;
        case 'B':
          combs[1][j]++;
          break;
        case '?':
          combs[2][j]++;
          break;
      }
    }
  }
  long long resp = 0;
  for (int i = 0; i != N * 2; ++i) {
    long long p1 = i - combs[1][0], p2 = i - combs[1][1];
    long long r1 = combs[2][0], r2 = combs[2][1];
    if (p1 < 0 || p2 < 0) continue;
    long long alpha = Binomial(r1, p1, MOD);
    long long beta = Binomial(r2, p2, MOD);
    resp = (resp + (alpha * beta)) % MOD;
  }
  long long delta = dp(0, 0, 0);
  resp -= delta;
  if (resp < 0) resp += MOD;
  std::cout << resp << "\n";
}
