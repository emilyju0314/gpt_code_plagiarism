#include <bits/stdc++.h>
using namespace std;
mt19937 gen(200);
struct node {
  pair<int, int> f, s;
  node *le, *ri;
  long long mn, res;
  int tl, tr;
  node() { mn = 228; }
  node(int l, int r) {
    tl = l;
    tr = r;
    mn = 228;
    if (l == r) return;
    le = new node(l, (l + r) / 2);
    ri = new node((l + r) / 2 + 1, r);
  }
  node(node* a, node* b) {
    le = a;
    ri = b;
    tl = le->tl;
    tr = ri->tr;
    if (le->mn == 228) {
      res = ri->res;
      mn = ri->mn;
      f = ri->f;
      s = ri->s;
      return;
    }
    if (ri->mn == 228) {
      res = le->res;
      mn = le->mn;
      f = le->f;
      s = le->s;
      return;
    }
    f = le->f;
    s = ri->s;
    long long del = 1ll * le->s.second * (ri->f.first - le->s.first);
    res = le->res + del + ri->res;
    mn = min(le->mn, le->res + del);
    mn = min(mn, ri->mn + le->res + del);
  }
  void combine() {
    node tmp(le, ri);
    *this = tmp;
  }
  void update(int id, int time, int speed) {
    if (tl == tr) {
      mn = res = 0;
      f.first = s.first = time;
      f.second = s.second = speed;
      return;
    }
    if (id <= (tl + tr) / 2)
      le->update(id, time, speed);
    else
      ri->update(id, time, speed);
    combine();
  }
  void del(int id) {
    if (tl == tr) {
      mn = 228;
      return;
    }
    if (id <= (tl + tr) / 2)
      le->del(id);
    else
      ri->del(id);
    combine();
  }
  node* get_seg(int l, int r) {
    if (tr < l || r < tl) return new node();
    if (l <= tl && tr <= r) {
      return this;
      ;
    }
    return new node(le->get_seg(l, r), ri->get_seg(l, r));
  }
  long double simulate(int r, long long v) {
    if (mn == 228) return -1;
    if (v + mn > 0 && v + res + 1ll * s.second * (r - s.first) > 0) return -1;
    if (f == s) return s.first - (long double)v / s.second;
    if (le->mn == 228) return ri->simulate(r, v);
    long double to = le->simulate(le->s.first, v);
    if (to != -1) return to;
    v += le->res;
    long long del =
        1ll * le->s.second * ((ri->mn == 228 ? r : ri->f.first) - le->s.first);
    if (v + del <= 0) return le->s.first - (long double)v / le->s.second;
    v += del;
    return ri->simulate(r, v);
  }
  long double query(int l, int r, int rr, long long v) {
    node* t = get_seg(l, r);
    return t->simulate(rr, v);
  }
};
struct query {
  int time, speed, start;
  int l, r, type;
  query() {}
};
vector<int> pos;
vector<query> q;
int main() {
  ios_base::sync_with_stdio(false);
  cout.precision(7);
  int qq;
  cin >> qq;
  q.resize(qq);
  for (int i = 0; i < qq; ++i) {
    cin >> q[i].type;
    if (q[i].type == 1) {
      cin >> q[i].time >> q[i].speed;
      pos.push_back(q[i].time);
    }
    if (q[i].type == 2) {
      cin >> q[i].time;
    }
    if (q[i].type == 3) {
      cin >> q[i].l >> q[i].r >> q[i].start;
    }
  }
  sort(pos.begin(), pos.end());
  pos.erase(unique(pos.begin(), pos.end()), pos.end());
  if (pos.size() == 0) pos.push_back(0);
  node* t = new node(0, pos.size() - 1);
  for (int i = 0; i < qq; ++i) {
    if (q[i].type == 1) {
      int id = lower_bound(pos.begin(), pos.end(), q[i].time) - pos.begin();
      t->update(id, q[i].time, q[i].speed);
    }
    if (q[i].type == 2) {
      int id = lower_bound(pos.begin(), pos.end(), q[i].time) - pos.begin();
      t->del(id);
    }
    if (q[i].type == 3) {
      int l = lower_bound(pos.begin(), pos.end(), q[i].l) - pos.begin();
      int r = --upper_bound(pos.begin(), pos.end(), q[i].r) - pos.begin();
      if (q[i].start == 0)
        cout << fixed << q[i].l << '\n';
      else
        cout << fixed << t->query(l, r, q[i].r, q[i].start) << '\n';
    }
  }
  return 0;
}
