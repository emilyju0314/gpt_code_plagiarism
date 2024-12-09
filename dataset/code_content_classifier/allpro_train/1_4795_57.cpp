#include <bits/stdc++.h>
using namespace std;
int n, m, head = 1, tail = 1;
long long f[110000];
long long a[110000], b[110000];
int que[110000];
int main() {
  int i, j;
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> a[i];
  for (i = 1; i <= n; ++i) cin >> b[i];
  que[1] = 1;
  for (i = 2; i <= n; ++i) {
    while (head < tail && f[que[head]] + b[que[head]] * a[i] >=
                              f[que[head + 1]] + b[que[head + 1]] * a[i])
      ++head;
    f[i] = f[que[head]] + b[que[head]] * a[i];
    while (head < tail && (f[que[tail]] - f[i]) / (b[i] - b[que[tail]]) <
                              (f[que[tail - 1]] - f[que[tail]]) /
                                  (b[que[tail]] - b[que[tail - 1]]))
      --tail;
    que[++tail] = i;
  }
  cout << f[n];
  return 0;
}
