#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int n, m, mdiv;
int num[200];
int able[10][200];
const int mod = 1000000007;
inline int fix(int a) {
  if (a >= m) return a - m;
  return a;
}
inline int fix2(int a) {
  if (a < 0) return a + m;
  return a;
}
int dfs(int dep, int back) {
  if (dep < 5) {
    int res = 1;
    int j;
    for (int i = back + 1; i < mdiv; ++i)
      if (!able[dep][i] && !able[dep][m - i] && num[i]) {
        for (j = 0; j < m; ++j) able[dep + 1][j] = 0;
        for (j = 0; j < m; ++j)
          if (able[dep][j]) {
            able[dep + 1][j] = able[dep + 1][fix(i + j)] =
                able[dep + 1][fix2(i - j)] = 1;
          }
        res += dfs(dep + 1, i) * (long long int)num[i] % mod;
        if (res >= mod) res -= mod;
      }
    return res;
  } else {
    int res = 1;
    for (int i = back + 1; i < mdiv; ++i)
      if (!able[dep][i] && !able[dep][m - i] && num[i]) {
        res += num[i];
      }
    if (res >= mod) res -= mod;
    return res;
  }
}
int main() {
  scanf("%*d%d%d", &m, &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    a %= m;
    a = min(a, m - a);
    num[a]++;
  }
  mdiv = m / 2;
  ++mdiv;
  able[0][0] = 1;
  printf("%d\n", dfs(0, 0));
  return 0;
}
