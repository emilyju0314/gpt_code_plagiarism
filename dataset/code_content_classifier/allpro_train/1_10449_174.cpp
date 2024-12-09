#include <bits/stdc++.h>
using namespace std;
struct Node {
  Node *L, *R;
  int l, r;
  map<char, int> cnt;
  set<char> Del;
  int size;
  Node(int l, int r) : L(0), R(0), l(l), r(r), size(r - l + 1) {}
} * root;
string s, ans;
Node *build(int l, int r) {
  Node *v = new Node(l, r);
  if (l == r) {
    v->cnt[s[l - 1]] = 1;
    return v;
  }
  v->L = build(l, (v->l + v->r) / 2);
  v->R = build((v->l + v->r) / 2 + 1, r);
  for (pair<char, int> x : v->L->cnt) v->cnt[x.first] += x.second;
  for (pair<char, int> x : v->R->cnt) v->cnt[x.first] += x.second;
  return v;
}
void push(Node *v) {
  if (v->L) {
    for (char c : v->Del) {
      if (v->L->cnt.count(c) and v->L->cnt[c]) {
        v->L->size -= v->L->cnt[c];
        v->L->Del.insert(c);
        v->L->cnt.erase(c);
      }
      if (v->R->cnt.count(c) and v->R->cnt[c]) {
        v->R->size -= v->R->cnt[c];
        v->R->Del.insert(c);
        v->R->cnt.erase(c);
      }
    }
  }
  v->Del.clear();
}
int update(int l, int r, char c, Node *v) {
  push(v);
  if (v->size == r - l + 1)
    if (v->cnt[c]) {
      int res(v->cnt[c]);
      v->size -= res;
      v->Del.insert(c);
      v->cnt.erase(c);
      return res;
    } else {
      v->cnt.erase(c);
      return 0;
    }
  int lsize(v->L->size), res1(0), res2(0);
  if (l <= lsize) res1 = update(l, min(r, lsize), c, v->L);
  if (r > lsize) res2 = update(max(l, lsize + 1) - lsize, r - lsize, c, v->R);
  v->cnt[c] -= res1 + res2;
  v->size -= res1 + res2;
  if (!v->cnt[c]) v->cnt.erase(c);
  return res1 + res2;
}
void get_ans(Node *v) {
  push(v);
  if (!v->size) return;
  if (v->size == 1) {
    for (pair<char, int> x : v->cnt)
      if (x.second) ans += x.first;
    return;
  }
  get_ans(v->L);
  get_ans(v->R);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m >> s;
  root = build(1, n);
  while (m--) {
    int l, r;
    char c;
    cin >> l >> r >> c;
    update(l, r, c, root);
  }
  get_ans(root);
  cout << ans;
}
