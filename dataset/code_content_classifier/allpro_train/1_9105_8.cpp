#include <bits/stdc++.h>
using namespace std;
int p[18], c[100001], d[100001], fa[100001], sum[100001], n, i, j, k, l, tot, x,
    y, t;
set<int> S[100001];
set<int>::iterator I, J, K;
char st[100001];
long long ans, Ans;
struct type {
  int t, x, y;
} b[200001];
void swap(int &x, int &y) {
  int z = x;
  x = y;
  y = z;
}
int gf(int t) {
  if (fa[t] == t) return t;
  fa[t] = gf(fa[t]);
  return fa[t];
}
struct SA {
  int hi[200001], Hi[100001][17], sa[200001], ls[200001], rk[200001],
      Rk[200001], h[200001], a[200001], b[200001], i, j, k, l;
  char st[200001];
  void add() {
    static int a[200001], b[200001];
    int i, j, k, l;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (i = 1; i <= n; i++) ++a[rk[i]];
    for (i = 1; i <= n; i++) a[i] += a[i - 1];
    for (i = 1; i <= n; i++) ++b[rk[i]], sa[a[rk[i] - 1] + b[rk[i]]] = i;
  }
  void Add(int t) {
    b[rk[t]] += rk[t + l] != ls[rk[t]], ls[rk[t]] = rk[t + l];
    Rk[t] = a[rk[t] - 1] + b[rk[t]];
  }
  void init() {
    l = 1;
    for (i = 1; i <= n; i++) a[st[i] - 'a'] = 1;
    for (i = 1; i <= 25; i++) a[i] += a[i - 1];
    for (i = 1; i <= n; i++) rk[i] = a[st[i] - 'a'];
    add();
    while (l < n) {
      memset(a, 0, sizeof(a));
      memset(b, 0, sizeof(b));
      memset(ls, 128, sizeof(ls));
      for (i = 1; i <= n; i++) ++a[rk[i]];
      for (i = 1; i <= n; i++) a[i] += a[i - 1];
      for (i = n - l + 1; i <= n; i++) Add(i);
      for (i = 1; i <= n; i++)
        if (sa[i] - l >= 1) Add(sa[i] - l);
      memcpy(rk, Rk, sizeof(Rk));
      memset(a, 0, sizeof(a));
      for (i = 1; i <= n; i++) a[rk[i]] = 1;
      for (i = 1; i <= n; i++) a[i] += a[i - 1];
      for (i = 1; i <= n; i++) rk[i] = a[rk[i]];
      add();
      l *= 2;
    }
    while (rk[1] < n &&
           (1 > sa[rk[1] + 1] ? 1 : sa[rk[1] + 1]) + h[1] - 1 < n &&
           st[1 + h[1]] == st[sa[rk[1] + 1] + h[1]])
      ++h[1];
    for (i = 2; i <= n; i++) {
      h[i] = (h[i - 1] - 1 > 0 ? h[i - 1] - 1 : 0);
      if (rk[i] == n)
        h[i] = 0;
      else {
        while ((i > sa[rk[i] + 1] ? i : sa[rk[i] + 1]) + h[i] - 1 < n &&
               st[i + h[i]] == st[sa[rk[i] + 1] + h[i]])
          ++h[i];
      }
    }
    for (i = 1; i <= n; i++) hi[rk[i]] = h[i];
    for (i = 1; i <= n - 1; i++) Hi[i][0] = hi[i];
    l = 1;
    j = 0;
    while (l * 2 <= n - 1) {
      ++j;
      for (i = 1; i <= (n - 1) - l * 2 + 1; i++)
        Hi[i][j] =
            (Hi[i][j - 1] < Hi[i + l][j - 1] ? Hi[i][j - 1] : Hi[i + l][j - 1]);
      l *= 2;
    }
  }
  int get(int x, int y) {
    if (x > y) swap(x, y);
    --y;
    int l = floor(log2(y - x + 1));
    return (Hi[x][l] < Hi[y - p[l] + 1][l] ? Hi[x][l] : Hi[y - p[l] + 1][l]);
  }
} s1, s2;
bool cmp(type a, type b) { return a.t > b.t || a.t == b.t && a.y < b.y; }
int main() {
  p[0] = 1;
  for (i = 1; i <= 17; i++) p[i] = p[i - 1] * 2;
  scanf("%s", st + 1), n = strlen(st + 1);
  for (i = 1; i <= n; i++)
    s1.st[i] = st[i], s2.st[n - i + 1] = st[i], fa[i] = i;
  s1.init();
  s2.init();
  ans = 2;
  if (n >= 3) {
    for (i = 1; i <= n - 2; i++)
      b[++tot] = {i, s1.rk[i + 2], 0}, c[i] = s2.rk[n - i + 1];
    sort(c + 1, c + (n - 2) + 1);
    for (i = 1; i <= n - 3; i++) {
      j = s2.get(c[i], c[i + 1]);
      if (j)
        b[++tot] = {j, s1.rk[n - s2.sa[c[i]] + 3],
                    s1.rk[n - s2.sa[c[i + 1]] + 3]};
    }
    sort(b + 1, b + tot + 1, cmp);
    l = 0;
    for (i = 1; i <= tot; i++)
      if (i == tot || b[i].t != b[i + 1].t) {
        for (j = l + 1; j <= i; j++)
          if (!b[j].y) {
            Ans += n - s1.sa[b[j].x] + 1;
            sum[s1.sa[b[j].x]] = 1;
            S[s1.sa[b[j].x]].insert(b[j].x);
          } else {
            x = gf(s1.sa[b[j].x]), y = gf(s1.sa[b[j].y]);
            if (sum[x] < sum[y]) swap(x, y);
            t = 0;
            for (I = S[y].begin(); I != S[y].end(); ++I) {
              d[++t] = *I;
              K = S[x].upper_bound(*I);
              if (K != S[x].end()) {
                Ans -= s1.get(*I, *K);
                if (K != S[x].begin()) {
                  J = K;
                  --J;
                  Ans += s1.get(*J, *K) - s1.get(*J, *I);
                }
              } else
                J = K, --J, Ans -= s1.get(*J, *I);
              S[x].insert(*I);
            }
            for (k = 1; k <= t - 1; k++) Ans += s1.get(d[k], d[k + 1]);
            fa[y] = x;
            sum[x] += sum[y];
          }
        l = i;
        ans += Ans * (b[i].t - b[i + 1].t);
      }
  }
  if (n >= 2) {
    for (i = 2; i <= n; i++) c[i - 1] = s1.rk[i];
    sort(c + 1, c + (n - 1) + 1);
    for (i = 1; i <= n - 1; i++) {
      ans += n - s1.sa[c[i]] + 1;
      if (i < n - 1) ans -= s1.get(c[i], c[i + 1]);
    }
    for (i = 1; i <= n - 1; i++) c[i] = s2.rk[n - i + 1];
    sort(c + 1, c + (n - 1) + 1);
    for (i = 1; i <= n - 1; i++) {
      ans += n - s2.sa[c[i]] + 1;
      if (i < n - 1) ans -= s2.get(c[i], c[i + 1]);
    }
  }
  for (i = 1; i <= n; i++) {
    ans += n - s1.sa[i] + 1;
    if (i < n) ans -= s1.hi[i];
  }
  printf("%lld\n", ans);
}
