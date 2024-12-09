#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
inline int add(int a, int b) { return (a + b < M) ? (a + b) : (a + b - M); }
inline int sub(int a, int b) { return (a >= b) ? (a - b) : (a - b + M); }
inline int mul(int a, int b) { return (int((a * 1LL * b) % M) + M) % M; }
inline int expo(int a, int b) {
  int ret = 1;
  b = (b == -1) ? (M - 2) : b;
  while (b != 0) {
    if (b & 1) {
      ret = mul(ret, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}
vector<int> prime;
bitset<N> vis;
int mu[N], spf[N];
void sieve() {
  mu[1] = 1;
  spf[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (!vis[i]) {
      prime.push_back(i);
      mu[i] = -1;
      spf[i] = i;
    }
    for (int j = 0; j < (int)prime.size() && i * prime[j] < N; ++j) {
      vis[i * prime[j]] = true;
      spf[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      }
      mu[i * prime[j]] = mu[i] * mu[prime[j]];
    }
  }
}
vector<int> divisors(int n) {
  vector<int> pdivs;
  while (n > 1) {
    pdivs.push_back(spf[n]);
    while (pdivs.back() == spf[n]) {
      n /= spf[n];
    }
  }
  int l = (int)pdivs.size();
  vector<int> ret;
  for (int mask = 1; mask < (1 << l); mask++) {
    int num = 1;
    for (int i = 0; i < l; i++) {
      if ((mask >> i) & 1) {
        num *= pdivs[i];
      }
    }
    ret.push_back(num);
  }
  return ret;
}
int main() {
  sieve();
  int n;
  scanf("%d", &n);
  vector<int> a(n), cnt(N);
  for (int &v : a) {
    scanf("%d", &v);
    for (int x : divisors(v)) {
      ++cnt[x];
    }
  }
  vector<int> pow2(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    pow2[i] = (pow2[i - 1] << 1);
    if (pow2[i] >= M) {
      pow2[i] -= M;
    }
  }
  for (int &v : pow2) {
    v = sub(v, 1);
  }
  vector<int> dp(N);
  for (int i = 2; i < N; i++) {
    dp[i] = mu[i] == 1 ? pow2[cnt[i]] : (M - pow2[cnt[i]]);
  }
  int tot = 0;
  for (int i = 2; i < N; i++) {
    tot = sub(tot, dp[i]);
  }
  int ans = 0;
  for (int x : a) {
    ans = add(ans, tot);
    for (int v : divisors(x)) {
      ans = add(ans, dp[v]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
