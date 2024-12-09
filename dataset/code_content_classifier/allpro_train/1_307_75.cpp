#include <bits/stdc++.h>
using namespace std;
struct node {
  int v, r, siz;
  node* ch[2];
  long long sum[5];
  void maintain() {
    int pre = 0;
    int s = 1;
    if (ch[0] != NULL) s += ch[0]->siz;
    pre = s;
    if (ch[1] != NULL) s += ch[1]->siz;
    siz = s;
    memset(sum, 0, sizeof(sum));
    sum[(pre % 5)] = v;
    for (int i = 0; i < 5; i++) {
      if (ch[0] != NULL) sum[i] += ch[0]->sum[i];
      if (ch[1] != NULL) sum[(pre + i) % 5] += ch[1]->sum[i];
    }
  }
  node(int x) {
    this->v = x;
    this->r = rand();
    this->siz = 1;
    this->ch[0] = this->ch[1] = NULL;
    memset(sum, 0, sizeof(sum));
    this->sum[1] = x;
  }
  int cmp(int x) {
    if (x == v) return -1;
    return x < v ? 0 : 1;
  }
};
node* rt;
void rotate(node*& o, int d) {
  node* k = o->ch[d ^ 1];
  o->ch[d ^ 1] = k->ch[d];
  k->ch[d] = o;
  o->maintain();
  k->maintain();
  o = k;
}
void Insert(node*& o, int v) {
  if (o == NULL) {
    o = new node(v);
    return;
  } else {
    int d = v < o->v ? 0 : 1;
    Insert(o->ch[d], v);
    if (o->ch[d]->r > o->r) rotate(o, d ^ 1);
    if (o != NULL) o->maintain();
  }
}
void Remove(node*& o, int v) {
  int d = o->cmp(v);
  if (d == -1) {
    if (o->ch[0] != NULL && o->ch[1] != NULL) {
      int d2 = o->ch[0]->r > o->ch[1]->r ? 1 : 0;
      rotate(o, d2);
      Remove(o->ch[d2], v);
      if (o != NULL) o->maintain();
    } else if (o->ch[0] != NULL)
      o = o->ch[0];
    else
      o = o->ch[1];
  } else {
    Remove(o->ch[d], v);
    if (o != NULL) o->maintain();
  }
}
int kth(node*& o, int k) {
  if (k == 0 || o == NULL || o->siz < k)
    return -1;
  else {
    int s = o->ch[0] == NULL ? 0 : o->ch[0]->siz;
    if (k == s + 1)
      return o->v;
    else if (k <= s)
      return kth(o->ch[0], k);
    else
      return kth(o->ch[1], k - s - 1);
  }
}
void print(node*& o) {
  if (o == NULL) return;
  if (o->ch[0] != NULL) print(o->ch[0]);
  printf("v=%d r=%d siz=%d || ", o->v, o->r, o->siz);
  if (o->ch[1] != NULL) print(o->ch[1]);
}
string Coms[] = {"add", "del", "sum"};
int n;
int main() {
  scanf("%d", &n);
  string com;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> com;
    if (com == Coms[0]) {
      scanf("%d", &x);
      Insert(rt, x);
    } else if (com == Coms[1]) {
      scanf("%d", &x);
      Remove(rt, x);
    } else {
      if (rt == NULL)
        printf("0\n");
      else {
        printf("%lld\n", rt->sum[3]);
      }
    }
  }
  return 0;
}
