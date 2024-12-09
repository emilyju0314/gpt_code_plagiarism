#include <bits/stdc++.h>
using namespace std;
int n, m;
int v[22][22];
int cnt[22], ord[22];
bool got[22];
bool chk;
int cmp(int id1, int id2) {
  if (cnt[id1] != cnt[id2]) return cnt[id1] < cnt[id2];
  return id1 < id2;
}
void greed(int st) {
  memset(got, false, sizeof got);
  int cur = st;
  for (int i = 1; i < n; i++) {
    got[cur] = true;
    bool found = false;
    for (int j = 1; j <= n && !found; j++) {
      int nxt = ord[j];
      if (got[nxt]) continue;
      if (v[cur][nxt] || v[nxt][cur]) {
        found = true;
        cur = nxt;
      }
    }
    if (!found) return;
  }
  chk = true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    v[x][y] = true;
  }
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (v[i][j]) {
        cnt[i]++;
        cnt[j]++;
      }
  for (int i = 1; i <= n; i++) ord[i] = i;
  sort(ord + 1, ord + n + 1, cmp);
  chk = false;
  for (int i = 1; i <= n && !chk; i++) greed(i);
  puts(chk ? "Yes" : "No");
  return 0;
}
