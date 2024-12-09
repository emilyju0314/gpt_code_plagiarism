#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
template <typename T>
T read() {
  T x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <typename T>
void chkmax(T &x, const T &y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  x = x < y ? x : y;
}
const int N = 6e5 + 10;
namespace blossom {
vec G[N];
int col[N], tim, fa[N], n, mat[N], vis[N], pre[N];
queue<int> q;
vec usd;
int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }
void match(int x, int y) {
  mat[x] = y, mat[y] = x;
  usd.emplace_back(x);
  usd.emplace_back(y);
}
void link(int x, int y) {
  G[x].emplace_back(y);
  G[y].emplace_back(x);
}
int lca(int x, int y) {
  ++tim;
  x = gf(x), y = gf(y);
  while (vis[x] != tim) {
    vis[x] = tim;
    x = gf(pre[mat[x]]);
    if (y) swap(x, y);
  }
  return x;
}
void blossom(int x, int y, int L) {
  while (gf(x) != L) {
    pre[x] = y;
    y = mat[x];
    if (col[y] == 2) q.emplace(y), col[y] = 1, usd.emplace_back(y);
    if (gf(x) == x) fa[x] = L, usd.emplace_back(x);
    if (gf(y) == y) fa[y] = L, usd.emplace_back(y);
    x = pre[y];
  }
}
bool tmath(int x) {
  for (auto v : usd) fa[v] = v, col[v] = pre[v] = 0;
  usd.clear();
  while (q.size()) q.pop();
  q.emplace(x);
  col[x] = 1;
  usd.emplace_back(x);
  while (q.size()) {
    int x = q.front();
    q.pop();
    for (auto y : G[x]) {
      if (col[y] == 2 || gf(y) == gf(x)) continue;
      if (!col[y]) {
        col[y] = 2;
        usd.emplace_back(y);
        pre[y] = x;
        if (!mat[y]) {
          for (int k = y; k; y = k) k = mat[pre[y]], match(pre[y], y);
          return true;
        }
        col[mat[y]] = 1;
        q.emplace(mat[y]);
        usd.emplace_back(mat[y]);
      } else {
        int L = lca(x, y);
        blossom(x, y, L);
        blossom(y, x, L);
      }
    }
  }
  return false;
}
int solve() {
  for (int i = (1); i <= (n); i++) fa[i] = i, col[i] = vis[i] = mat[i] = 0;
  int ans = 0;
  for (int i = (1); i <= (n); i++)
    if (!mat[i]) ans += tmath(i);
  return ans;
}
}  // namespace blossom
int n, a[N], cur;
bool hav[N], ahav[N];
veg ed;
int main() {
  n = read<int>();
  for (int i = (1); i <= (n); i++)
    a[i] = read<int>(), (a[i] && (hav[a[i]] = true));
  for (int i = (2); i <= (n); i++)
    if (a[i] == a[i - 1]) ahav[a[i]] = true;
  ahav[0] = true;
  blossom ::n = n + 610;
  for (int i = (1); i <= (n); i++) {
    while (i <= n && a[i]) i++;
    if (i > n) break;
    int j = i;
    while (j <= n && !a[j]) j++;
    j--;
    ed.emplace_back(i, j);
    if ((j - i + 1) & 1) {
      if (i > 1 && !ahav[a[i - 1]]) blossom ::link(a[i - 1] + n, i);
      if (j < n && !ahav[a[j + 1]]) blossom ::link(a[j + 1] + n, i);
    } else {
      if (i > 1 && !ahav[a[i - 1]]) blossom ::link(a[i - 1] + n, i);
      if (j < n && !ahav[a[j + 1]]) blossom ::link(a[j + 1] + n, j);
      blossom ::link(i, j);
    }
    i = j;
  }
  blossom ::solve();
  cur = 1;
  for (auto v : ed) {
    int i, j;
    tie(i, j) = v;
    if ((j - i + 1) & 1) {
      if (i > 1 && !ahav[a[i - 1]] && blossom ::mat[a[i - 1] + n] == i) {
        a[i] = a[i - 1];
        for (int k = (i + 1); k <= (j - 1); k++) {
          while (hav[cur]) cur++;
          a[k] = a[k + 1] = cur;
          cur++;
          k++;
        }
      } else {
        a[j] = a[j + 1];
        for (int k = (i); k <= (j - 2); k++) {
          while (hav[cur]) cur++;
          a[k] = a[k + 1] = cur;
          cur++;
          k++;
        }
      }
    } else {
      if (blossom ::mat[i] == j) {
        for (int k = (i); k <= (j - 1); k++) {
          while (hav[cur]) cur++;
          a[k] = a[k + 1] = cur;
          cur++;
          k++;
        }
      } else {
        a[i] = a[i - 1];
        a[j] = a[j + 1];
        for (int k = (i + 1); k <= (j - 2); k++) {
          while (hav[cur]) cur++;
          a[k] = a[k + 1] = cur;
          cur++;
          k++;
        }
      }
    }
  }
  for (int i = (1); i <= (n); i++) printf("%d ", a[i] ? a[i] : 1);
  puts("");
  return 0;
}
