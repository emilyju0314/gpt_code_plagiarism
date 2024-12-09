#include <bits/stdc++.h>
using namespace std;
int fa[2 * 100100], n, k;
void init(int n) {
  for (int i = (0); i <= (2 * n + 3); i++) fa[i] = i;
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int a, int b) {
  int x = find(a), y = find(b);
  fa[x] = y;
}
int main() {
  cin >> n >> k;
  init(n);
  int a, b, d = n + 2;
  char c;
  for (int i = (1); i <= (k); i++) {
    scanf("%d %d %c", &a, &b, &c);
    int r = min(a + b - 1, 2 * n - (a + b - 1)) + 1;
    int l = max(2 - (b - a + 1), b - a + 1) - 1;
    if (l >= r) {
      if (c == 'o') return puts("0"), 0;
      continue;
    }
    if (c == 'x') {
      if (find(l) == find(r + d) || find(r) == find(l + d))
        return puts("0"), 0;
      else
        merge(l, r), merge(l + d, r + d);
    } else {
      if (find(l) == find(r) || find(l + d) == find(r + d))
        return puts("0"), 0;
      else
        merge(l, r + d), merge(l + d, r);
    }
  }
  int cnt = 0, ans = 1;
  for (int i = (0); i <= (2 * d - 1); i++)
    if (fa[i] == i) cnt++;
  cnt = cnt / 2 - 2;
  for (int i = (1); i <= (cnt); i++) (ans <<= 1) %= 1000000007;
  cout << ans << endl;
  return 0;
}
