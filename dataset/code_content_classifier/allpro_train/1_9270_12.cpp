#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
const int N = 200000 + 10;
const int inf = 0x3f3f3f3f;
int n, Q;
char s[N];
int sum[N][26];
struct SuffixArray {
  int sa[N], rnk[N], height[N], x[N], y[N], z[N];
  void SuffixSort() {
    int m = 256;
    for (int i = 1; i <= n; ++i) ++z[x[i] = s[i]];
    for (int i = 2; i <= m; ++i) z[i] += z[i - 1];
    for (int i = n; i; --i) sa[z[x[i]]--] = i;
    for (int k = 1; k < n; k <<= 1) {
      int p = 0;
      for (int i = n - k + 1; i <= n; ++i) y[++p] = i;
      for (int i = 1; i <= n; ++i)
        if (sa[i] > k) y[++p] = sa[i] - k;
      for (int i = 1; i <= m; ++i) z[i] = 0;
      for (int i = 1; i <= n; ++i) ++z[x[i]];
      for (int i = 2; i <= m; ++i) z[i] += z[i - 1];
      for (int i = n; i; --i) sa[z[x[y[i]]]--] = y[i], y[i] = 0;
      swap(x, y), x[sa[1]] = p = 1;
      for (int i = 2; i <= n; ++i)
        x[sa[i]] =
            (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k])
                ? p
                : ++p;
      if (p == m) break;
      m = p;
    }
  }
  void GetHeight() {
    for (int i = 1; i <= n; ++i) rnk[sa[i]] = i;
    for (int i = 1, j = 0; i <= n; ++i) {
      if (j) --j;
      int p = sa[rnk[i] - 1];
      while (s[i + j] == s[p + j]) ++j;
      height[rnk[i]] = j;
    }
  }
  int lg[N], st[18][N];
  void buildST() {
    for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; ++i) st[0][i] = height[i];
    for (int i = 1; i < 18; ++i)
      for (int j = 1; j <= n; ++j)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }
  int qmin(int l, int r) {
    int t = lg[r - l + 1];
    return min(st[t][l], st[t][r - (1 << t) + 1]);
  }
  int LCP(int x, int y) {
    if (rnk[x] > rnk[y]) swap(x, y);
    return qmin(rnk[x] + 1, rnk[y]);
  }
} A, B;
struct SegmentTree {
  int minv[N << 2], tag[N << 2];
  SegmentTree() {
    memset(minv, 0x3f, sizeof(minv)), memset(tag, 0x3f, sizeof(tag));
  }
  void update(int o, int l, int w) {
    tag[o] = min(tag[o], w), minv[o] = min(minv[o], l + w);
  }
  void pushup(int o) { minv[o] = min(minv[(o << 1)], minv[(o << 1 | 1)]); }
  void pushdown(int o, int l, int r) {
    int mid = (l + r) >> 1;
    if (tag[o] != inf)
      update((o << 1), l, tag[o]), update((o << 1 | 1), mid + 1, tag[o]),
          tag[o] = inf;
  }
  void modify(int o, int l, int r, int ql, int qr, int w) {
    if (ql <= l && r <= qr) {
      update(o, l, w);
      return;
    }
    int mid = (l + r) >> 1;
    pushdown(o, l, r);
    if (ql <= mid) modify((o << 1), l, mid, ql, qr, w);
    if (qr > mid) modify((o << 1 | 1), mid + 1, r, ql, qr, w);
    pushup(o);
  }
  int query(int o, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return minv[o];
    int mid = (l + r) >> 1, res = inf;
    pushdown(o, l, r);
    if (ql <= mid) res = min(res, query((o << 1), l, mid, ql, qr));
    if (qr > mid) res = min(res, query((o << 1 | 1), mid + 1, r, ql, qr));
    return res;
  }
} L, R;
void InitAA(SuffixArray &lcp_sa, SuffixArray &lcs_sa, SegmentTree &T) {
  for (int l = 1; l <= n / 2; ++l)
    for (int i = l, j = l << 1; j <= n; i += l, j += l) {
      int lcp = lcp_sa.LCP(i, j), lcs = lcs_sa.LCP(n - i + 1, n - j + 1);
      if (lcp + lcs - 1 >= l)
        T.modify(1, 1, n, i - lcs + 1, i + lcp - l, 2 * l - 1);
    }
}
bool CheckBorder(int l, int r) {
  int len = r - l + 1, S = sqrt(n) + 1;
  for (int i = 1; i < len && i <= S; ++i)
    if (A.LCP(l, r - i + 1) >= i) return 1;
  for (int i = A.rnk[l] - 1, h = A.height[i + 1], c = 0; i && c <= S && h > S;
       ++c, h = min(h, A.height[i--]))
    if (A.sa[i] >= l && A.sa[i] <= r && A.sa[i] + h > r) return 1;
  for (int i = A.rnk[l] + 1, h = A.height[i], c = 0; i <= n && c <= S && h > S;
       ++c, h = min(h, A.height[++i]))
    if (A.sa[i] >= l && A.sa[i] <= r && A.sa[i] + h > r) return 1;
  return 0;
}
bool CheckNS(int l, int r) {
  int flag = 1;
  for (int i = 0; i < 26; ++i)
    if (sum[r][i] - sum[l - 1][i] >= 2) {
      flag = 0;
      break;
    }
  return flag;
}
bool Check1(int l, int r) {
  int len = r - l + 1;
  for (int i = 1; i * i <= len; ++i) {
    if (len % i) continue;
    if (A.LCP(l, l + i) >= len - i) return 1;
    if (i != 1 && A.LCP(l, l + len / i) >= len - len / i) return 1;
  }
  return 0;
}
bool Check2(int l, int r) {
  if (CheckBorder(l, r)) return 1;
  if (L.query(1, 1, n, l, l) <= r) return 1;
  if (R.query(1, 1, n, n - r + 1, n - r + 1) <= n - l + 1) return 1;
  return 0;
}
bool Check3(int l, int r) {
  if (sum[r][s[l] - 'a'] - sum[l][s[l] - 'a']) return 1;
  if (sum[r - 1][s[r] - 'a'] - sum[l - 1][s[r] - 'a']) return 1;
  if (L.query(1, 1, n, l, r) <= r) return 1;
  return 0;
}
int main() {
  n = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 26; ++j) sum[i][j] = sum[i - 1][j] + (j == s[i] - 'a');
  A.SuffixSort(), A.GetHeight(), A.buildST();
  reverse(s + 1, s + n + 1);
  B.SuffixSort(), B.GetHeight(), B.buildST();
  reverse(s + 1, s + n + 1);
  InitAA(A, B, L), InitAA(B, A, R);
  Q = read();
  while (Q--) {
    int l = read(), r = read();
    if (CheckNS(l, r)) {
      puts("-1");
      continue;
    }
    if (Check1(l, r)) {
      puts("1");
      continue;
    }
    if (Check2(l, r)) {
      puts("2");
      continue;
    }
    if (Check3(l, r)) {
      puts("3");
      continue;
    }
    puts("4");
  }
  return 0;
}
