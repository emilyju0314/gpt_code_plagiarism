#include <bits/stdc++.h>
using namespace std;
template <class T>
T read() {
  T x = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') w = -w;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * w;
}
template <class T>
T read(T& x) {
  return x = read<T>();
}
const int mod = 998244353;
inline int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
inline int mul(int a, int b) { return (long long)a * b % mod; }
inline int fpow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) ans = mul(ans, a);
  return ans;
}
const int N = 2000 + 10;
int pp[N], pq[N];
int cp[N][N], scc[N], dp[N];
int main() {
  int n = read<int>(), a = read<int>(), b = read<int>();
  int p = mul(a, fpow(b, mod - 2)), q = add(1, mod - p);
  pp[0] = pq[0] = 1;
  for (int i = 1; i <= n; ++i)
    pp[i] = mul(pp[i - 1], p), pq[i] = mul(pq[i - 1], q);
  cp[0][0] = 1;
  for (int s = 1; s <= n; ++s) {
    cp[s][0] = 1;
    for (int i = 1; i <= s; ++i)
      cp[s][i] =
          add(mul(pp[i], cp[s - 1][i]), mul(pq[s - i], cp[s - 1][i - 1]));
  }
  for (int s = 1; s <= n; ++s) {
    scc[s] = 1;
    for (int i = 0; i < s - 1; ++i)
      scc[s] = add(scc[s], mod - mul(scc[i + 1], cp[s][i + 1]));
  }
  for (int s = 2; s <= n; ++s) {
    int sum = 0;
    for (int i = 1; i < s; ++i)
      sum = add(
          sum,
          mul(scc[i],
              mul(cp[s][i], add(dp[i], add(dp[s - i], add(i * (s - i),
                                                          i * (i - 1) / 2))))));
    sum = add(sum, mul(scc[s], s * (s - 1) / 2));
    dp[s] = mul(sum, fpow(add(1, mod - scc[s]), mod - 2));
  }
  printf("%d\n", dp[n]);
  return 0;
}
