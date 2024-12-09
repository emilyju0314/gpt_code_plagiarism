#include <bits/stdc++.h>
using namespace std;
const int MAX_L = 200;
map<int, pair<int, int> > ds;
int ops[MAX_L];
int powmod(int a, int n, int mod) {
  int pm = 1;
  while (n > 0) {
    if (n & 1) pm = (long long)pm * a % mod;
    a = (long long)a * a % mod;
    n >>= 1;
  }
  return pm;
}
bool check(int v, int u, int uc, queue<int> &q, int &mst, int &mgl) {
  map<int, pair<int, int> >::iterator mit = ds.find(v);
  if (mit != ds.end()) {
    if (uc * mit->second.first < 0) {
      if (uc > 0)
        mst = u, mgl = v;
      else
        mst = v, mgl = u;
      return true;
    }
  } else {
    ds[v] = pair<int, int>(uc, u);
    q.push(v);
  }
  return false;
}
int getop(int u, int v, int p) {
  if ((u + 1) % p == v) return 1;
  if ((u + p - 1) % p == v) return 2;
  return 3;
}
int main() {
  int st, gl, p;
  scanf("%d%d%d", &st, &gl, &p);
  if (st == gl) {
    puts("2\n1 2");
    return 0;
  }
  ds[st] = pair<int, int>(1, -1);
  ds[gl] = pair<int, int>(-1, -1);
  queue<int> q;
  q.push(st), q.push(gl);
  int mst = -1, mgl = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    pair<int, int> ud = ds[u];
    int uc = ud.first, up = ud.second;
    if (check((u + 1) % p, u, uc, q, mst, mgl) ||
        check((u + p - 1) % p, u, uc, q, mst, mgl) ||
        check(powmod(u, p - 2, p), u, uc, q, mst, mgl))
      break;
  }
  vector<int> vst, vgl;
  for (int u = mst; u >= 0; u = ds[u].second) vst.push_back(u);
  for (int u = mgl; u >= 0; u = ds[u].second) vgl.push_back(u);
  int l = 0;
  for (int i = vst.size() - 1; i > 0; i--)
    ops[l++] = getop(vst[i], vst[i - 1], p);
  ops[l++] = getop(mst, mgl, p);
  for (int i = 0; i + 1 < vgl.size(); i++)
    ops[l++] = getop(vgl[i], vgl[i + 1], p);
  printf("%d\n", l);
  for (int i = 0; i < l; i++) printf("%d%c", ops[i], (i + 1 < l) ? ' ' : '\n');
  return 0;
}
