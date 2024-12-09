#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 19;
const int inf = 1e9;
const int N = 6e5 + 55;
const int SQ = 200;
int S, q, sorted[N], start[N], finish[N], LOG[N];
int suff[N], h[N], ww[N], l, r, rmq[N][logN + 1], bel[N], belong[N], cnt[N], n,
    m, x, y, z, asd[N], asdsad[N], wh[N], w[N];
pair<int, int> mx[N], ans[N];
vector<pair<pair<int, int>, pair<pair<int, int>, int> > > v[N];
pair<pair<int, int>, int> C[N], temp[N];
char s[N], s2[N];
int get(int x, int y) {
  --y;
  if (x > y) return inf;
  int t = LOG[y - x + 1];
  return min(rmq[x][t], rmq[y - (1 << t) + 1][t]);
}
pair<int, int> cmp(pair<int, int> x, pair<int, int> y) {
  if (x.first != y.first) {
    if (x > y) return x;
    return y;
  }
  if (x < y) return x;
  return y;
}
pair<int, int> tet(int x, int y) {
  pair<int, int> ans = make_pair(0, x);
  if (bel[x] == bel[y]) {
    for (int i = x; i <= y; i++) ans = cmp(ans, make_pair(cnt[i], i));
    return ans;
  }
  int t1 = bel[x] + 1, t2 = bel[y] - 1;
  for (int i = t1; i <= t2; i++) ans = cmp(ans, mx[i]);
  for (int i = finish[bel[x]]; i >= x; i--)
    ans = cmp(ans, make_pair(cnt[i], i));
  for (int i = start[bel[y]]; i <= y; i++) ans = cmp(ans, make_pair(cnt[i], i));
  return ans;
}
void add(int x) {
  int t = bel[x];
  ++cnt[x];
  mx[t] = cmp(mx[t], make_pair(cnt[x], x));
}
void counting_sort() {
  memset(h, 0, sizeof h);
  for (int i = 1; i <= n; i++) h[C[i].first.second]++;
  for (int i = 1; i <= N - 1; i++) h[i] += h[i - 1];
  for (int i = 1; i <= n; i++) temp[h[C[i].first.second]--] = C[i];
  memset(h, 0, sizeof h);
  for (int i = 1; i <= n; i++) h[temp[i].first.first]++;
  for (int i = 1; i <= N - 1; i++) h[i] += h[i - 1];
  for (int i = n; i >= 1; i--) C[h[temp[i].first.first]--] = temp[i];
}
void suffix_array() {
  for (int i = 1; i <= n; i++) suff[i] = s[i];
  for (int i = 1; i <= logN; i++) {
    for (int j = 1; j <= n; j++)
      C[j] =
          make_pair(make_pair(suff[j], suff[min(n + 1, j + (1 << i - 1))]), j);
    counting_sort();
    for (int j = 1; j <= n; j++)
      suff[C[j].second] =
          suff[C[j - 1].second] + (C[j - 1].first != C[j].first);
  }
}
pair<int, int> get(int x, int y, int l, int r) {
  for (int i = x; i <= y; i++) cnt[ww[i]]++;
  pair<int, int> ans = make_pair(0, l);
  for (int i = x; i <= y; i++)
    if (l <= ww[i] && ww[i] <= r) ans = cmp(ans, make_pair(cnt[ww[i]], ww[i]));
  for (int i = x; i <= y; i++) cnt[ww[i]]--;
  return ans;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  s[++n] = '#';
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%s", s2 + 1);
    int m = strlen(s2 + 1);
    for (int j = n + 1; j <= n + m; j++) {
      s[j] = s2[j - n];
      belong[j] = i;
    }
    n += m;
    s[++n] = '$';
  }
  suffix_array();
  for (int i = 1; i <= n; i++) sorted[suff[i]] = i;
  int j = 0;
  for (int i = 1; i <= n; i++) {
    if (j) j--;
    if (suff[i] == 1) continue;
    while (i + j <= n && sorted[suff[i] - 1] + j <= n &&
           s[i + j] == s[sorted[suff[i] - 1] + j])
      j++;
    rmq[suff[i] - 1][0] = j;
  }
  for (int i = 1; i <= logN; i++)
    for (int j = 1; j <= n - 1; j++)
      rmq[j][i] = min(rmq[j][i - 1], rmq[min(n - 1, j + (1 << i - 1))][i - 1]);
  for (int i = 1; i <= N - 1; i++) LOG[i] = log2(i);
  scanf("%d", &q);
  int t = 0, tt = 0;
  for (int i = 1; i <= n; i++) {
    if (belong[sorted[i]]) {
      ++t;
      ww[t] = belong[sorted[i]];
      wh[i] = t;
      tt = i;
    }
    asdsad[i] = tt;
  }
  tt = inf;
  for (int i = n; i >= 1; i--) {
    if (belong[sorted[i]]) tt = i;
    asd[i] = tt;
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d %d %d %d", &l, &r, &x, &y);
    int f = suff[x], sz = y - x + 1;
    int bas = 1, son = f;
    while (bas < son) {
      if (get((bas + son >> 1), f) >= sz)
        son = (bas + son >> 1);
      else
        bas = (bas + son >> 1) + 1;
    }
    int lll = bas;
    bas = f, son = n;
    while (bas < son) {
      int ort = bas + son + 1 >> 1;
      if (get(f, ort) >= sz)
        bas = ort;
      else
        son = ort - 1;
    }
    int rrr = bas;
    lll = asd[lll];
    rrr = asdsad[rrr];
    if (lll > rrr) {
      ans[i] = make_pair(0, l);
    } else {
      lll = wh[lll];
      rrr = wh[rrr];
      if (rrr - lll <= 2 * SQ)
        ans[i] = get(lll, rrr, l, r);
      else
        v[lll / SQ].push_back(
            make_pair(make_pair(rrr, lll), make_pair(make_pair(l, r), i)));
    }
  }
  int last = 1;
  for (int i = 1; i <= m; i++)
    if (i == m || i % SQ == 0) {
      start[++S] = last;
      finish[S] = i;
      for (int j = last; j <= i; j++) bel[j] = S;
      last = i + 1;
    }
  for (int i = 0; i <= N - 1; i++) {
    if (!v[i].size()) continue;
    sort(v[i].begin(), v[i].end());
    int j = (i + 1) * SQ - 1, g = j;
    for (int j = N - 1; j >= 0; j--) {
      cnt[j] = 0;
      mx[bel[j]] = make_pair(0, j);
    }
    for (__typeof(v[i].begin()) it = v[i].begin(); it != v[i].end(); it++) {
      while (j < it->first.first) add(ww[++j]);
      pair<int, int> ans = make_pair(0, it->second.first.first);
      ans = tet(it->second.first.first, it->second.first.second);
      for (int jh = it->first.second; jh <= g; jh++)
        if (it->second.first.first <= ww[jh] &&
            ww[jh] <= it->second.first.second) {
          ans = cmp(ans, make_pair(++cnt[ww[jh]], ww[jh]));
        }
      for (int jh = it->first.second; jh <= g; jh++)
        if (it->second.first.first <= ww[jh] &&
            ww[jh] <= it->second.first.second)
          --cnt[ww[jh]];
      ::ans[it->second.second] = ans;
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%d %d\n", ans[i].second, ans[i].first);
  }
  return 0;
}
