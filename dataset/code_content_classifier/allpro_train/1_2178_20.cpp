#include <bits/stdc++.h>
const int N = 100005;
using namespace std;
int r[N][4];
bool lr(int x, int y) { return r[x][0] < r[y][0]; }
bool rl(int x, int y) { return r[x][2] > r[y][2]; }
bool bt(int x, int y) { return r[x][1] < r[y][1]; }
bool tb(int x, int y) { return r[x][3] > r[y][3]; }
int w[4][2] = {{0, 2}, {2, 0}, {1, 3}, {3, 1}};
bool check(vector<int> v) {
  if (v.size() == 1) return true;
  vector<int> q[4];
  int i, j;
  for (i = 0; i < 4; i++) q[i] = v;
  sort(q[0].begin(), q[0].end(), lr);
  sort(q[1].begin(), q[1].end(), rl);
  sort(q[2].begin(), q[2].end(), bt);
  sort(q[3].begin(), q[3].end(), tb);
  int sz = v.size();
  bool used[N];
  memset(used, false, sizeof(used));
  vector<int> nxt[4];
  int maxe[4], ptr[4], prev[4];
  for (i = 0; i < 4; i++) ptr[i] = 0;
  while (sz > 1) {
    bool f = false;
    for (i = 0; i < 4; i++) {
      while (used[q[i][ptr[i]]]) ptr[i]++;
      maxe[i] = r[q[i][ptr[i]]][w[i][1]];
      nxt[i].clear();
      nxt[i].push_back(q[i][ptr[i]]);
      prev[i] = ptr[i];
    }
    for (j = 1; j <= sz / 2; j++) {
      for (i = 0; i < 4; i++) {
        ptr[i]++;
        while (used[q[i][ptr[i]]]) ptr[i]++;
        if (((i & 1) && maxe[i] >= r[q[i][ptr[i]]][w[i][0]]) ||
            (((~i & 1)) && maxe[i] <= r[q[i][ptr[i]]][w[i][0]])) {
          if (!check(nxt[i]))
            return false;
          else {
            f = true;
            for (int k = 0; k < nxt[i].size(); k++) used[nxt[i][k]] = true;
            for (int k = 0; k < 4; k++)
              if (k != i) ptr[k] = prev[k];
            sz -= nxt[i].size();
            break;
          }
        }
        if (i & 1)
          maxe[i] = min(maxe[i], r[q[i][ptr[i]]][w[i][1]]);
        else
          maxe[i] = max(maxe[i], r[q[i][ptr[i]]][w[i][1]]);
        nxt[i].push_back(q[i][ptr[i]]);
      }
      if (f) break;
    }
    if (!f) return false;
  }
  if (sz <= 1) return true;
  return true;
}
vector<int> p;
int main() {
  int n, i, j;
  scanf("%d", &n);
  int a, b, c, d;
  for (i = 0; i < n; i++) {
    p.push_back(i);
    for (j = 0; j < 4; j++) scanf("%d", &r[i][j]);
  }
  if (check(p))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
