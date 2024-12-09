#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long k, c;
} a[110];
long long n, m, p[110], ans = 0, f = 1;
bool cmp(Node x, Node y) { return x.c < y.c; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].k >> a[i].c;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> p[i];
  }
  for (int i = m; i > 1; i--) p[i] -= p[i - 1];
  p[m + 1] = 1e18;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    while (a[i].k > p[f]) {
      ans += 1ll * p[f] * f * a[i].c;
      a[i].k -= p[f];
      f++;
    }
    ans += 1ll * a[i].k * a[i].c * f;
    p[f] -= a[i].k;
  }
  cout << ans << endl;
  return 0;
}
