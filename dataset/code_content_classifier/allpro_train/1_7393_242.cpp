#include <bits/stdc++.h>
using namespace std;
int a[200001];
vector<int> g[200001];
char sign[200001];
int in[200001];
int out[200001];
int timer = 0;
int t[262144 * 2];
inline void push(int v) {
  t[v * 2] += t[v];
  t[v * 2 + 1] += t[v];
  t[v] = 0;
}
void add(int l, int r, int val, int v = 1, int cl = 0, int cr = 262144) {
  if (l <= cl && cr <= r) {
    t[v] += val;
    return;
  }
  if (r <= cl || cr <= l) return;
  push(v);
  int cc = (cl + cr) / 2;
  add(l, r, val, v * 2, cl, cc);
  add(l, r, val, v * 2 + 1, cc, cr);
}
int get(int id, int v = 1, int cl = 0, int cr = 262144) {
  if (cl + 1 == cr) return t[v];
  push(v);
  int cc = (cl + cr) / 2;
  if (id >= cc)
    return get(id, v * 2 + 1, cc, cr);
  else
    return get(id, v * 2, cl, cc);
}
void precalc(int u, int prev = -1, char s = 0) {
  sign[u] = s;
  in[u] = timer++;
  for (int i = 0; i < (int)g[u].size(); ++i) {
    int v = g[u][i];
    if (v == prev) continue;
    precalc(v, u, s ^ 1);
  }
  out[u] = timer;
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  precalc(0);
  for (int i = 0; i < n; ++i)
    if (sign[i])
      t[in[i] + 262144] = -a[i];
    else
      t[in[i] + 262144] = a[i];
  for (int i = 0; i < q; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int id, val;
      cin >> id >> val;
      --id;
      if (sign[id]) val = -val;
      add(in[id], out[id], val);
    } else {
      int id;
      cin >> id;
      --id;
      int res = get(in[id]);
      if (sign[id]) res = -res;
      cout << res << '\n';
    }
  }
}
