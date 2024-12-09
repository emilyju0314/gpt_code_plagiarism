#include <bits/stdc++.h>
using namespace std;
const int N = 50 * 1000 + 10, second = 400;
bool on[N], is[N];
int lz[N];
vector<int> st[N], r[N];
void add(int v, int u) {
  st[v].push_back(u);
  if (!is[v] && ((int)(st[v]).size()) == second) {
    is[v] = true;
    for (auto x : st[v]) {
      r[x].push_back(v);
      lz[v] += on[x];
    }
  } else if (is[v]) {
    r[u].push_back(v);
    lz[v] += on[u];
  }
}
void remove(int v, int u) {
  if (is[v] && ((int)(st[v]).size()) == second) {
    is[v] = false;
    for (auto x : st[v]) {
      for (int i = (0); i <= (((int)(r[x]).size()) - 1); i++)
        if (r[x][i] == v) {
          r[x].erase(r[x].begin() + i);
          break;
        }
      lz[v] -= on[x];
    }
  } else if (is[v]) {
    for (int i = (0); i <= (((int)(r[u]).size()) - 1); i++)
      if (r[u][i] == v) {
        r[u].erase(r[u].begin() + i);
        break;
      }
    lz[v] -= on[u];
  }
  for (int i = (0); i <= (((int)(st[v]).size()) - 1); i++)
    if (st[v][i] == u) {
      st[v].erase(st[v].begin() + i);
      break;
    }
}
void online(int id) {
  on[id] = true;
  for (auto x : r[id]) lz[x]++;
}
void offline(int id) {
  on[id] = false;
  for (auto x : r[id]) lz[x]--;
}
int count(int id) {
  if (is[id]) return lz[id];
  int ret = 0;
  for (auto x : st[id]) ret += on[x];
  return ret;
}
int main() {
  int n, m, q, o;
  scanf("%d%d%d%d", &n, &m, &q, &o);
  for (int i = (0); i <= (o - 1); i++) {
    int x;
    scanf("%d", &x);
    x--;
    online(x);
  }
  for (int i = (0); i <= (m - 1); i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    add(a, b);
    add(b, a);
  }
  while (q--) {
    char t;
    int v;
    scanf(" %c%d", &t, &v);
    v--;
    if (t == 'O')
      online(v);
    else if (t == 'F')
      offline(v);
    else if (t == 'A') {
      int u;
      scanf("%d", &u);
      u--;
      add(v, u);
      add(u, v);
    } else if (t == 'D') {
      int u;
      scanf("%d", &u);
      u--;
      remove(v, u);
      remove(u, v);
    } else
      printf("%d\n", count(v));
  }
  return 0;
}
