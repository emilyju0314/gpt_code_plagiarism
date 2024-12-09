#include <bits/stdc++.h>
using namespace std;
int head[602], ver[602 * 2], nxt[602 * 2], fa[602], dep[602], l;
int n, i, j, a[602], p[602], s[602], tmp[602], cnt, s1[602], cnt1, s2[602],
    cnt2, ans[602], len;
int query(int x, int *a) {
  if (x == 1) return 0;
  int ans;
  cout << "? " << x << endl;
  cout.flush();
  for (int i = 1; i <= x; i++) cout << a[i] << ' ';
  cout << endl;
  cout.flush();
  cin >> ans;
  return ans;
}
void insert(int x, int y) {
  l++;
  ver[l] = y;
  nxt[l] = head[x];
  head[x] = l;
}
void dfs(int x, int pre, int col) {
  if (col == 1)
    s1[++cnt1] = x;
  else
    s2[++cnt2] = x;
  fa[x] = pre;
  dep[x] = dep[pre] + 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (y != pre) dfs(y, x, 3 - col);
  }
}
int main() {
  srand(19491001);
  cin >> n;
  if (n == 1) {
    cout << "Y 1" << endl;
    cout.flush();
    cout << "1" << endl;
    cout.flush();
    return 0;
  }
  for (i = 2; i <= n; i++) s[++cnt] = i;
  p[1] = 1;
  for (i = 1; i < n; i++) {
    int l = 1, r = cnt, mid, num = 0, tmp = 0;
    if (i != 1) {
      for (j = 1; j <= i; j++) a[++num] = p[j];
      tmp = query(num, a);
    }
    while (l < r) {
      mid = (l + r) / 2;
      num = 0;
      for (j = l; j <= mid; j++) a[++num] = s[j];
      int res = query(num, a);
      for (j = 1; j <= i; j++) a[++num] = p[j];
      if (query(num, a) == res + tmp)
        l = mid + 1;
      else
        r = mid;
    }
    p[i + 1] = s[l];
    cnt--;
    for (j = l; j <= cnt; j++) s[j] = s[j + 1];
    l = 1, r = i;
    while (l < r) {
      mid = (l + r) / 2;
      num = 0;
      for (j = l; j <= mid; j++) a[++num] = p[j];
      int res = query(num, a);
      a[++num] = p[i + 1];
      if (query(num, a) > res)
        r = mid;
      else
        l = mid + 1;
    }
    insert(p[l], p[i + 1]);
    insert(p[i + 1], p[l]);
  }
  dfs(1, 0, 1);
  int c1 = query(cnt1, s1), c2 = query(cnt2, s2);
  if (c1 == 0 && c2 == 0) {
    cout << "Y " << cnt1 << endl;
    cout.flush();
    for (i = 1; i <= cnt1; i++) cout << s1[i] << ' ';
    cout << endl;
    cout.flush();
  } else {
    if (c1 != 0) {
      cnt = cnt1;
      for (i = 1; i <= cnt1; i++) s[i] = s1[i];
    } else {
      cnt = cnt2;
      for (i = 1; i <= cnt2; i++) s[i] = s2[i];
    }
    while (cnt > 2) {
      cnt1 = cnt2 = 0;
      for (i = 1; i <= cnt; i++) {
        if (rand() % 2 == 0)
          s1[++cnt1] = s[i];
        else
          s2[++cnt2] = s[i];
      }
      if (cnt1 == 0 || cnt2 == 0) continue;
      if (query(cnt1, s1) != 0) {
        for (i = 1; i <= cnt1; i++) s[i] = s1[i];
        cnt = cnt1;
      } else if (query(cnt2, s2) != 0) {
        for (i = 1; i <= cnt2; i++) s[i] = s2[i];
        cnt = cnt2;
      }
    }
    int u = s[1], v = s[2];
    cnt1 = cnt2 = 0;
    if (dep[u] < dep[v]) swap(u, v);
    while (dep[u] != dep[v]) s1[++cnt1] = u, u = fa[u];
    while (u != v) {
      s1[++cnt1] = u;
      s2[++cnt2] = v;
      u = fa[u];
      v = fa[v];
    }
    for (i = 1; i <= cnt1; i++) ans[++len] = s1[i];
    ans[++len] = u;
    for (i = cnt2; i >= 1; i--) ans[++len] = s2[i];
    cout << "N " << len << endl;
    cout.flush();
    for (i = 1; i <= len; i++) cout << ans[i] << ' ';
    cout << endl;
    cout.flush();
  }
  return 0;
}
