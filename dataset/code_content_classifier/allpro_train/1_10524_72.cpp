#include <bits/stdc++.h>
using namespace std;
string txt;
long long int len[1000010], cst[1000010], ar[1000010];
char text[1000006];
const int maxlen = 1000005;
const int alphabet = 256;
struct TT {
  int p, indx;
} arr[maxlen];
bool cmp(TT x, TT y) {
  if (x.p == y.p) return x.indx > y.indx;
  return x.p < y.p;
}
int Rank[22][maxlen], LCP[maxlen], step;
int pn[maxlen], cn[maxlen], p[maxlen], cnt[maxlen];
void build_suffix_array() {
  int n;
  n = strlen(text) + 1;
  memset(cnt, 0, alphabet * sizeof(int));
  for (int i = 0; i < n; ++i) ++cnt[text[i]];
  for (int i = 1; i < alphabet; ++i) cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; ++i) p[--cnt[text[i]]] = i;
  Rank[0][p[0]] = 0;
  int classes = 1;
  for (int i = 1; i < n; ++i) {
    if (text[p[i]] != text[p[i - 1]]) ++classes;
    Rank[0][p[i]] = classes - 1;
  }
  for (int i = 0; i < n; i++) {
    arr[i].p = Rank[0][i], arr[i].indx = i;
  }
  step = 1;
  for (int h = 0; (1 << h) < n; ++h) {
    for (int i = 0; i < n; ++i) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) pn[i] += n;
    }
    memset(cnt, 0, classes * sizeof(int));
    for (int i = 0; i < n; ++i) ++cnt[Rank[h][pn[i]]];
    for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) p[--cnt[Rank[h][pn[i]]]] = pn[i];
    cn[p[0]] = 0;
    classes = 1;
    for (int i = 1; i < n; ++i) {
      int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i - 1] + (1 << h)) % n;
      if (Rank[h][p[i]] != Rank[h][p[i - 1]] || Rank[h][mid1] != Rank[h][mid2])
        ++classes;
      cn[p[i]] = classes - 1;
    }
    for (int i = 0; i < n; i++)
      Rank[h + 1][i] = cn[i], arr[i].p = cn[i], arr[i].indx = i;
    step = h + 2;
  }
  sort(arr, arr + n, cmp);
  for (int i = 1; i < n; i++) arr[i - 1] = arr[i];
}
void build_LCP_array(int n) {
  LCP[0] = 0;
  int i, j, id1, id2, lh;
  for (i = 1; i < n; i++) {
    id1 = arr[i - 1].indx;
    id2 = arr[i].indx;
    lh = min(len[id1], len[id2]);
    LCP[i - 1] = 0;
    for (j = step - 1; j >= 0; j--)
      if (Rank[j][id1] == Rank[j][id2] && Rank[j][id2] != -1) {
        LCP[i - 1] += (1 << j);
        id1 += (1 << j);
        id2 += (1 << j);
      }
    LCP[i - 1] = min(lh, LCP[i - 1]);
  }
}
char st[600010];
int tr[3000000];
long long int dp[700000];
void build(int p, int l, int r) {
  if (l == r) {
    tr[p] = LCP[l];
    return;
  }
  int mid = (l + r) / 2;
  build(2 * p, l, mid);
  build(2 * p + 1, mid + 1, r);
  tr[p] = min(tr[2 * p], tr[2 * p + 1]);
}
int query(int p, int l, int r, int x, int y) {
  if (l > y || r < x) return 10000000;
  if (l >= x && r <= y) {
    return tr[p];
  }
  int mid = (l + r) / 2;
  return min(query(2 * p, l, mid, x, y), query(2 * p + 1, mid + 1, r, x, y));
}
long long int Lf[700000], Rh[700000];
int main() {
  int i, j, k, l, t, cs = 1, r = 1, s, m, n, a, b, c, d, e, f, g, h, u, v;
  memset(Rank, -1, sizeof(Rank));
  memset(cst, 0, sizeof(cst));
  txt = "";
  a = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", &st);
    l = strlen(st);
    for (j = 0; j < l; j++) {
      u = a;
      len[u] = l - j;
      cst[u] = i;
      text[a++] = st[j];
    }
    len[a] = -1;
    text[a++] = '#';
  }
  text[a] = '\0';
  for (i = 0; i < n; i++) {
    scanf("%I64d", &ar[i]);
  }
  for (i = 0; i < a; i++) {
    cst[i] = ar[cst[i]];
  }
  build_suffix_array();
  a = strlen(text);
  for (i = 0, j = 0; i < a; i++) {
    u = arr[i].indx;
    if (len[u] != -1) arr[j++].indx = arr[i].indx;
  }
  m = j;
  if (m == 1) {
    if (ar[0] < 0) ar[0] = 0;
    printf("%I64d\n", ar[0]);
    return 0;
  }
  build_LCP_array(m);
  dp[0] = 0;
  long long int ans = 0;
  for (i = 0; i < m; i++) {
    dp[i + 1] = dp[i] + cst[arr[i].indx];
  }
  for (i = 0; i < m; i++) {
    u = arr[i].indx;
    if (i == 0 && LCP[i] != len[u]) {
      ans = max(ans, len[u] * (dp[i + 1] - dp[i]));
    } else if (i > 0 && i < m - 1 && LCP[i - 1] != len[u] && LCP[i] != len[u]) {
      ans = max(ans, len[u] * (dp[i + 1] - dp[i]));
    } else if (i == m - 1 && LCP[i - 1] != len[u]) {
      ans = max(ans, len[u] * (dp[i + 1] - dp[i]));
    }
  }
  for (i = 0; i < m - 1; i++) {
    Lf[i] = Rh[i] = i;
  }
  for (i = 0; i < m - 1; i++) {
    u = i - 1;
    while (u >= 0 && LCP[u] >= LCP[i]) {
      Lf[i] = Lf[u];
      u = Lf[u] - 1;
    }
  }
  for (i = m - 2; i >= 0; i--) {
    u = i + 1;
    while (u <= m - 2 && LCP[u] >= LCP[i]) {
      Rh[i] = Rh[u];
      u = Rh[u] + 1;
    }
  }
  for (i = 0; i < m - 1; i++) {
    long long int cost = (dp[Rh[i] + 2] - dp[Lf[i]]) * 1LL * LCP[i];
    ans = max(ans, cost);
  }
  printf("%I64d\n", ans);
  return 0;
}
