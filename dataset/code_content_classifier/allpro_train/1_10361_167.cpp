#include <bits/stdc++.h>
using namespace std;
long long pwr(long long base, long long p, long long mod = (1000000007LL)) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<vector<long long> > identity;
vector<vector<long long> > matmul(const vector<vector<long long> > &a,
                                  const vector<vector<long long> > &b) {
  int n = (int)a.size();
  vector<vector<long long> > ans(n, vector<long long>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        ans[i][j] += (a[i][k] * b[k][j]) % (1000000007LL);
        ans[i][j] %= (1000000007LL);
      }
    }
  }
  return ans;
}
vector<vector<long long> > matpwr(const vector<vector<long long> > &a,
                                  long long n) {
  if (n == 0) {
    return identity;
  }
  if (n == 1) return a;
  vector<vector<long long> > tmp = matpwr(a, n / 2);
  tmp = matmul(tmp, tmp);
  if (n & 1) tmp = matmul(a, tmp);
  return tmp;
}
int n;
long long K, A[102], B[102], C[102];
int main() {
  identity.resize(16);
  for (int i = 0; i < 16; i++) {
    identity[i].resize(16);
    for (int j = 0; j < i; j++) {
      identity[i][j] = 0;
    }
    identity[i][i] = 1;
  }
  scanf("%d%lld", &n, &K);
  for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &A[i], &B[i], &C[i]);
  B[n] = K;
  vector<long long> curr(16, 0);
  curr[0] = 1;
  for (int t = 1; t <= n; t++) {
    if (A[t] == K) break;
    vector<vector<long long> > arr;
    arr.resize(16);
    for (int i = 0; i < 16; i++) {
      arr[i].resize(16);
      for (int j = 0; j < 16; j++) arr[i][j] = 0;
      if (i > C[t]) continue;
      if (i - 1 >= 0) arr[i][i - 1] = 1;
      arr[i][i] = 1;
      if (i + 1 <= C[t]) arr[i][i + 1] = 1;
    }
    arr = matpwr(arr, B[t] - A[t]);
    vector<long long> nxt(16, 0);
    for (int i = 0; i < 16; i++)
      for (int j = 0; j < 16; j++)
        nxt[i] = (nxt[i] + arr[i][j] * curr[j]) % (1000000007LL);
    curr = nxt;
  }
  printf("%lld\n", curr[0]);
  return 0;
}
