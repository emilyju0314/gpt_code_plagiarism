#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, D = 55, mod = 1e9 + 7;
char s[N], r[D], l[D];
int ch[N * D][10], fail[N * D], leaf[N * D], cnt = 1;
int d, n;
void insert(char *s) {
  int u = 1;
  for (int i = 0; i < d / 2; i++) {
    int t = s[i] - '0';
    if (!ch[u][t]) ch[u][t] = ++cnt;
    u = ch[u][t];
  }
  for (int i = 0; i < 10; i++) ch[u][i] = -1;
  leaf[u] = 1;
}
void build() {
  queue<int> q;
  for (int i = 0; i < 10; i++)
    if (ch[1][i])
      fail[ch[1][i]] = 1, q.push(ch[1][i]);
    else
      ch[1][i] = 1;
  while (q.size()) {
    int t = q.front();
    q.pop();
    for (int i = 0; i < 10; i++)
      if (int &v = ch[t][i])
        if (~v)
          q.push(v), fail[v] = ch[fail[t]][i];
        else
          v = t;
      else
        v = ch[fail[t]][i];
  }
}
int f[D][N * D];
void _(int &x, int y) {
  x += y;
  x >= mod ? x -= mod : 0;
}
int dp(char *s) {
  int u = 1;
  for (int i = 0; i < d; i++) {
    memset(f[i + 1], 0, sizeof(int) * (cnt + 2));
    for (int j = 1; j <= cnt; j++)
      for (int k = 0; k < 10; k++) _(f[i + 1][ch[j][k]], f[i][j]);
    for (int j = 0; j < s[i + 1] - '0'; j++) f[i + 1][ch[u][j]]++;
    u = ch[u][s[i + 1] - '0'];
  }
  ++f[d][u];
  long long ans = 0;
  for (int i = 1; i <= cnt; i++)
    if (leaf[i]) ans += f[d][i];
  return ans % mod;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  scanf("%s", l + 1);
  scanf("%s", r + 1);
  d = strlen(l + 1);
  for (int i = 0; i <= n - d / 2; i++) insert(s + i);
  build();
  int t = d;
  while (l[t] == '0') l[t--] = '9';
  --l[t];
  cout << (dp(r) - dp(l) + mod) % mod << endl;
}
