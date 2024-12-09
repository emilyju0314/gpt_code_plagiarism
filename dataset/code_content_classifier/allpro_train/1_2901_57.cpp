#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100005;
const int SQMAX = 330;
const int MODULO = 1000000007;
int m;
int fact[NMAX], factinv[NMAX];
int pw25[NMAX];
int dpaux[NMAX];
char s[NMAX];
vector<pair<int, int> > v[NMAX];
int ans[NMAX];
int Log(int x, int y) {
  int p = 1;
  while (y) {
    if (y & 1) {
      p = (1LL * p * x) % MODULO;
      y--;
    }
    x = (1LL * x * x) % MODULO;
    y >>= 1;
  }
  return p;
}
int Comb(int x, int y) {
  int aux = (1LL * factinv[y] * factinv[x - y]) % MODULO;
  aux = (1LL * aux * fact[x]) % MODULO;
  return aux;
}
int main() {
  int i, j, x, sq, last, cnt = 0;
  scanf("%d", &m);
  sq = sqrt(NMAX);
  scanf("%s", s + 1);
  last = strlen(s + 1);
  for (i = 1; i <= m; i++) {
    scanf("%d", &x);
    if (x == 1) {
      scanf("%s", s + 1);
      last = strlen(s + 1);
    } else {
      scanf("%d", &x);
      cnt++;
      v[last].push_back(make_pair(x, cnt));
    }
  }
  fact[1] = fact[0] = 1;
  for (i = 2; i < NMAX; i++) fact[i] = (1LL * fact[i - 1] * i) % MODULO;
  for (i = 0; i < NMAX; i++) factinv[i] = Log(fact[i], MODULO - 2);
  pw25[0] = 1;
  for (i = 1; i < NMAX; i++) pw25[i] = (1LL * pw25[i - 1] * 25) % MODULO;
  for (i = 1; i < NMAX; i++)
    if (v[i].size()) {
      for (j = 0; j < i; j++) dpaux[j] = 0;
      dpaux[i] = 1;
      for (j = i + 1; j < NMAX; j++)
        dpaux[j] = (1LL * dpaux[j - 1] * 26 +
                    1LL * Comb(j - 1, i - 1) * pw25[j - 1 - (i - 1)]) %
                   MODULO;
      for (auto it : v[i]) ans[it.second] = dpaux[it.first];
    }
  for (i = 1; i <= cnt; i++) printf("%d\n", ans[i]);
  return 0;
}
