#include <bits/stdc++.h>
using namespace std;
void read(int& x) {
  static char c;
  int f = 0;
  while (!isdigit(c = getchar()))
    if (c == '-') f = 1;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
  if (f) x = -x;
}
void read(long long& x) {
  static char c;
  int f = 0;
  while (!isdigit(c = getchar()))
    if (c == '-') f = 1;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
  if (f) x = -x;
}
void read(unsigned int& x) {
  static char c;
  while (!isdigit(c = getchar()))
    ;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
}
void read(unsigned long long& x) {
  static char c;
  while (!isdigit(c = getchar()))
    ;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
}
void chkmax(int& x, int y) {
  if (y > x) x = y;
}
void chkmin(int& x, int y) {
  if (y < x) x = y;
}
void chkmax(long long& x, long long y) {
  if (y > x) x = y;
}
void chkmin(long long& x, long long y) {
  if (y < x) x = y;
}
void chkmax(unsigned int& x, unsigned int y) {
  if (y > x) x = y;
}
void chkmin(unsigned int& x, unsigned int y) {
  if (y < x) x = y;
}
void chkmax(unsigned long long& x, unsigned long long y) {
  if (y > x) x = y;
}
void chkmin(unsigned long long& x, unsigned long long y) {
  if (y < x) x = y;
}
const int Mod = 998244353;
void Add(int& x, int y) { (x += y) >= Mod ? x -= Mod : x; }
void Del(int& x, int y) { (x -= y) < 0 ? x += Mod : x; }
int Pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % Mod;
    a = 1ll * a * a % Mod, b >>= 1;
  }
  return res;
}
const int len = 2000;
int Fac[len + 10], Iac[len + 10];
void facInit() {
  Fac[0] = Iac[0] = 1;
  for (int i = 1; i <= len; ++i) Fac[i] = 1ll * Fac[i - 1] * i % Mod;
  Iac[len] = Pow(Fac[len], Mod - 2);
  for (int i = len - 1; i; --i) Iac[i] = 1ll * Iac[i + 1] * (i + 1) % Mod;
}
int Binom(int x, int y) {
  return x < y ? 0 : 1ll * Fac[x] * Iac[y] % Mod * Iac[x - y] % Mod;
}
const int N = 2e3 + 10, K = 55;
int n, k;
int L[N], R[N];
int G[2][N][N], Pre[2][N][N];
bool checkI(int pos, int i) { return pos >= L[i] && pos <= R[i]; }
int calcG() {
  if (checkI(1, 1)) G[0][1][1] = 1;
  if (checkI(0, 1)) G[0][1][0] = 1;
  for (int mex = L[1]; mex <= R[1]; ++mex) {
    Pre[0][1][mex] = G[0][1][mex];
    if (mex) Add(Pre[0][1][mex], Pre[0][1][mex - 1]);
  }
  int cur = 0;
  for (int pos = 2; pos <= n; ++pos) {
    cur ^= 1;
    for (int sum = 0; sum <= pos; ++sum)
      for (int mex = L[pos - 2]; mex <= R[pos - 2] && mex <= sum; ++mex)
        G[cur][sum][mex] = Pre[cur][sum][mex] = 0;
    for (int sum = 0; sum <= pos; ++sum) {
      for (int mex = L[pos]; mex <= R[pos]; ++mex) {
        if (mex > sum) break;
        Add(G[cur][sum][mex], 1ll * sum * G[cur ^ 1][sum][mex] % Mod);
        if (sum) Add(G[cur][sum][mex], G[cur ^ 1][sum - 1][mex] % Mod);
        if (mex)
          Add(G[cur][sum][mex], 1ll * Iac[sum - mex] *
                                    Pre[cur ^ 1][sum - 1][min(
                                        mex - 1, min(sum - 1, R[pos - 1]))] %
                                    Mod);
        Pre[cur][sum][mex] = 1ll * Fac[sum - mex] * G[cur][sum][mex] % Mod;
        if (mex) Add(Pre[cur][sum][mex], Pre[cur][sum][mex - 1]);
      }
    }
  }
  return cur;
}
int calc(int cur) {
  int res = 0;
  for (int sum = 0; sum <= n; ++sum)
    for (int mex = L[n]; mex <= R[n]; ++mex) {
      if (mex > sum) continue;
      int coe = 1ll * Fac[n - mex] * Iac[n - sum] % Mod;
      Add(res, 1ll * G[cur][sum][mex] * coe % Mod);
    }
  return res;
}
void Work() {
  facInit();
  read(n), read(k);
  for (int i = 1, b; i <= n; ++i)
    read(b), R[i] = min(i, b + k), L[i] = max(0, b - k);
  printf("%d\n", calc(calcG()));
}
int main() { Work(); }
