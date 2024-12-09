#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long fact[200001], invfact[200001];
int n50 = 0, n100 = 0, k = 0;
struct node {
  int l[2], r[2], b;
};
long long nways[51][51][51][51][2], shortest[51][51][51][51][2];
queue<node> q;
long long pmod(long long base, long long p) {
  if (p == 0) return 1LL;
  long long ret = pmod(base, p / 2);
  ret = (ret * ret) % MOD;
  if (p % 2 == 1) ret = (ret * base) % MOD;
  return ret;
}
long long invEuler(long long x) { return pmod(x, MOD - 2); }
long long nCr(long long n, long long r) {
  long long ret = 1;
  ret *= fact[n];
  ret = (ret * invfact[r]) % MOD;
  ret = (ret * invfact[n - r]) % MOD;
  return ret;
}
void bfs() {
  memset(nways, 0, sizeof(nways));
  memset(shortest, -1, sizeof(shortest));
  nways[n50][n100][0][0][0] = 1;
  shortest[n50][n100][0][0][0] = 0;
  node temp;
  temp.l[0] = n50;
  temp.l[1] = n100;
  temp.r[0] = 0;
  temp.r[1] = 0;
  temp.b = 0;
  q.push(temp);
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    int l0, l1, r0, r1, b;
    l0 = temp.l[0];
    l1 = temp.l[1];
    r0 = temp.r[0];
    r1 = temp.r[1];
    b = temp.b;
    if (b == 0) {
      for (int i = 0; i <= l0; ++i) {
        for (int j = 0; j <= l1; ++j) {
          if (50 * i + 100 * j > k || (!i && !j)) continue;
          int _l0 = l0 - i, _l1 = l1 - j, _r0 = r0 + i, _r1 = r1 + j, _b = !b;
          if (shortest[_l0][_l1][_r0][_r1][_b] == -1 ||
              shortest[_l0][_l1][_r0][_r1][_b] >
                  shortest[l0][l1][r0][r1][b] + 1) {
            shortest[_l0][_l1][_r0][_r1][_b] = 1 + shortest[l0][l1][r0][r1][b];
            nways[_l0][_l1][_r0][_r1][_b] =
                (((nCr(l0, i) * nCr(l1, j)) % MOD) * nways[l0][l1][r0][r1][b]) %
                MOD;
            temp.l[0] = _l0;
            temp.l[1] = _l1;
            temp.r[0] = _r0;
            temp.r[1] = _r1;
            temp.b = _b;
            q.push(temp);
          } else if (shortest[_l0][_l1][_r0][_r1][_b] ==
                     shortest[l0][l1][r0][r1][b] + 1)
            nways[_l0][_l1][_r0][_r1][_b] =
                (nways[_l0][_l1][_r0][_r1][_b] +
                 (((nCr(l0, i) * nCr(l1, j)) % MOD) *
                  nways[l0][l1][r0][r1][b]) %
                     MOD) %
                MOD;
        }
      }
    } else {
      for (int i = 0; i <= r0; ++i) {
        for (int j = 0; j <= r1; ++j) {
          if (50 * i + 100 * j > k || (!i && !j)) continue;
          int _l0 = l0 + i, _l1 = l1 + j, _r0 = r0 - i, _r1 = r1 - j, _b = !b;
          if (shortest[_l0][_l1][_r0][_r1][_b] == -1 ||
              shortest[_l0][_l1][_r0][_r1][_b] >
                  shortest[l0][l1][r0][r1][b] + 1) {
            shortest[_l0][_l1][_r0][_r1][_b] = 1 + shortest[l0][l1][r0][r1][b];
            nways[_l0][_l1][_r0][_r1][_b] =
                (((nCr(r0, i) * nCr(r1, j)) % MOD) * nways[l0][l1][r0][r1][b]) %
                MOD;
            temp.l[0] = _l0;
            temp.l[1] = _l1;
            temp.r[0] = _r0;
            temp.r[1] = _r1;
            temp.b = _b;
            q.push(temp);
          } else if (shortest[_l0][_l1][_r0][_r1][_b] ==
                     shortest[l0][l1][r0][r1][b] + 1)
            nways[_l0][_l1][_r0][_r1][_b] =
                (nways[_l0][_l1][_r0][_r1][_b] +
                 (((nCr(r0, i) * nCr(r1, j)) % MOD) *
                  nways[l0][l1][r0][r1][b]) %
                     MOD) %
                MOD;
        }
      }
    }
  }
}
int main() {
  int n, in;
  fact[0] = 1;
  fact[1] = 1;
  invfact[0] = invEuler(1);
  invfact[1] = invfact[0];
  for (int i = 2; i < 200001; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
    invfact[i] = invEuler(fact[i]);
  }
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &in);
    if (in == 50)
      n50++;
    else
      n100++;
  }
  bfs();
  cout << shortest[0][0][n50][n100][1] << endl << nways[0][0][n50][n100][1];
}
