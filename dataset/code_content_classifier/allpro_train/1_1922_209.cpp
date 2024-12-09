#include <bits/stdc++.h>
using namespace std;
const int infinity = 0x3fffffff, maxn = 1 << 20;
const long long linfinity = 0x3fffffffffffffffLL;
char N[maxn];
int n;
int dp[maxn][2];
int solve(int x, int carry) {
  if (x == n) {
    return carry;
  }
  int& ans = dp[x][carry];
  if (ans != -1) return ans;
  ans = infinity;
  for (int a = 0; a < 2; a++)
    for (int b = 0; b < 2; b++)
      if ((b + carry + (N[x] - '0')) % 2 == a) {
        int ans2 =
            ((a > 0) + (b > 0)) + solve(x + 1, (b + carry + (N[x] - '0')) >> 1);
        ans = min(ans, ans2);
      }
  return ans;
}
int main() {
  scanf("%s", N);
  n = strlen(N);
  reverse(N, N + n);
  for (int x = 0; x <= n; x++)
    for (int c = 0; c < 2; c++) dp[x][c] = -1;
  printf("%d\n", solve(0, 0));
  int x, carry;
  for (x = 0, carry = 0; x < n; x++) {
    for (int a = 0; a < 2; a++)
      for (int b = 0; b < 2; ++b)
        if ((b + carry + (N[x] - '0')) % 2 == a) {
          if (solve(x, carry) == solve(x + 1, (b + carry + (N[x] - '0')) >> 1) +
                                     ((a > 0) + (b > 0))) {
            carry += b + N[x] - '0';
            carry >>= 1;
            if (a == 0 && b == 0) {
              goto next;
            } else if (a == 1 && b == 0) {
              printf("+2^%d\n", x);
              goto next;
            } else if (a == 0 && b == 1) {
              printf("-2^%d\n", x);
              goto next;
            } else {
            }
          }
        }
  next:;
    ;
    ;
  }
  if (carry == 1) {
    printf("+2^%d\n", n);
  }
  return 0;
}
