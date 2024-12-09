#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const int maxn = 1e5 + 10;
mt19937 rd(chrono::system_clock::now().time_since_epoch().count());
int n, m, a[maxn], bel[maxn];
unordered_map<int, int> mp, p;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline void work() {
  m = read();
  for (int x, i = 1; i <= m; i++) x = read(), mp[x]++, p[x] = i;
  for (auto x : mp)
    if (x.second > 1)
      a[++n] = x.first, a[++n] = x.first;
    else
      a[++n] = x.first;
  while (1.0 * clock() / CLOCKS_PER_SEC < 0.45) {
    shuffle(a + 1, a + 1 + n, rd);
    int i = 1, g = 0;
    while (i < n and g != 1) g = gcd(g, a[i]), ++i;
    if (g == 1) {
      g = 0;
      for (int j = i; j <= n; j++) g = gcd(g, a[j]);
      if (g == 1) {
        for (int j = 1; j < i; j++) bel[p[a[j]]] = 1;
        puts("YES");
        for (int i = 1; i <= m; i++) printf("%d ", bel[i] + 1);
        return;
      }
    }
  }
  puts("NO");
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
