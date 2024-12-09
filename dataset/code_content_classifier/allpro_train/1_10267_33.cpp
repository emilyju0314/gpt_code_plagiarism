#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000 + 10;
const int maxn = 2105;
int n, s, m, val[maxn], a[maxn], st[maxn], ed[maxn];
int stfrom[maxn], edfrom[maxn], stans[maxn], edans[maxn][2];
int dist(int i, int j) {
  if (i <= j)
    return j - i;
  else
    return n - (i - j);
}
void init() {
  scanf("%d%d", &n, &s);
  s--;
  m = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    val[m++] = a[i];
  }
  sort(val, val + m);
  m = unique(val, val + m) - val;
  for (int i = 0; i <= n; i++) st[i] = ed[i] = inf;
  memset(stans, 0, sizeof stans);
  memset(edans, 0, sizeof edans);
  memset(stfrom, -1, sizeof stfrom);
  memset(edfrom, -1, sizeof edfrom);
  for (int i = 0; i < n; i++)
    if (a[i] == val[0]) {
      if (dist(s, i) < st[i]) {
        st[i] = dist(s, i);
        stans[i] = dist(s, i);
        stfrom[i] = -1;
      }
      if (dist(i, s) < st[i]) {
        st[i] = dist(i, s);
        stans[i] = -dist(i, s);
        stfrom[i] = -1;
      }
    }
}
vector<int> ans;
bool vis[maxn];
int q[maxn];
void out(int x) {
  if (x == -1) return;
  ans.push_back(edans[x][1]);
  ans.push_back(edans[x][0]);
  x = edfrom[x];
  ans.push_back(stans[x]);
  x = stfrom[x];
  out(x);
}
void solve() {
  for (int v = 0; v < m; v++) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (a[i] == val[v]) cnt++;
    if (cnt == 1) {
      for (int i = 0; i < n; i++)
        if (a[i] == val[v]) {
          ed[i] = st[i];
          edfrom[i] = i;
        }
    }
    for (int i = 0; i < n; i++)
      if (a[i] == val[v]) {
        int lst = i;
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n)
          if (a[j] == val[v]) {
            if (st[i] + dist(i, lst) + dist(j, lst) < ed[j]) {
              ed[j] = st[i] + dist(i, lst) + dist(j, lst);
              edans[j][0] = dist(i, lst);
              edans[j][1] = -dist(j, lst);
              edfrom[j] = i;
            }
            lst = j;
          }
        lst = i;
        for (int j = (i - 1 + n) % n; j != i; j = (j - 1 + n) % n)
          if (a[j] == val[v]) {
            if (st[i] + dist(lst, i) + dist(lst, j) < ed[j]) {
              ed[j] = st[i] + dist(lst, i) + dist(lst, j);
              edans[j][0] = -dist(lst, i);
              edans[j][1] = dist(lst, j);
              edfrom[j] = i;
            }
            lst = j;
          }
      }
    if (v + 1 == m) break;
    for (int i = 0; i < n; i++)
      if (a[i] == val[v]) {
        for (int j = 0; j < n; j++)
          if (a[j] == val[v + 1]) {
            if (ed[i] + dist(i, j) < st[j]) {
              st[j] = ed[i] + dist(i, j);
              stans[j] = dist(i, j);
              stfrom[j] = i;
            }
            if (ed[i] + dist(j, i) < st[j]) {
              st[j] = ed[i] + dist(j, i);
              stans[j] = -dist(j, i);
              stfrom[j] = i;
            }
          }
      }
  }
  ans.clear();
  int best = -1;
  for (int i = 0; i < n; i++)
    if (a[i] == val[m - 1]) {
      if (best == -1 || ed[i] < ed[best]) best = i;
    }
  out(best);
  printf("%d\n", ed[best]);
  int top = 0, curp = s, curv = 0;
  for (int i = 0; i < n; i++) val[i] = a[i];
  sort(val, val + n);
  memset(vis, 0, sizeof vis);
  q[top++] = s;
  if (!vis[curp] && a[curp] == val[curv]) {
    vis[curp] = 1;
    q[top++] = curp;
    curv++;
  }
  while (!ans.empty()) {
    int move = ans.back();
    ans.pop_back();
    int d = move < 0 ? n - 1 : 1;
    for (int i = 0; i < abs(move); i++) {
      curp = (curp + d) % n;
      if (!vis[curp]) {
      }
      if (!vis[curp] && a[curp] == val[curv]) {
        vis[curp] = 1;
        q[top++] = curp;
        curv++;
      }
    }
  }
  for (int i = 1; i < top; i++) {
    if (dist(q[i - 1], q[i]) <= dist(q[i], q[i - 1]))
      printf("+%d\n", dist(q[i - 1], q[i]));
    else
      printf("-%d\n", dist(q[i], q[i - 1]));
  }
}
int main() {
  init();
  solve();
  return 0;
}
