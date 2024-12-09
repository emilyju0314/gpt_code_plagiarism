#include <bits/stdc++.h>
using namespace std;
namespace SHENZHEBEI {
static const int GYN = 2333333;
char SZB[GYN], *SS = SZB, *TT = SZB;
inline char gc() {
  if (SS == TT) {
    TT = (SS = SZB) + fread(SZB, 1, GYN, stdin);
    if (SS == TT) return '\n';
  }
  return *SS++;
}
inline long long read() {
  long long x = 0, g = 1;
  char ch = gc();
  for (; !isdigit(ch); ch = gc())
    if (ch == '-') g = -1;
  for (; isdigit(ch); ch = gc()) x = x * 10 - 48 + ch;
  return x * g;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline char readchar() {
  char ch = gc();
  for (; isspace(ch); ch = gc())
    ;
  return ch;
}
inline long long readstr(char *s) {
  char ch = gc();
  int cur = 0;
  for (; isspace(ch); ch = gc())
    ;
  for (; !isspace(ch); ch = gc()) s[cur++] = ch;
  s[cur] = '\0';
  return cur;
}
void Print(long long *a, int s, int t) {
  for (int i = (long long)(s); i <= (long long)(t); ++i) printf("%lld ", a[i]);
}
void Print(int *a, int s, int t) {
  for (int i = (long long)(s); i <= (long long)(t); ++i) printf("%d ", a[i]);
}
void Print(char *a, int s, int t) {
  for (int i = (long long)(s); i <= (long long)(t); ++i) putchar(a[i]);
}
void writeln(long long x) {
  write(x);
  puts("");
}
void Min(long long &x, long long y) { x = x < y ? x : y; }
void Max(long long &x, long long y) { x = x > y ? x : y; }
}  // namespace SHENZHEBEI
using namespace SHENZHEBEI;
const long long N = 400010;
vector<long long> g[N];
vector<long long> lzh;
long long dep[N], a[N], b[N], fa[N], vis[N], cqz, n, zyy, sum, best, Best, Rt,
    id1, id2, ans;
void dfs(long long x) {
  for (int i = (long long)(0); i < (long long)(g[x].size()); ++i) {
    long long to = g[x][i];
    if (to == fa[x]) continue;
    fa[to] = x;
    dep[to] = dep[x] + 1;
    dfs(to);
  }
}
long long lca(long long x, long long y) {
  for (; x != y; x = fa[x])
    if (dep[x] < dep[y]) swap(x, y);
  return x;
}
bool fafa() {
  best = 0, Best = 0;
  for (int i = (long long)(1); i <= (long long)(n); ++i)
    if (a[i] != b[i]) best = dep[best] < dep[i] ? i : best;
  if (!best) return 1;
  for (long long i = best; vis[i] = 1, lzh.push_back(i), a[fa[i]] != b[fa[i]];
       i = fa[i])
    ;
  for (int i = (long long)(1); i <= (long long)(n); ++i)
    if (a[i] != b[i] && !vis[i]) Best = dep[Best] < dep[i] ? i : Best;
  if (Best) {
    reverse(lzh.begin(), lzh.end());
    for (long long i = Best; vis[i] = 1, lzh.push_back(i), a[fa[i]] != b[fa[i]];
         i = fa[i])
      ;
  } else
    Best = fa[lzh.back()];
  for (int i = (long long)(1); i <= (long long)(n); ++i)
    if (a[i] != b[i] && !vis[i]) return 0;
  Rt = lca(best, Best);
  if (lzh.size() != dep[best] + dep[Best] - 2 * dep[Rt]) return 0;
  return 1;
}
int main() {
  n = read();
  for (int i = (long long)(1); i <= (long long)(n); ++i)
    a[i] = read(), id1 = a[i] ? id1 : i;
  for (int i = (long long)(1); i <= (long long)(n); ++i)
    b[i] = read(), id2 = b[i] ? id2 : i;
  for (int i = (long long)(1); i < (long long)(n); ++i) {
    long long a = read(), b = read();
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dep[0] = -1;
  dfs(id2);
  for (long long i = id1; i != id2; i = fa[i]) swap(a[i], a[fa[i]]);
  ans = dep[id1];
  if (!fafa()) return puts("-1"), 0;
  if (!lzh.size()) return printf("0 %lld\n", ans), 0;
  zyy = 0, sum = lzh.size();
  for (int i = (long long)(0); i < (long long)(sum); ++i)
    if (b[lzh[i]] == a[lzh[0]]) zyy = i;
  for (int i = (long long)(1); i < (long long)(sum); ++i)
    if (b[lzh[(i + zyy) % sum]] != a[lzh[i]]) return puts("-1"), 0;
  memset(vis, 0, sizeof vis);
  for (long long i = id1; i; i = fa[i]) vis[i] = 1;
  if (vis[lzh[0]] || vis[lzh.back()]) {
    for (int i = (long long)(0); i < (long long)(sum); ++i)
      if (!vis[lzh[i]]) {
        cqz = i;
        break;
      }
    ans +=
        -cqz + ((cqz + zyy * (sum + 1)) < (abs((sum - zyy) * (sum + 1) - cqz))
                    ? (cqz + zyy * (sum + 1))
                    : (abs((sum - zyy) * (sum + 1) - cqz)));
  } else
    ans += ((zyy) < (sum - zyy) ? (zyy) : (sum - zyy)) * (sum + 1);
  for (; !vis[Rt]; Rt = fa[Rt]) ans += 2;
  if (best > Best) swap(best, Best);
  printf("%lld %lld %lld\n", best, Best, ans);
}
