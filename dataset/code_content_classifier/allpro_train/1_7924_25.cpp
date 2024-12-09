#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 100006;
const int mxc = 26;
struct AC {
  struct Node {
    Node *to[mxc];
    Node *fail;
    int psum;
    int dfn;
    int out;
    vector<Node *> e;
    void clear(Node *t = NULL, Node *f = NULL) {
      fill(to, to + mxc, t);
      fail = f;
    }
  } mem[mxn];
  int size;
  void clear() {
    mem[0].clear(&mem[1]);
    mem[1].clear(NULL, &mem[0]);
    size = 1;
  }
  Node *append(Node *x, int c) {
    if (!x->to[c]) (x->to[c] = &mem[++size])->clear();
    return x->to[c];
  }
  vector<Node *> que;
  void build() {
    que = {&mem[1]};
    for (int i = 0; i < que.size(); ++i) {
      auto x = que[i];
      for (int i = 0; i < mxc; ++i)
        if (x->to[i]) {
          x->to[i]->fail = x->fail->to[i];
          que.push_back(x->to[i]);
        } else {
          x->to[i] = x->fail->to[i];
        }
    }
  }
  Node *root() { return mem + 1; }
};
AC A;
int n, q;
char line[mxn];
string s[mxn];
AC::Node *last[mxn];
struct Qry {
  int id;
  int l, r, x;
  int op;
};
vector<Qry> qa[mxn];
vector<Qry> qb[mxn];
ll ans[mxn];
vector<Qry> qc[mxn];
const int SQRT = 320;
const int B = SQRT;
struct SqrtArr {
  ll d[mxn];
  ll b[mxn];
  void set(int l, int r, ll val) {
    while (l <= r && l % B) d[l++] += val;
    while (l <= r && (r + 1) % B) d[r--] += val;
    for (int i = l; i <= r; i += B) b[i / B] += val;
  }
  ll get(int x) { return b[x / B] + d[x]; }
} Q;
int cnt;
void dfs(AC::Node *x) {
  x->dfn = ++cnt;
  for (auto i : x->e) dfs(i);
  x->out = cnt;
}
void EXEC() {
  scanf("%d%d", &n, &q);
  A.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", line);
    s[i] = line;
    for (auto &c : s[i]) c -= 'a';
    auto t = A.root();
    for (auto c : s[i]) t = A.append(t, c);
    last[i] = t;
  }
  A.build();
  for (int i = 1; i <= q; ++i) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    if (s[x].size() < SQRT) {
      qa[r].push_back({i, l, r, x, +1});
      qa[l - 1].push_back({i, l, r, x, -1});
    } else {
      qb[x].push_back({i, l, r, x, +1});
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!qb[i].empty()) {
      for (auto j : A.que) j->psum = 0;
      auto t = A.root();
      for (auto c : s[i]) {
        t = t->to[c];
        ++t->psum;
      }
      for (auto j = A.que.rbegin(); j != A.que.rend(); ++j)
        (*j)->fail->psum += (*j)->psum;
      for (int j = 0; j <= n; ++j) qc[j].clear();
      for (auto j : qb[i]) {
        qc[j.r].push_back({j.id, j.l, j.r, j.x, +1});
        qc[j.l - 1].push_back({j.id, j.l, j.r, j.x, -1});
      }
      ll sum = 0;
      for (int j = 1; j <= n; ++j) {
        sum += last[j]->psum;
        for (auto k : qc[j]) ans[k.id] += sum * k.op;
      }
    }
  for (auto i : A.que)
    if (i != A.root()) i->fail->e.push_back(i);
  cnt = 0;
  dfs(A.root());
  for (int i = 1; i <= n; ++i) {
    Q.set(last[i]->dfn, last[i]->out, +1);
    for (auto j : qa[i]) {
      auto t = A.root();
      for (auto c : s[j.x]) {
        t = t->to[c];
        ans[j.id] += Q.get(t->dfn) * j.op;
      }
    }
  }
  for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
}
int main() {
  EXEC();
  return 0;
}
