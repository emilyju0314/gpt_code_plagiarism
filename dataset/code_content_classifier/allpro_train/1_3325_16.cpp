#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
struct node {
  int value, size, max;
  node *ch[2], *pnt;
  void rs() {
    size = ch[0]->size + ch[1]->size + 1;
    max = std::max(std::max(ch[0]->max, ch[1]->max), value);
  }
};
node nil = (node){0, 0, 0};
node *NIL = &nil;
map<int, pair<int, int> > maps;
struct splaytree {
  node *root;
  int ncnt;
  node nodes[MAXN + 10];
  void init() {
    root = NIL;
    ncnt = 0;
  }
  void rotate(node *x, bool d) {
    node *y = x->pnt;
    y->ch[!d] = x->ch[d];
    if (x->ch[d] != NIL) x->ch[d]->pnt = y;
    x->pnt = y->pnt;
    if (y->pnt != NIL) {
      if (y == y->pnt->ch[d])
        y->pnt->ch[d] = x;
      else
        y->pnt->ch[!d] = x;
    }
    x->ch[d] = y;
    y->pnt = x;
    y->rs();
    x->rs();
  }
  void splay(node *x, node *target) {
    node *y;
    while (x->pnt != target) {
      y = x->pnt;
      if (x == y->ch[0]) {
        if (y->pnt != target && y == y->pnt->ch[0]) rotate(y, true);
        rotate(x, true);
      } else {
        if (y->pnt != target && y == y->pnt->ch[1]) rotate(y, false);
        rotate(x, false);
      }
    }
    if (target == NIL) root = x;
  }
  void pushup(node *x, node *target) {
    node *y = x->pnt;
    while (y != target) {
      y->rs();
      y = y->pnt;
    }
  }
  void insert(int value) {
    if (root == NIL) {
      ncnt = 0;
      root = &nodes[++ncnt];
      root->ch[0] = root->ch[1] = root->pnt = NIL;
      root->value = value;
      root->max = value;
      root->size = 1;
      return;
    }
    node *x = root, *y;
    while (1) {
      x->size++;
      if (value < x->value || maps[value].second <= x->ch[0]->size ||
          value < x->ch[0]->max) {
        if (x->ch[0] != NIL)
          x = x->ch[0];
        else {
          x->ch[0] = &nodes[++ncnt];
          y = x->ch[0];
          y->value = value;
          y->size = 1;
          y->max = value;
          y->ch[0] = y->ch[1] = NIL;
          y->pnt = x;
          break;
        }
      } else {
        maps[value].second -= x->ch[0]->size + 1;
        if (x->ch[1] != NIL)
          x = x->ch[1];
        else {
          x->ch[1] = &nodes[++ncnt];
          y = x->ch[1];
          y->value = value;
          y->size = 1;
          y->max = value;
          y->ch[0] = y->ch[1] = NIL;
          y->pnt = x;
          break;
        }
      }
    }
    pushup(y, NIL);
    splay(y, NIL);
  }
};
int dfsflag = 1;
int dfs(node *now) {
  if (now == NIL) return 0;
  dfs(now->ch[1]);
  if (dfsflag) {
    printf("%d", maps[now->value].first, now->value);
    dfsflag = 0;
  } else
    printf(" %d", maps[now->value].first, now->value);
  dfs(now->ch[0]);
  return 0;
}
int n;
splaytree tree;
int main(void) {
  tree.init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int tempa, tempb;
    scanf("%d%d", &tempa, &tempb);
    maps[tempa].first = i;
    maps[tempa].second = tempb;
    tree.insert(tempa);
  }
  dfs(tree.root);
  printf("\n");
  return 0;
}
