#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
int vst[1000100], p[1000100], pk;
long long arr[1000100], d[1000100];
int dp[1000100], tmp[1000100], tp[1000100];
int id[1000100];
bool is_prime(long long a) {
  if (a < 1000100) return false;
  for (int i = 0; i < pk; i++) {
    if (1LL * p[i] * p[i] > a) break;
    if (a % p[i] == 0) return false;
  }
  return true;
}
long long A;
int cnt;
int get(long long a) {
  if (a < 1000100) return id[a];
  return cnt - 1 - id[A / a];
}
int main() {
  cin >> A;
  int n = 0;
  for (int i = 2; i < 1000100; i++) {
    if (vst[i]) continue;
    for (long long j = i; j < 1000000000000LL; j *= i) {
      if (A % (j + 1)) continue;
      tp[n] = i;
      arr[n++] = j + 1;
    }
    p[pk++] = i;
    if (i > 10000) continue;
    for (int j = i * i; j < 1000100; j += i) vst[j] = 1;
  }
  if (A <= 3) return printf("%d\n", A & 1), 0;
  for (long long i = 1; i * i <= A; i++) {
    if (A % i) continue;
    d[cnt++] = i;
    if (i * i != A) d[cnt++] = A / i;
  }
  sort(d, d + cnt);
  for (int i = 0; i < cnt; i++) {
    if (d[i] < 1000100) id[d[i]] = i;
  }
  dp[0] = 1;
  for (int i = 0, ii = 0; i < n; i = ii) {
    for (int j = 0; j < cnt; j++) tmp[j] = dp[j];
    for (; ii < n && tp[i] == tp[ii]; ii++) {
      for (int j = 0; j < cnt - 1; j++) {
        if (!tmp[j]) continue;
        if (arr[ii] > d[cnt - j - 1]) continue;
        if (d[cnt - j - 1] % arr[ii]) continue;
        dp[get((long long)arr[ii] * d[j])] += tmp[j];
      }
    }
  }
  int ans = dp[cnt - 1];
  for (int i = 0; i < cnt - 1; i++) {
    if (!dp[i]) continue;
    if (is_prime(A / d[i] - 1)) ans += dp[i];
  }
  cout << ans << endl;
  return 0;
}
