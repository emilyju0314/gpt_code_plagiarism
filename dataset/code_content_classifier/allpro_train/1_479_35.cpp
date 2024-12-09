#include <bits/stdc++.h>
using namespace std;
int a, b, h, w, n, s = 1000000007;
int c[100001];
void dfs(int a, int b, int k) {
  if (!a and !b) {
    s = min(s, k);
    return;
  }
  if (k == n) return;
  if (c[k] == 2) {
    while (a) {
      a /= 2;
      k++;
    }
    while (b) {
      b /= 2;
      k++;
    }
    s = min(s, k);
  }
  if (a) dfs(a / c[k], b, k + 1);
  if (b) dfs(a, b / c[k], k + 1);
}
int main() {
  cin >> a >> b >> h >> w >> n;
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  sort(c, c + n, greater<int>());
  dfs((a - 1) / h, (b - 1) / w, 0);
  dfs((a - 1) / w, (b - 1) / h, 0);
  if (s > n)
    cout << -1;
  else
    cout << s;
  return 0;
}
