#include <bits/stdc++.h>
using namespace std;
const long long mol = 998244353;
const int maxn = 1000;
int l[maxn + 11], r[maxn + 11], R[maxn + 11], L[maxn + 11];
vector<int> v;
long long inv[maxn + 11];
long long f[maxn + 11][maxn + 11];
long long add(long long a, long long b) {
  a += b;
  if (a >= mol) a -= mol;
  return a;
}
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mol;
    a = a * a % mol;
    b >>= 1;
  }
  return ans;
}
void pre() {
  inv[0] = 1;
  for (int i = 1; i <= 500; i++) inv[i] = inv[i - 1] * qpow(i, mol - 2) % mol;
}
long long C(int n, int m) {
  long long ans = 1;
  for (int i = n - m + 1; i <= n; i++) ans = ans * i % mol;
  return ans * inv[m] % mol;
}
int main() {
  int n;
  pre();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    v.push_back(l[i]);
    v.push_back(r[i] + 1);
  }
  reverse(l + 1, l + 1 + n);
  reverse(r + 1, r + 1 + n);
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
  for (int i = 1; i <= n; i++) {
    L[i] = lower_bound((v).begin(), (v).end(), l[i]) - v.begin() + 1;
    R[i] = lower_bound((v).begin(), (v).end(), r[i] + 1) - v.begin();
  }
  int m = v.size() - 1;
  for (int i = 0; i <= m; i++) f[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = L[i]; j <= R[i]; j++) {
      for (int k = i; k; k--) {
        if (R[k] < j || L[k] > j) break;
        f[i][j] = add(f[i][j], f[k - 1][j - 1] *
                                   C(i - k + v[j] - v[j - 1], i - k + 1) % mol);
      }
    }
    for (int k = 1; k <= m; k++) f[i][k] = add(f[i][k], f[i][k - 1]);
  }
  long long ans = f[n][m];
  for (int i = 1; i <= n; i++) ans = ans * qpow(r[i] - l[i] + 1, mol - 2) % mol;
  printf("%lld\n", ans);
}
