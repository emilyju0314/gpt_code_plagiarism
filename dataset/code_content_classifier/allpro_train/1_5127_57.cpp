#include <bits/stdc++.h>
using namespace std;
int k, l, s[100005][50], e[100005], qq[1005], m, n, r;
char c[100005];
int fs, last[100005][30], ll[30], ff[100005], b[100005], tt[30][100005],
    t[30][100005];
long long ans;
struct node {
  int l, r, c;
} q[100005];
int main() {
  scanf("%s", c);
  scanf("%d%d%d", &m, &l, &r);
  for (register int i = 1; i <= m; i++) {
    char cc = getchar();
    while (cc < 'a' || cc > 'z') cc = getchar();
    q[i].c = int(cc) - 96;
    scanf("%d%d", &q[i].l, &q[i].r);
  }
  n = strlen(c);
  for (register int i = 0; i < n; i++) {
    b[i + 1] = int(c[i]) - 96;
    tt[b[i + 1]][s[i][b[i + 1]]] = i;
    s[i + 1][b[i + 1]] = s[i][b[i + 1]] + 1;
    t[b[i + 1]][s[i + 1][b[i + 1]]] = i + 1;
    ll[b[i + 1]] = i + 1;
    for (register int j = 1; j <= 26; j++) {
      if (j != b[i + 1]) s[i + 1][j] += s[i][j];
      last[i + 1][j] = ll[j];
    }
  }
  for (register int i = 1; i <= 26; i++) tt[i][s[n][i]] = n;
  for (register int i = 1; i <= n; i++) {
    int tot = 0, ss = 0;
    for (register int j = 1; j <= m; j++) {
      int st = -1, en = -1;
      if (s[i][q[j].c] - q[j].r >= 0) st = t[q[j].c][s[i][q[j].c] - q[j].r] + 1;
      if (q[j].l > 0) {
        if (s[i][q[j].c] - q[j].l >= 0)
          en = tt[q[j].c][s[i][q[j].c] - q[j].l] + 1;
      } else
        en = i;
      if (st == -1 && en == -1) continue;
      if (st <= 0) st = 1;
      if (st > en) continue;
      ff[st]++;
      if (en < i || q[j].l == 0)
        ff[en + 1]--;
      else
        en = last[i][q[j].c], ff[en + 1]--;
      if (e[st] != i) qq[++tot] = st, e[st] = i;
      if (e[en + 1] != i) qq[++tot] = en + 1, e[en + 1] = i;
    }
    if (e[i] != i) qq[++tot] = i, e[i] = i;
    if (e[1] != i) qq[++tot] = 1, e[1] = i;
    sort(qq + 1, qq + 1 + tot);
    for (register int oo = 1; oo <= tot; oo++) {
      int j = qq[oo];
      ss = ss + ff[j];
      ff[j] = 0;
      if (ss >= l && ss <= r) {
        if (oo != tot)
          ans = ans + qq[oo + 1] - j;
        else
          ans = ans + i - j + 1;
      }
    }
  }
  printf("%I64d\n", ans);
}
