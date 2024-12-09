#include <bits/stdc++.h>
using namespace std;
int a[100009];
int p[100009];
int s[100009];
int main() {
  int n;
  cin >> n;
  for (int(i) = (0); i < (n); ++(i)) cin >> a[i];
  p[0] = 1;
  for (int(i) = (1); i < (n); ++(i))
    if (a[i - 1] < a[i])
      p[i] = p[i - 1] + 1;
    else
      p[i] = 1;
  s[n - 1] = 1;
  for (int(i) = (n - 1) - 1; (i) >= (0); --(i))
    if (a[i + 1] > a[i])
      s[i] = s[i + 1] + 1;
    else
      s[i] = 1;
  int ans = 0;
  for (int(i) = (0); i < (n); ++(i)) ans = max(ans, p[i] + 1);
  ans = min(ans, n);
  for (int(i) = (1); i < (n); ++(i))
    if (a[i - 1] + 1 < a[i + 1]) ans = max(ans, p[i - 1] + s[i + 1] + 1);
  cout << ans;
  return 0;
}
