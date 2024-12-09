#include <bits/stdc++.h>
using namespace std;
const int MODULO = 1000003;
const int NMAX = 700005;
int n, C, comb[NMAX], fact[NMAX], factinv[NMAX];
int sol;
int Log(int x, int y) {
  int p = 1;
  while (y) {
    if (y & 1) p = (1LL * p * x) % MODULO;
    x = (1LL * x * x) % MODULO;
    y >>= 1;
  }
  return p;
}
int Com(int x, int y) {
  int aux = (1LL * fact[x] * factinv[y]) % MODULO;
  aux = (1LL * aux * factinv[x - y]) % MODULO;
  return aux;
}
int main() {
  int i;
  cin.sync_with_stdio(false);
  cin >> n >> C;
  fact[0] = fact[1] = 1;
  for (i = 2; i < NMAX; i++) fact[i] = (1LL * fact[i - 1] * i) % MODULO;
  factinv[NMAX - 1] = Log(fact[NMAX - 1], MODULO - 2);
  for (i = NMAX - 2; i >= 0; i--)
    factinv[i] = (1LL * factinv[i + 1] * (i + 1)) % MODULO;
  for (i = 1; i <= n; i++) {
    sol += Com(i + C - 1, C - 1);
    if (sol >= MODULO) sol -= MODULO;
  }
  cout << sol << "\n";
  return 0;
}
