#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template <class T>
inline T lcm(T a, T b) {
  return ((a) / gcd((a), (b)) * (b));
}
template <class T>
inline T BigMod(T Base, T power, T M = 1000000007) {
  if (power == 0) return 1;
  if (power & 1)
    return ((Base % M) * (BigMod(Base, power - 1, M) % M)) % M;
  else {
    T y = BigMod(Base, power / 2, M) % M;
    return (y * y) % M;
  }
}
template <class T>
inline T ModInv(T A, T M = 1000000007) {
  return BigMod(A, M - 2, M);
}
int fx[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int fy[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
double arr[111];
double dp[111];
double pre[111];
int main() {
  int n, i, j;
  double answer = 0;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> arr[i];
  sort(arr + 1, arr + n + 1);
  dp[n] = arr[n];
  pre[n] = (1 - arr[n]);
  for (i = n - 1; i >= 1; i--) {
    pre[i] = (1 - arr[i]) * pre[i + 1];
    dp[i] = arr[i] * pre[i + 1] + dp[i + 1] * (1 - arr[i]);
  }
  for (i = 1; i <= n; i++) answer = max(answer, dp[i]);
  printf("%.10f", answer);
  return 0;
}
