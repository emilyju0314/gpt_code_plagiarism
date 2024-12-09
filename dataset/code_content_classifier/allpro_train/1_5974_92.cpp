#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n, qn, w, a[100010], ans[100010], nxt[100010], t = 185;
vector<pair<int, int> > q, op[100010];
namespace lct {
int ch[100010][2], fa[100010], tag[100010], sz[100010];
void Init(int k) {
  ch[k][0] = ch[k][1] = fa[k] = tag[k] = 0;
  sz[k] = (k == 0 ? 0 : 1);
}
int getTy(int x) { return ch[fa[x]][1] == x; }
bool isRoot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
void pushUp(int x) {
  if (x == 0) return;
  sz[x] = sz[ch[x][0]] + 1 + sz[ch[x][1]];
}
void pushDown(int x) {
  if (tag[x] == 1) {
    if (ch[x][0] != 0) tag[ch[x][0]] ^= 1;
    if (ch[x][1] != 0) tag[ch[x][1]] ^= 1;
    swap(ch[ch[x][0]][0], ch[ch[x][0]][1]);
    swap(ch[ch[x][1]][0], ch[ch[x][1]][1]);
    tag[x] = 0;
  }
}
void upd(int x) {
  if (!isRoot(x)) upd(fa[x]);
  pushDown(x);
}
void rotate(int x) {
  int f = fa[x], ff = fa[f], ty = getTy(f);
  bool ok = isRoot(f);
  if (getTy(x) == 0) {
    ch[f][0] = ch[x][1];
    if (ch[x][1] != 0) fa[ch[x][1]] = f;
    ch[x][1] = f;
    fa[f] = x;
    if (!ok) ch[ff][ty] = x;
    fa[x] = ff;
  } else {
    ch[f][1] = ch[x][0];
    if (ch[x][0] != 0) fa[ch[x][0]] = f;
    ch[x][0] = f;
    fa[f] = x;
    if (!ok) ch[ff][ty] = x;
    fa[x] = ff;
  }
  pushUp(f);
  pushUp(x);
}
void spl(int x) {
  upd(x);
  while (!isRoot(x)) {
    int f = fa[x];
    if (isRoot(f))
      rotate(x);
    else if (getTy(f) == getTy(x))
      rotate(f), rotate(x);
    else
      rotate(x), rotate(x);
  }
}
int access(int x) {
  int nxt = 0;
  for (; x > 0; nxt = x, x = fa[x]) {
    spl(x);
    ch[x][1] = nxt;
    pushUp(x);
  }
  return nxt;
}
void makeRoot(int x) {
  x = access(x);
  tag[x] ^= 1;
  swap(ch[x][0], ch[x][1]);
}
int find(int x) {
  access(x);
  spl(x);
  pushDown(x);
  int ret = x;
  while (ch[ret][0] != 0) ret = ch[ret][0], pushDown(ret);
  spl(ret);
  return ret;
}
void link(int x, int y) {
  long long yrt = find(y);
  makeRoot(x);
  spl(x);
  fa[x] = y;
  makeRoot(yrt);
}
void cut(int x, int y) {
  int yrt = find(y);
  makeRoot(x);
  access(y);
  spl(y);
  ch[y][0] = 0;
  fa[x] = 0;
  makeRoot(x);
  makeRoot(yrt);
}
}  // namespace lct
namespace ST {
int mx[100010][22], mn[100010][22], lev[100010];
void calc() {
  for (int i = 0; i < n; ++i) mx[i][0] = mn[i][0] = a[i];
  for (int j = 0; j < 20; ++j)
    for (int i = 0; i < n; ++i) {
      mx[i][j + 1] =
          max(mx[i][j], (i + (1 << j) >= n ? (int)-2e9 : mx[i + (1 << j)][j]));
      mn[i][j + 1] =
          min(mn[i][j], (i + (1 << j) >= n ? (int)2e9 : mn[i + (1 << j)][j]));
    }
  for (int i = 1; i <= n + 5; ++i) lev[i] = floor(log(i) / log(2));
}
pair<int, int> qry(int lb, int ub) {
  int Lev = lev[ub - lb + 1];
  return make_pair(max(mx[lb][Lev], mx[ub - (1 << Lev) + 1][Lev]),
                   min(mn[lb][Lev], mn[ub - (1 << Lev) + 1][Lev]));
}
}  // namespace ST
int main() {
  cin >> n >> w >> qn;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  ST::calc();
  int x;
  for (int i = 0; i < qn; ++i) {
    scanf("%d", &x);
    q.push_back(make_pair(w - x, i));
  }
  sort(q.begin(), q.end());
  for (int i = 0; i < n; ++i) {
    lct::Init(i + 1);
    int mn = 1e9, mx = -1e9;
    vector<int> v;
    v.clear();
    for (int j = i; j < i + t && j < n; ++j) {
      mn = min(mn, a[j]);
      mx = max(mx, a[j]);
      v.push_back(lower_bound(q.begin(), q.end(), make_pair(mx - mn, 0)) -
                  q.begin());
    }
    for (int j = 0; j < v.size(); ++j) {
      if (j == v.size() - 1) {
        int xx =
            (i + j == n - 1 ? -1
                            : lower_bound(q.begin(), q.end(),
                                          make_pair(max(mx, a[i + j + 1]) -
                                                        min(mn, a[i + j + 1]),
                                                    0)) -
                                  q.begin());
        if (xx != v[j]) {
          op[v[j]].push_back(make_pair(i, i + j + 1));
          if (xx != -1) op[xx].push_back(make_pair(i, -1));
        } else
          op[v[j]].push_back(make_pair(i, -1));
      } else if (v[j] != v[j + 1])
        op[v[j]].push_back(make_pair(i, i + j + 1));
    }
  }
  lct::Init(n + 1);
  for (int i = 0; i < n + 1; ++i) nxt[i] = -1;
  for (int i = 0; i < qn; ++i) {
    for (int j = 0; j < op[i].size(); ++j) {
      if (op[i][j].second != -1) {
        if (nxt[op[i][j].first] != -1)
          lct::cut(op[i][j].first + 1, nxt[op[i][j].first] + 1);
        nxt[op[i][j].first] = op[i][j].second;
        lct::link(op[i][j].first + 1, nxt[op[i][j].first] + 1);
      } else if (nxt[op[i][j].first] != -1)
        lct::cut(op[i][j].first + 1, nxt[op[i][j].first] + 1);
    }
    int pos = 1, res = 0;
    while (true) {
      int top = lct::find(pos);
      lct::access(pos);
      lct::spl(pos);
      res += lct::sz[pos] - 1;
      pos = top;
      if (pos == n + 1) break;
      int lb = pos - 1, ub = n - 1, mid;
      while (lb < ub) {
        mid = (lb + ub + 1) >> 1;
        pair<int, int> val = ST::qry(pos - 1, mid);
        if (val.first - val.second <= q[i].first)
          lb = mid;
        else
          ub = mid - 1;
      }
      pos = lb + 2;
      ++res;
    }
    ans[q[i].second] = res - 1;
  }
  for (int i = 0; i < qn; ++i) printf("%d\n", ans[i]);
  return 0;
}
