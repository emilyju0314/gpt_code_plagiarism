#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int INF = 0x3f3f3f3f;
int m, n;
const int maxm = 2 * 1e5 + 20;
struct Operation {
  int kind;
  int x, y;
} op[maxm];
vector<int> ve;
set<int> pos[maxm];
map<int, int> mp;
char s[15];
void readop(int ind) {
  Operation& now = op[ind];
  scanf("%s", s);
  if (s[0] == 'f')
    now.kind = 0;
  else if (s[0] == 'a')
    now.kind = 1;
  else
    now.kind = -1;
  scanf("%d%d", &now.x, &now.y);
  ve.push_back(now.x);
}
struct Segmenttree {
  int maxi[4 * maxm];
  void build(int ind, int le, int ri) {
    if (le == ri) {
      maxi[ind] = -1;
      return;
    }
    int mid = (le + ri) >> 1;
    build(ind << 1, le, mid);
    build(ind << 1 | 1, mid + 1, ri);
    maxi[ind] = max(maxi[ind * 2], maxi[ind * 2 + 1]);
  }
  void add(int ind, int le, int ri, int x, int y) {
    if (le == ri) {
      maxi[ind] = max(maxi[ind], y);
      pos[le].insert(y);
      return;
    }
    int mid = (le + ri) >> 1;
    if (x <= mid)
      add(ind << 1, le, mid, x, y);
    else
      add(ind << 1 | 1, mid + 1, ri, x, y);
    maxi[ind] = max(maxi[ind * 2], maxi[ind * 2 + 1]);
  }
  void remove(int ind, int le, int ri, int x, int y) {
    if (le == ri) {
      pos[le].erase(y);
      maxi[ind] = pos[le].empty() ? -1 : *(--pos[le].end());
      return;
    }
    int mid = (le + ri) >> 1;
    if (x <= mid)
      remove(ind << 1, le, mid, x, y);
    else
      remove(ind << 1 | 1, mid + 1, ri, x, y);
    maxi[ind] = max(maxi[2 * ind], maxi[2 * ind + 1]);
  }
  pair<int, int> query(int ind, int le, int ri, int x, int y) {
    if (y > maxi[ind]) return make_pair(-1, -1);
    if (le == ri) {
      return make_pair(le, *pos[le].lower_bound(y));
    }
    int mid = (le + ri) >> 1;
    pair<int, int> tmp =
        x <= mid ? query(ind << 1, le, mid, x, y) : make_pair(-1, -1);
    if (tmp.first != -1) return tmp;
    return query(ind << 1 | 1, mid + 1, ri, x, y);
  }
} sgt;
int main() {
  while (~scanf("%d", &m)) {
    ve.clear();
    mp.clear();
    for (int i = 1; i <= m; i++) readop(i);
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    n = ve.size();
    for (int i = 0; i < n; i++) {
      int x = ve[i];
      mp[x] = i;
    }
    for (int i = 0; i < n; i++) pos[i].clear();
    sgt.build(1, 0, n);
    for (int i = 1; i <= m; i++) {
      int kind = op[i].kind;
      int x = op[i].x, y = op[i].y;
      if (kind == 1)
        sgt.add(1, 0, n, mp[x], y);
      else if (kind == -1)
        sgt.remove(1, 0, n, mp[x], y);
      else {
        pair<int, int> pa = sgt.query(1, 0, n, mp[x] + 1, y + 1);
        if (pa.first == -1)
          puts("-1");
        else
          printf("%d %d\n", ve[pa.first], pa.second);
      }
    }
  }
  return 0;
}
