#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 1000 * 1000 * 1000;
const double EPS = 1e-9;
const int MAXN = 100100;
struct Segment {
  int l, r;
  Segment(int l, int r) : l(l), r(r) {}
  bool operator<(const Segment &o) const {
    return r - l > o.r - o.l || r - l == o.r - o.l && l > o.l;
  }
};
set<Segment> q;
struct Node {
  int key, priority;
  int q;
  Node *l, *r;
  Node(int key) : key(key), priority(rand() << 15 ^ rand()), q(1), l(0), r(0) {}
};
typedef Node *treap;
treap root;
int calc(treap t) {
  if (t == 0) {
    return 0;
  }
  return t->q;
}
void recalc(treap &t) {
  if (t == 0) {
    return;
  }
  t->q = 1 + calc(t->l) + calc(t->r);
}
treap merge(treap l, treap r) {
  if (l == 0) {
    return r;
  }
  if (r == 0) {
    return l;
  }
  if (l->priority > r->priority) {
    l->r = merge(l->r, r);
    recalc(l);
    return l;
  }
  r->l = merge(l, r->l);
  recalc(r);
  return r;
}
void split(treap t, treap &l, treap &r, int key) {
  if (t == 0) {
    l = 0;
    r = 0;
    return;
  }
  if (key > t->key) {
    split(t->r, t->r, r, key);
    l = t;
  } else {
    split(t->l, l, t->l, key);
    r = t;
  }
  recalc(l);
  recalc(r);
}
void insert(int key) {
  treap l, r;
  split(root, l, r, key);
  root = merge(l, merge(new Node(key), r));
}
void remove(int key) {
  treap l, m, r;
  split(root, l, r, key);
  split(r, m, r, key + 1);
  root = merge(l, r);
}
bool find(int key, treap t = root) {
  if (t == 0) {
    return false;
  }
  if (t->key == key) {
    return true;
  }
  if (key < t->key) {
    return find(key, t->l);
  }
  return find(key, t->r);
}
void print(treap t) {
  if (t == 0) {
    return;
  }
  print(t->l);
  printf("%d ", t->key);
  print(t->r);
}
int query(int l, int r) {
  treap tl, tm, tr;
  split(root, tl, tr, l);
  split(tr, tm, tr, r);
  int res = calc(tm);
  root = merge(tl, merge(tm, tr));
  return res;
}
int main() {
  int N;
  scanf("%d", &N);
  q.insert(Segment(0, N - 1));
  int Q;
  scanf("%d", &Q);
  map<int, int> ps;
  map<int, int> leftEnds, rightEnds;
  leftEnds.insert(make_pair(0, N - 1));
  rightEnds.insert(make_pair(N - 1, 0));
  while (Q--) {
    int x;
    scanf("%d", &x);
    if (x == 0) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", query(l - 1, r));
    } else {
      if (ps.find(x) != ps.end()) {
        int id = ps[x];
        ps.erase(x);
        remove(id);
        if (leftEnds.find(id + 1) == leftEnds.end() &&
            rightEnds.find(id - 1) != rightEnds.end()) {
          int tmp = rightEnds[id - 1];
          rightEnds.erase(id - 1);
          leftEnds.erase(tmp);
          q.erase(Segment(tmp, id - 1));
          rightEnds.insert(make_pair(id, tmp));
          leftEnds.insert(make_pair(tmp, id));
          q.insert(Segment(tmp, id));
        } else if (leftEnds.find(id + 1) != leftEnds.end() &&
                   rightEnds.find(id - 1) == rightEnds.end()) {
          int tmp = leftEnds[id + 1];
          leftEnds.erase(id + 1);
          rightEnds.erase(tmp);
          q.erase(Segment(id + 1, tmp));
          leftEnds.insert(make_pair(id, tmp));
          rightEnds.insert(make_pair(tmp, id));
          q.insert(Segment(id, tmp));
        } else if (leftEnds.find(id + 1) != leftEnds.end() &&
                   rightEnds.find(id - 1) != rightEnds.end()) {
          int tmpl = rightEnds[id - 1];
          rightEnds.erase(id - 1);
          int tmpr = leftEnds[id + 1];
          leftEnds.erase(id + 1);
          q.erase(Segment(tmpl, id - 1));
          q.erase(Segment(id + 1, tmpr));
          rightEnds.erase(tmpr);
          leftEnds.erase(tmpl);
          rightEnds.insert(make_pair(tmpr, tmpl));
          leftEnds.insert(make_pair(tmpl, tmpr));
          q.insert(Segment(tmpl, tmpr));
        } else if (leftEnds.find(id + 1) == leftEnds.end() &&
                   rightEnds.find(id - 1) == rightEnds.end()) {
          leftEnds.insert(make_pair(id, id));
          rightEnds.insert(make_pair(id, id));
          q.insert(Segment(id, id));
        }
      } else {
        Segment is = *q.begin();
        q.erase(q.begin());
        int p = is.l + (is.r - is.l) / 2;
        if ((is.r - is.l) & 1) {
          ++p;
        }
        ps.insert(make_pair(x, p));
        leftEnds.erase(is.l);
        rightEnds.erase(is.r);
        if (p - 1 >= is.l) {
          leftEnds.insert(make_pair(is.l, p - 1));
          rightEnds.insert(make_pair(p - 1, is.l));
          q.insert(Segment(is.l, p - 1));
        }
        if (p + 1 <= is.r) {
          rightEnds.insert(make_pair(is.r, p + 1));
          leftEnds.insert(make_pair(p + 1, is.r));
          q.insert(Segment(p + 1, is.r));
        }
        insert(p);
      }
    }
  }
  return 0;
}
