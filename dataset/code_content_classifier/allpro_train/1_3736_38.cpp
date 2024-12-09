#include <bits/stdc++.h>
using namespace std;
int n, k;
namespace BST {
int cnt, s, a;
struct Node {
  int size, value;
  Node *left, *right;
  Node(int s, int v, Node* a, Node* b) : size(s), value(v), left(a), right(b) {}
  Node() {}
} * root[1000000], *father, *st[1000000], t[1000000], *null;
inline void maintain(register Node* cur) {
  if (cur->left->size > cur->right->size * 4)
    cur->right =
        (&(*st[cnt++] = Node(cur->left->right->size + cur->right->size,
                             cur->right->value, cur->left->right, cur->right))),
    st[--cnt] = cur->left, cur->left = cur->left->left;
  if (cur->right->size > cur->left->size * 4)
    cur->left = (&(*st[cnt++] = Node(cur->left->size + cur->right->left->size,
                                     cur->right->left->value, cur->left,
                                     cur->right->left))),
    st[--cnt] = cur->right, cur->right = cur->right->right;
}
int find(int x, Node* cur) {
  if (cur->size == 1) return cur->value;
  return x > cur->left->size ? find(x - cur->left->size, cur->right)
                             : find(x, cur->left);
}
int Rank(int x, Node* cur) {
  if (cur->size == 1) return 1;
  return x > cur->left->value ? Rank(x, cur->right) + cur->left->size
                              : Rank(x, cur->left);
}
void insert(int x, Node* cur) {
  if (cur->size == 1)
    cur->left = (&(*st[cnt++] = Node(1, min(cur->value, x), null, null))),
    cur->right = (&(*st[cnt++] = Node(1, max(cur->value, x), null, null)));
  else
    insert(x, x > cur->left->value ? cur->right : cur->left);
  if (cur->left->size)
    cur->size = cur->left->size + cur->right->size,
    cur->value = cur->right->value;
  maintain(cur);
}
void erase(int x, Node* cur) {
  if (cur->size == 1)
    *father = cur == father->left ? *father->right : *father->left;
  else
    father = cur, erase(x, x > cur->left->value ? cur->right : cur->left);
  if (cur->left->size)
    cur->size = cur->left->size + cur->right->size,
    cur->value = cur->right->value;
  maintain(cur);
}
void init() {
  null = new Node(0, 0, 0, 0);
  for (int i = 0; i < 1000000; ++i)
    st[i] = &t[i], root[i] = new Node(1, 0x7f7f7f7f, null, null);
}
}  // namespace BST
int head[200016], nex[200016 << 1], to[200016 << 1], ecn = 0;
void ade(int u, int v) { nex[++ecn] = head[u], to[ecn] = v, head[u] = ecn; }
int fa[200016], siz[200016], hea[200016], dep[200016], top[200016], tig[200016],
    bac[200016], en[200016], clo;
void dfs(int u, int faa) {
  siz[u] = 1, dep[u] = dep[faa] + 1;
  for (int i = head[u]; i; i = nex[i]) {
    int v = to[i];
    if (v == faa) continue;
    fa[v] = u;
    dfs(v, u);
    siz[u] += siz[v];
    if (!hea[u] || siz[v] > siz[hea[u]]) hea[u] = v;
  }
}
void dfss(int u, int too) {
  tig[u] = ++clo, bac[clo] = u, en[too] = u, top[u] = too;
  if (!hea[u]) return;
  dfss(hea[u], too);
  for (int i = head[u]; i; i = nex[i]) {
    int v = to[i];
    if (v == fa[u] || v == hea[u]) continue;
    dfss(v, v);
  }
}
int col[200016];
struct node {
  int l, r;
  node(int L = 0, int R = 0) : l(L), r(R) {}
} T[200016 << 2], red(0x3f3f3f3f, 0x3f3f3f3f), blu(-0x3f3f3f3f, -0x3f3f3f3f);
int rec[200016];
bool judge(int u, int k, int d) {
  int B = BST ::Rank(k + 1, BST ::root[u]) - 1;
  int R = BST ::Rank(0x7f7f7f7f, BST ::root[u]) - 1 - B;
  return k >= R - B - d;
}
void update(int u, int& k, int d) {
  while (!judge(u, k, d)) ++k;
  while (judge(u, k - 1, d)) --k;
}
void work(int rt, int u) {
  if (col[u] == 0) {
    T[rt] = red;
  } else if (col[u] == 1) {
    T[rt] = blu;
  } else {
    update(u, T[rt].l, 1);
    update(u, T[rt].r, -1);
  }
}
node merge(node a, node b) {
  node ret;
  ret.l = min(max(b.l, a.l), a.r);
  ret.r = min(max(b.r, a.l), a.r);
  return ret;
}
void pushup(int rt) { T[rt] = merge(T[rt << 1], T[rt << 1 | 1]); }
node query(int rt, int l, int r, int L, int R) {
  if (l == L && r == R) return T[rt];
  int m = l + r >> 1;
  if (R <= m) return query(rt << 1, l, m, L, R);
  if (L > m) return query(rt << 1 | 1, m + 1, r, L, R);
  return merge(query(rt << 1, l, m, L, m),
               query(rt << 1 | 1, m + 1, r, m + 1, R));
}
void build(int rt, int l, int r) {
  if (l == r) {
    int u = bac[l];
    work(rt, u);
    if (u == top[u] && fa[u])
      BST ::insert((rec[u] = (query(1, 1, n, l, tig[en[u]])).l),
                   BST ::root[fa[u]]);
    return;
  }
  int mid = l + r >> 1;
  build(rt << 1 | 1, mid + 1, r), build(rt << 1, l, mid);
  pushup(rt);
}
void mdfy(int rt, int l, int r, int p) {
  if (l == r) {
    work(rt, bac[l]);
    return;
  }
  int m = l + r >> 1;
  if (p <= m)
    mdfy(rt << 1, l, m, p);
  else
    mdfy(rt << 1 | 1, m + 1, r, p);
  pushup(rt);
}
void modify(int x, int c) {
  col[x] = c;
  while (x) {
    mdfy(1, 1, n, tig[x]);
    x = top[x];
    if (fa[x] != 0) {
      BST ::erase(rec[x], BST ::root[fa[x]]);
      BST ::insert(rec[x] = (query(1, 1, n, tig[x], tig[en[x]]).l),
                   BST ::root[fa[x]]);
    }
    x = fa[x];
  }
}
int main() {
  BST ::init();
  cin >> n >> k;
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    ade(u, v), ade(v, u);
  }
  for (int i = 1; i <= n; ++i) scanf("%d", &col[i]);
  dfs(1, 1);
  dfss(1, 1);
  build(1, 1, n);
  int q, opt, v, c;
  cin >> q;
  while (q--) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d", &v);
      printf("%d\n", (query(1, 1, n, tig[v], tig[en[top[v]]]).l) <= -k);
    } else if (opt == 2) {
      scanf("%d%d", &v, &c);
      modify(v, c);
    } else {
      scanf("%d", &c);
      k = c;
    }
  }
}
