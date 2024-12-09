#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int> > parent;
void make_set(int v) { parent[v] = make_pair(v, 0); }
pair<int, int> find_parent(int v) {
  if (parent.find(v) == parent.end()) {
    make_set(v);
  }
  if (v == parent[v].first) return parent[v];
  pair<int, int> prnt = find_parent(parent[v].first);
  parent[v] = make_pair(prnt.first, prnt.second ^ parent[v].second);
  return parent[v];
}
int calc(int l, int r) {
  pair<int, int> pl = find_parent(l), pr = find_parent(r);
  if (pl.first != pr.first) return -1;
  return pl.second ^ pr.second;
}
void union_sets(int l, int r, int x) {
  pair<int, int> pl = find_parent(l), pr = find_parent(r);
  if (pl.first != pr.first) {
    if (rand() % 2) {
      parent[pl.first] = make_pair(pr.first, pr.second ^ pl.second ^ x);
    } else {
      parent[pr.first] = make_pair(pl.first, pl.second ^ pr.second ^ x);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int q;
  cin >> q;
  int last = 0;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int _l, _r, _x;
      cin >> _l >> _r >> _x;
      int l = _l ^ last, r = _r ^ last, x = _x ^ last;
      if (l > r) swap(l, r);
      r++;
      int xx = calc(l, r);
      if (xx == -1) {
        union_sets(l, r, x);
      }
    } else {
      int _l, _r;
      cin >> _l >> _r;
      int l = _l ^ last, r = _r ^ last;
      if (l > r) swap(l, r);
      r++;
      int x = calc(l, r);
      cout << x << endl;
      if (x == -1)
        last = 1;
      else
        last = x;
    }
  }
  return 0;
}
