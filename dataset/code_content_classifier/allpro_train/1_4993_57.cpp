#include <bits/stdc++.h>
using namespace std;
int n, m;
unsigned long long has[2010], hass[2010][2010];
const unsigned long long base = 131;
map<unsigned long long, int> ma;
char s[2010];
unsigned long long hashs(char s[]) {
  int len = strlen(s + 1);
  unsigned long long ans = 0;
  for (int i = 1; i <= len; ++i) ans = ans * base + s[i] - 'a' + 1;
  return ans;
}
unsigned long long fast_pow(unsigned long long a, unsigned long long p) {
  unsigned long long ans = 1;
  for (; p; p >>= 1, a = a * a)
    if (p & 1) ans = ans * a;
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    has[i] = hashs(s);
  }
  unsigned long long bas2 = fast_pow(base, m);
  for (int i = 1; i <= n - m + 1; ++i) {
    unsigned long long cnt = 0;
    for (int j = i; j <= i + m - 1; ++j) cnt = cnt * bas2 + has[j];
    ma[cnt] = i;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; ++j)
      hass[i][j] = hass[i][j - 1] * base + s[j] - 'a' + 1;
  }
  for (int i = 1; i <= n - m + 1; ++i) {
    unsigned long long cnt = 0;
    for (int j = 1; j <= m; ++j) {
      unsigned long long num = hass[j][i + m - 1] - hass[j][i - 1] * bas2;
      cnt = cnt * bas2 + num;
    }
    if (ma.count(cnt)) {
      printf("%d %d\n", ma[cnt], i);
      return 0;
    }
  }
}
