#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int maxn = 6e5 + 5;
char s[maxn];
int a[maxn], b[maxn], n, tot, m, p[maxn], c[maxn], cnt[26], st[maxn], top;
bool vis[maxn];
vector<pair<int, int> > ans, res;
void add(int x, int y) {
  while (x <= n) b[x] += y, x += x & (-x);
}
int qry(int x) {
  int ret = 0;
  while (x) ret += b[x], x -= x & (-x);
  return ret;
}
int nowid() {
  for (int i = 0; i < 26; i++)
    if (cnt[i] >= tot / 2) return i;
  return -1;
}
void solve(int m) {
  int id = -1;
  tot = m;
  top = 0;
  int x = -1;
  for (int i = 1; i <= m; i++) {
    st[++top] = i;
    if (x == -1) x = nowid();
    if (x == -1) {
      if (top > 1 && c[st[top - 1]] != c[st[top]]) {
        int u = st[top - 1], v = st[top];
        res.push_back((pair<int, int>){u, v});
        cnt[c[u]]--;
        cnt[c[v]]--;
        top -= 2;
        tot -= 2;
      }
    } else {
      if (top > 1 && ((c[st[top - 1]] == x) ^ (c[st[top]] == x))) {
        int u = st[top - 1], v = st[top];
        res.push_back((pair<int, int>){u, v});
        cnt[c[u]]--;
        cnt[c[v]]--;
        top -= 2;
        tot -= 2;
      }
    }
  }
  while (top) res.push_back((pair<int, int>){st[top], -1}), top--;
}
void solve(int l, int r) {
  int L = qry(l), R = qry(r);
  add(r, L - R);
  ans.push_back((pair<int, int>){L + 1, R});
}
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    m = 0;
    res.clear();
    ans.clear();
    for (int i = 1; i < n; i++)
      if (s[i] == s[i + 1]) p[++m] = i;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= m; i++) c[i] = s[p[i]] - 'a', cnt[c[i]]++, vis[i] = 0;
    solve(m);
    for (int i = 1; i <= n; i++) b[i] = i & -i;
    for (auto x : res) {
      if (x.second == -1)
        solve(p[x.first], n);
      else
        solve(p[x.first], p[x.second]);
    }
    solve(0, n);
    printf("%d\n", ans.size());
    for (auto x : ans) printf("%d %d\n", x.first, x.second);
  }
  return 0;
}
