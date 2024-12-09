#include <bits/stdc++.h>
using namespace std;
int n, jc[200010], inv[200010], l, r, ans;
char s[200010];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  jc[0] = 1;
  for (int i = 1; i <= n; i++) jc[i] = (long long)jc[i - 1] * i % 1000000007;
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = (long long)(1000000007 - 1000000007 / i) * inv[1000000007 % i] %
             1000000007;
  for (int i = 2; i <= n; i++)
    inv[i] = (long long)inv[i - 1] * inv[i] % 1000000007;
  ans = l = r = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == ')') r++;
  for (int i = 1; i <= n; i++)
    if (s[i] == '(') {
      ans = (ans + (long long)jc[l + r] * inv[r - 1] % 1000000007 * inv[l + 1] %
                       1000000007) %
            1000000007;
      l++;
    } else
      r--;
  printf("%d", ans);
  return 0;
}
