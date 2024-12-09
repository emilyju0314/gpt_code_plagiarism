#include <bits/stdc++.h>
using namespace std;
void RI() {}
template <typename... T>
void RI(int& head, T&... tail) {
  scanf("%d", &head);
  RI(tail...);
}
mt19937 rng(0x5EED);
int randint(int lb, int ub) {
  return uniform_int_distribution<int>(lb, ub)(rng);
}
const int LOG = 18;
const int MXN = 200005;
struct Operation {
  int t, v;
  char c;
} op[MXN];
struct BIT {
  int bit[MXN];
  void init() { memset((bit), 0, sizeof(bit)); }
  int lb(int a) { return a & -a; }
  void update(int id, int v) {
    for (int i = id; i < MXN; i += lb(i)) {
      bit[i] += v;
    }
  }
  long long query(int id) {
    long long ret = 0;
    for (int i = id; i > 0; i -= lb(i)) {
      ret += bit[i];
    }
    return ret;
  }
} bit1, bit2;
struct Tree {
  struct Node {
    int id, dep, f;
    char c;
  } node[MXN];
  int N;
  pair<int, int> rg[MXN];
  vector<int> E[MXN];
  void init() { node[N = 1] = {0, 0, 1, 0}; }
  int add(int id, int f, char c) {
    node[++N] = {id, node[f].dep + 1, f, c};
    E[f].push_back(N);
    return N;
  }
} strTree[2];
int N, treeID[MXN];
int pre[LOG][MXN], sa[MXN], rk[MXN], ct[MXN], tp[MXN][2], tsa[MXN];
int moveUP(int v, int len) {
  for (int i = 0; len; i++, len >>= 1) {
    if (len & 1) {
      v = pre[i][v];
    }
  }
  return v;
}
void buildSA(const Tree& tree) {
  for (int i = 1; i <= tree.N; i++) {
    pre[0][i] = tree.node[i].f;
    sa[i] = i;
    rk[i] = tree.node[i].c;
  }
  for (int i = 1; i < LOG; i++) {
    for (int j = 1; j <= tree.N; j++) {
      pre[i][j] = pre[i - 1][pre[i - 1][j]];
    }
  }
  int len = tree.N;
  int alp = 256;
  memset(ct, 0, sizeof(ct));
  for (int i = 0; i < len; i++) ct[tree.node[i + 1].c + 1]++;
  for (int i = 1; i < alp; i++) ct[i] += ct[i - 1];
  for (int i = 0; i < len; i++) rk[i] = ct[(int)tree.node[i + 1].c];
  for (int i = 1, cmpLv = 0; i < len; i *= 2, cmpLv++) {
    for (int j = 0; j < len; j++) {
      if (i >= tree.node[j + 1].dep)
        tp[j][1] = 0;
      else
        tp[j][1] = rk[pre[cmpLv][j + 1] - 1] + 1;
      tp[j][0] = rk[j];
    }
    memset(ct, 0, sizeof(ct));
    for (int j = 0; j < len; j++) ct[tp[j][1] + 1]++;
    for (int j = 1; j < len + 2; j++) ct[j] += ct[j - 1];
    for (int j = 0; j < len; j++) tsa[ct[tp[j][1]]++] = j;
    memset(ct, 0, sizeof(ct));
    for (int j = 0; j < len; j++) ct[tp[j][0] + 1]++;
    for (int j = 1; j < len + 1; j++) ct[j] += ct[j - 1];
    for (int j = 0; j < len; j++) sa[ct[tp[tsa[j]][0]]++] = tsa[j];
    rk[sa[0]] = 0;
    for (int j = 1; j < len; j++) {
      if (tp[sa[j]][0] == tp[sa[j - 1]][0] && tp[sa[j]][1] == tp[sa[j - 1]][1])
        rk[sa[j]] = rk[sa[j - 1]];
      else
        rk[sa[j]] = j;
    }
  }
  for (int i = len; i >= 1; i--) {
    sa[i] = sa[i - 1] + 1;
    rk[i] = rk[i - 1] + 1;
  }
}
int getL(int l, int r, int up, int cp) {
  if (l >= r) return l;
  while (l < r) {
    int mid = (l + r) / 2;
    int id = moveUP(sa[mid], up);
    if (cp <= strTree[1].node[id].c) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
int getR(int l, int r, int up, int cp) {
  if (l >= r) return r;
  while (l < r) {
    int mid = (l + r) / 2;
    int id = moveUP(sa[mid], up);
    if (cp < strTree[1].node[id].c) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
void DFS(int u, int f, int d, const vector<int> E[]) {
  int l = strTree[0].rg[f].first;
  int r = strTree[0].rg[f].second;
  int cp = strTree[0].node[u].c;
  strTree[0].rg[u] = make_pair(getL(l, r, d, cp), getR(l, r, d, cp));
  for (const auto& v : E[u]) DFS(v, u, d + 1, E);
}
void getRange() {
  strTree[0].rg[1] = make_pair(1, strTree[1].N + 1);
  for (const auto& v : strTree[0].E[1]) DFS(v, 1, 0, strTree[0].E);
}
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  strTree[0].init();
  strTree[1].init();
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> op[i].t >> op[i].v >> op[i].c;
    treeID[i] = strTree[op[i].t - 1].add(i, op[i].v, op[i].c);
  }
  buildSA(strTree[1]);
  getRange();
  long long ans = 1;
  bit1.init();
  bit2.init();
  for (int i = 1; i <= N; i++) {
    int id = treeID[i];
    if (op[i].t == 1) {
      pair<int, int> rg = strTree[0].rg[id];
      ans += bit2.query(rg.second - 1) - bit2.query(rg.first - 1);
      bit1.update(rg.first, 1);
      bit1.update(rg.second, -1);
    } else {
      ans += bit1.query(rk[id]);
      ans++;
      bit2.update(rk[id], 1);
    }
    cout << ans << "\n";
  }
  return 0;
}
