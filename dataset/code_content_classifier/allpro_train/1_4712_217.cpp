#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
const int maxn = 411111;
const int mod = (int)(1e9 + 7);
struct node {
  int b, c, cnt, id;
  node() {}
  node(int b, int c, int cnt, int id) : b(b), c(c), cnt(cnt), id(id) {}
  bool operator<(const node& tmp) const { return c > tmp.c; }
} f[maxn];
bool cmp(node x, node y) { return x.b < y.b; }
int n, m, s;
int a[maxn];
int b[maxn];
int c[maxn];
pair<int, int> p[maxn];
int cnt[maxn];
int ans[maxn];
int res[maxn];
bool used[maxn];
bool go(int c) {
  int i, j;
  memset(used, false, sizeof(used));
  memset(ans, 0, sizeof(ans));
  for (i = 0; i < n; ++i) {
    f[i].cnt = c;
    cnt[i] = c;
  }
  priority_queue<node> q;
  int tot = 0;
  for (i = m - 1, j = n - 1; i >= 0; --i) {
    while (j >= 0 && f[j].b >= p[i].first) {
      q.push(f[j]);
      --j;
    }
    if (!q.empty()) {
      while (!q.empty()) {
        node top = q.top();
        q.pop();
        if (!used[top.id] && tot + top.c > s) {
          continue;
        }
        used[top.id] = true;
        tot += top.c;
        top.c = 0;
        ans[p[i].second] = top.id + 1;
        top.cnt--;
        if (top.cnt) {
          q.push(top);
        }
        break;
      }
    } else {
      return false;
    }
  }
  for (i = 0; i < m; ++i)
    if (!ans[i]) return false;
  return true;
}
int main() {
  int i;
  scanf("%d%d%d", &n, &m, &s);
  for (i = 0; i < m; ++i) {
    scanf("%d", a + i);
    p[i] = pair<int, int>(a[i], i);
  }
  for (i = 0; i < n; ++i) {
    scanf("%d", b + i);
  }
  for (i = 0; i < n; ++i) {
    scanf("%d", c + i);
  }
  for (i = 0; i < n; ++i) {
    f[i] = node(b[i], c[i], 0, i);
  }
  sort(p, p + m);
  sort(f, f + n, cmp);
  int l = 1, r = m, mid;
  bool flag = false;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (go(mid)) {
      memcpy(res, ans, sizeof(res));
      flag = true;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (flag) {
    puts("YES");
    for (i = 0; i < m; ++i) {
      if (i) printf(" ");
      printf("%d", res[i]);
    }
    puts("");
  } else {
    puts("NO");
  }
  return 0;
}
