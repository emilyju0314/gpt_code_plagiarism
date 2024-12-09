#include <bits/stdc++.h>
using namespace std;
int t[800005], lazy[800005], tin[300005], tout[300005], timer = 0;
vector<int> g[300005];
void dfs(int v) {
  tin[v] = timer;
  timer++;
  for (int to : g[v]) {
    dfs(to);
  }
  tout[v] = timer;
}
void push(int v, int sz) {
  if (!lazy[v]) return;
  t[v * 2] = sz / 2 - t[v * 2];
  t[(v * 2) + 1] = sz / 2 - t[(v * 2) + 1];
  lazy[v * 2] ^= lazy[v];
  lazy[(v * 2) + 1] ^= lazy[v];
  lazy[v] = 0;
  return;
}
long long sum(int v, int cl, int cr, int l, int r) {
  if (cr <= l || cl >= r) return 0;
  if (cl >= l && cr <= r) return t[v];
  int mid = (cr + cl) / 2;
  push(v, cr - cl);
  return sum(v * 2, cl, mid, l, r) + sum(v * 2 + 1, mid, cr, l, r);
}
void modify(int v, int cl, int cr, int l, int r) {
  if (cr <= l || cl >= r) return;
  if (l <= cl && cr <= r) {
    lazy[v] ^= 1;
    t[v] = (cr - cl) - t[v];
    return;
  }
  int mid = (cl + cr) / 2;
  push(v, cr - cl);
  modify(v * 2, cl, mid, l, r);
  modify((v * 2) + 1, mid, cr, l, r);
  t[v] = t[v * 2] + t[(v * 2) + 1];
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    x--;
    g[x].push_back(i);
  }
  dfs(0);
  int tn = 1;
  while (tn < n) {
    tn *= 2;
  }
  for (int i = 0; i < n; i++) {
    cin >> t[tin[i] + tn];
  }
  for (int i = tn - 1; i > 0; i--) {
    t[i] = t[i * 2] + t[i * 2 + 1];
  }
  int m;
  cin >> m;
  while (m--) {
    string s;
    cin >> s;
    if (s == "get") {
      int x;
      cin >> x;
      x--;
      cout << sum(1, 0, tn, tin[x], tout[x]) << endl;
    } else {
      int x;
      cin >> x;
      x--;
      modify(1, 0, tn, tin[x], tout[x]);
    }
  }
}
