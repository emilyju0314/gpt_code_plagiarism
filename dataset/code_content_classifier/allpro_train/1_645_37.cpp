#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
const int MOD = 1000000007;
const int N = 50000 * 12, M = N * 4;
struct Edge {
  int x, y, nxt;
} e[M];
int hd[N], color[N], tail, m, d[N], tot;
vector<int> rub;
vector<pair<int, int> > vec[N];
void addedge(int x, int y, int tx, int ty) {
  e[++tail].x = tx, e[tail].y = ty, e[tail].nxt = hd[x << 1 | y],
  hd[x << 1 | y] = tail;
}
void add(int x, int y, int tx, int ty) {
  addedge(x, y ^ 1, tx, ty), addedge(tx, ty ^ 1, x, y);
}
void clear() {
  for (int i = 0; i < (rub).size(); i++) color[rub[i]] = -1;
}
bool setcolor(int x, int y) {
  if (color[x] == y) return 0;
  if (color[x] == (y ^ 1)) return 1;
  color[x] = y, rub.push_back(x);
  for (int i = hd[((x << 1 | y))]; i; i = e[i].nxt) {
    int tx = e[i].x, ty = e[i].y;
    if (setcolor(tx, ty)) return 1;
  }
  return 0;
}
bool ok(int t) {
  memset(color, -1, sizeof(color));
  rub.clear();
  for (int i = (1); i <= (m); i++)
    if (d[i] > t && setcolor(i, 0)) return 0;
  for (int i = (1); i <= (m); i++) {
    if (color[i] != -1) continue;
    for (int j = (0); j <= (1); j++) {
      rub.clear();
      if (setcolor(i, j))
        clear();
      else
        break;
    }
    if (color[i] == -1) return 0;
  }
  return 1;
}
int main() {
  int n, x, y, c;
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); i++) {
    scanf("%d%d%d%d", &x, &y, &c, &d[i]);
    vec[x].push_back(make_pair(c, i)), vec[y].push_back(make_pair(c, i));
  }
  tot = m;
  for (int i = (1); i <= (n); i++) {
    sort(vec[i].begin(), vec[i].end());
    for (int j = 0; j < (vec[i]).size(); j++) {
      int l = vec[i][j].second, l1 = ++tot, l2 = ++tot;
      add(l, 1, l1, 1), add(l, 0, l2, 1);
      if (j) {
        int r = vec[i][j - 1].second, r1 = tot - 3, r2 = tot - 2;
        if (vec[i][j].first == vec[i][j - 1].first) {
          add(r1, 0, l, 1);
          add(r1, 0, l1, 1);
        }
        add(r2, 0, l, 0);
        add(r2, 0, l2, 1);
      }
    }
  }
  int ll = 0, rr = inf;
  while (ll < rr) {
    int mid = (ll + rr) >> 1;
    if (ok(mid))
      rr = mid;
    else
      ll = mid + 1;
  }
  if (ok(ll)) {
    puts("Yes");
    vector<int> ans;
    for (int i = (1); i <= (m); i++)
      if (color[i] == 1) ans.push_back(i);
    printf("%d %d\n", ll, ans.size());
    for (int i = 0; i < (ans).size(); i++)
      printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
  } else
    puts("No");
}
