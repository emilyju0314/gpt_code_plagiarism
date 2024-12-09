#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, G = 5;
long long fpow(long long a, long long k) {
  long long s = 1;
  while (k) {
    if (k & 1) s = s * a % MOD;
    a = a * a % MOD;
    k >>= 1;
  }
  return s;
}
long long bsgs(int a, int b) {
  map<long long, long long> hashmap;
  long long m = ceil(sqrt(MOD + 0.5));
  long long inva = fpow(a, m);
  for (long long i = 0, ans; i <= m; i++) {
    ans = i == 0 ? b : (ans * a % MOD);
    hashmap[ans] = i;
  }
  for (long long i = 1, ans = 1; i <= m; i++) {
    ans = ans * inva % MOD;
    if (hashmap.count(ans)) {
      long long ret = i * m % (MOD - 1) - hashmap[ans];
      ret = (ret % (MOD - 1) + (MOD - 1)) % (MOD - 1);
      return ret;
    }
  }
  return -1;
}
struct mat {
  long long a[5][5];
  mat() { memset(a, 0, sizeof(a)); }
  mat operator*(const mat &b) const {
    mat ans;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++)
          ans.a[i][j] += a[i][k] * b.a[k][j] % (MOD - 1);
        ans.a[i][j] %= (MOD - 1);
      }
    }
    return ans;
  }
};
mat fpow(mat a, long long k) {
  mat ans;
  for (int i = 0; i < 5; i++) ans.a[i][i] = 1;
  while (k) {
    if (k & 1) ans = ans * a;
    a = a * a;
    k >>= 1;
  }
  return ans;
}
int main() {
  long long n, f1, f2, f3, c;
  scanf("%lld %lld %lld %lld %lld", &n, &f1, &f2, &f3, &c);
  long long g1 = bsgs(G, f1), g2 = bsgs(G, f2);
  long long g3 = bsgs(G, f3), indc = bsgs(G, c);
  long long g4 = (indc * 2 + g3 + g2 + g1) % (MOD - 1);
  long long g5 = (indc * 4 + g4 + g3 + g2) % (MOD - 1);
  mat a;
  a.a[0][0] = 3;
  a.a[0][1] = MOD - 1 - 2;
  a.a[0][3] = MOD - 1 - 1;
  a.a[0][4] = a.a[1][0] = a.a[2][1] = a.a[3][2] = a.a[4][3] = 1;
  a = fpow(a, n - 1);
  long long gn = (g5 * a.a[4][0] + g4 * a.a[4][1] + g3 * a.a[4][2] +
                  g2 * a.a[4][3] + g1 * a.a[4][4]) %
                 (MOD - 1);
  if (gn < 0) gn += MOD - 1;
  printf("%lld\n", fpow(G, gn));
  return 0;
}
