#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 123;
int n;
int l[maxn], r[maxn];
struct node {
  node *lef, *rig, *papa;
  int Size;
  int value, lazy;
};
node *null;
void updateNode(node *x) { x->Size = x->lef->Size + x->rig->Size + 1; }
void setL(node *x, node *y) {
  x->lef = y;
  y->papa = x;
}
void setR(node *x, node *y) {
  x->rig = y;
  y->papa = x;
}
void addNode(node *x, int add) {
  x->value += add;
  x->lazy += add;
}
void pushDown(node *x) {
  if (x->lazy != 0) {
    if (x->lef != null) addNode(x->lef, x->lazy);
    if (x->rig != null) addNode(x->rig, x->lazy);
    x->lazy = 0;
  }
}
void uptree(node *x) {
  node *y = x->papa, *z = y->papa;
  if (x == y->lef) {
    setL(y, x->rig);
    setR(x, y);
  } else {
    setR(y, x->lef);
    setL(x, y);
  }
  if (y == z->lef)
    setL(z, x);
  else
    setR(z, x);
  updateNode(y);
  updateNode(x);
}
void splay(node *x) {
  while (true) {
    node *y = x->papa, *z = y->papa;
    if (y == null) break;
    if (z != null) {
      if ((z->lef == y) == (y->lef == x))
        uptree(y);
      else
        uptree(x);
    }
    uptree(x);
  }
}
node *at(node *root, int pos) {
  if (pos < 1 || pos > root->Size) return null;
  node *x = root;
  while (true) {
    pushDown(x);
    int s = x->lef->Size + 1;
    if (pos == s) break;
    if (pos < s) {
      x = x->lef;
    } else {
      pos -= s;
      x = x->rig;
    }
  }
  return x;
}
void split(node *T, int pos, node *&T1, node *&T2) {
  if (pos == 0) {
    T1 = null;
    T2 = T;
    return;
  }
  if (pos > T->Size) {
    T1 = T;
    T2 = null;
    return;
  }
  T = at(T, pos);
  splay(T);
  T1 = T;
  T2 = T->rig;
  T2->papa = T1->rig = null;
  updateNode(T1);
}
node *join(node *a, node *b) {
  if (a == null) return b;
  if (b == null) return a;
  a = at(a, a->Size);
  splay(a);
  setR(a, b);
  updateNode(a);
  return a;
}
int lowerBound(node *root, int key) {
  int res = root->Size + 1, rem = 0;
  node *x = root;
  while (true) {
    if (x == null) break;
    pushDown(x);
    if (x->value >= key) {
      res = rem + x->lef->Size + 1;
      x = x->lef;
    } else {
      rem += x->lef->Size + 1;
      x = x->rig;
    }
  }
  return res;
}
void insertNode(node *&root, int pos, int add) {
  node *T1, *T2;
  split(root, pos, T1, T2);
  node *u = new node;
  u->lef = u->rig = u->papa = null;
  u->lazy = 0;
  u->value = add;
  u->Size = 1;
  root = join(join(T1, u), T2);
}
void eraseNode(node *&root, int pos) {
  if (pos <= 0 || pos > root->Size) return;
  node *T1, *T2;
  split(root, pos, T1, T2);
  T1 = at(T1, T1->Size);
  splay(T1);
  T1 = T1->lef;
  T1->papa = null;
  root = join(T1, T2);
}
void increaseSegment(node *&root, int l, int r, int add) {
  if (r < l) return;
  node *T1, *T2, *T3;
  split(root, r, T2, T3);
  split(T2, l - 1, T1, T2);
  addNode(T2, add);
  root = join(join(T1, T2), T3);
}
void initSplayTree() {
  null = new node;
  null->lef = null->rig = null->papa = null;
  null->Size = null->value = null->lazy = 0;
}
node *root;
void ReadData() {
  cin >> n;
  for (int i = 1, _b = n; i <= _b; ++i) cin >> l[i] >> r[i];
}
void show(node *x) {
  if (x == null) return;
  pushDown(x);
  show(x->lef);
  cout << x->value << " ";
  show(x->rig);
}
void Process() {
  initSplayTree();
  root = new node;
  root = null;
  insertNode(root, 0, l[1]);
  for (int i = 2, _b = n; i <= _b; ++i) {
    int u = lowerBound(root, l[i]), v = lowerBound(root, r[i]);
    --v;
    eraseNode(root, v + 1);
    increaseSegment(root, u, v, 1);
    insertNode(root, u - 1, l[i]);
  }
  cout << root->Size << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ReadData();
  Process();
  return 0;
}
