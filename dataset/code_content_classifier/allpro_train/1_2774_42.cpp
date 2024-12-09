#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 40;
const int inf = 0x3fffff;
void read(int &x) {
  char ch;
  bool flag = 0;
  for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1);
       ch = getchar())
    ;
  for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar())
    ;
  x *= 1 - 2 * flag;
}
int n, m;
int ru[maxn], chu[maxn];
vector<int> vec[maxn];
int res = inf;
int val[maxn];
void dfs(int cnt, int fa, int st) {
  res = min(res, val[cnt]);
  int siz = vec[cnt].size();
  if (siz == 0) {
    printf("%d %d %d\n", st, cnt, res);
    return;
  }
  for (int i = 0; i < siz; i++) {
    if (vec[cnt][i] != fa) dfs(vec[cnt][i], cnt, st);
  }
}
int main() {
  read(n), read(m);
  if (m == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i <= n; i++) val[i] = 10000000;
  memset(ru, 0, sizeof(ru));
  memset(chu, 0, sizeof(chu));
  for (int i = 0; i < m; i++) {
    int l, r;
    int va;
    read(l), read(r);
    read(va);
    vec[l].push_back(r);
    val[l] = va;
    chu[l]++, ru[r]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!ru[i] && !chu[i]) continue;
    if (!ru[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    if (!ru[i] && chu[i]) {
      res = inf;
      dfs(i, -1, i);
    }
  }
  return 0;
}
