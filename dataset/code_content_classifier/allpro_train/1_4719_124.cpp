#include <bits/stdc++.h>
using namespace std;
vector<int> u[200005];
int n, p;
long long x[200005], y[200005], t[200005], s[200005];
int main() {
  scanf("%d", &n);
  for (int i = (2); i < (n + 1); i++) {
    scanf("%d", &p);
    u[p].push_back(i);
  }
  for (int i = n; i; i--) {
    x[i] = 1;
    for (int j : u[i]) (x[i] *= x[j] + 1) %= 1000000007;
  }
  for (int i = (1); i < (n + 1); i++) {
    y[i]++;
    int l = int(u[i].size());
    t[0] = 1;
    s[l] = 1;
    for (int j = (1); j < (l + 1); j++)
      t[j] = t[j - 1] * (1 + x[u[i][j - 1]]) % 1000000007;
    for (int j = l; j--;) s[j] = s[j + 1] * (1 + x[u[i][j]]) % 1000000007;
    for (int j = (0); j < (l); j++)
      y[u[i][j]] = t[j] * s[j + 1] % 1000000007 * y[i] % 1000000007;
  }
  for (int i = (1); i < (n + 1); i++)
    printf("%lld%c", x[i] * y[i] % 1000000007, " \n"[i == n]);
}
