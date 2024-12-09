#include <bits/stdc++.h>
using namespace std;
pair<int, int> eea(int a, int b) {
  if (b == 0) return make_pair(1, 0);
  pair<int, int> ret = eea(b, a % b);
  return make_pair(ret.second, ret.first - (a / b) * ret.second);
}
struct modint {
  int val;
  modint(int a = 0) { val = a; }
  modint operator+=(modint r) { return val = (val + r.val) % 1000000007; }
  modint operator+(modint r) { return r += *this; }
  modint operator-(modint r) { return (val - r.val + 1000000007) % 1000000007; }
  modint operator*=(modint r) { return val = (1LL * val * r.val) % 1000000007; }
  modint operator*(modint r) { return r *= *this; }
  modint operator/=(modint r) {
    auto ret = eea(r.val, 1000000007);
    while (ret.first < 0) ret.first += 1000000007;
    while (ret.first >= 1000000007) ret.first -= 1000000007;
    modint divm = ret.first;
    return (*this) *= divm;
  }
};
pair<modint, modint> combine(pair<modint, modint> l, pair<modint, modint> r) {
  return make_pair(l.first * r.first, l.second + l.first * r.second);
}
struct stree {
  vector<pair<int, int> > span;
  vector<pair<modint, modint> > data;
  void init(int size) {
    int tpow = 1;
    while (tpow < size) tpow *= 2;
    data.resize(tpow * 2, make_pair(1, 0));
    span.resize(tpow * 2, make_pair(0, 0));
    for (int i = tpow; i < 2 * tpow; i++)
      span[i] = make_pair(i - tpow, i - tpow + 1);
    for (int i = tpow - 1; i > 0; i--)
      span[i] = make_pair(span[i * 2].first, span[i * 2 + 1].second);
  }
  template <int operation>
  pair<modint, modint> operate(int pos, int l, int r,
                               pair<modint, modint> val) {
    if (r <= span[pos].first || span[pos].second <= l) return make_pair(1, 0);
    if (l <= span[pos].first && span[pos].second <= r) {
      if (operation == 0) return data[pos];
      data[pos].second /= data[pos].first;
      data[pos].second *= data[pos].first + val.first;
      data[pos].first += val.first;
      data[pos].second += data[pos].first * val.second;
      return make_pair(1, 0);
    }
    pair<modint, modint> ret = make_pair(1, 0);
    ret = combine(ret, operate<operation>(pos * 2, l, r, val));
    ret = combine(ret, operate<operation>(pos * 2 + 1, l, r, val));
    data[pos] = combine(data[pos * 2], data[pos * 2 + 1]);
    return ret;
  }
  void add(int addpos, pair<modint, modint> toadd) {
    operate<1>(1, addpos, addpos + 1, toadd);
  }
  pair<modint, modint> get(int l, int r) {
    return operate<0>(1, l, r, make_pair(0, 0));
  }
};
struct tree {
  vector<int> conn[200000];
  void addEdge(int a, int b) { conn[a].push_back(b); }
  int size[200000], parent[200000];
  void dfsinit(int pos = 0) {
    size[pos] = 1;
    parent[pos] = -1;
    for (auto next : conn[pos]) {
      dfsinit(next);
      size[pos] += size[next];
      parent[next] = pos;
    }
  }
  stree seg[200000];
  int master[200000], sind[200000], segsize[200000];
  void hldinit(int pos = 0) {
    master[pos] = pos;
    segsize[pos] = 1;
    sind[pos] = 0;
    if (parent[pos] != -1 && size[pos] * 2 > size[parent[pos]]) {
      master[pos] = master[parent[pos]];
      sind[pos] = segsize[master[pos]]++;
    }
    for (auto next : conn[pos]) hldinit(next);
    if (master[pos] == pos) seg[pos].init(segsize[pos]);
  }
  int getnode(int node) {
    return seg[master[node]].get(sind[node], segsize[master[node]]).second.val;
  }
  void addnode(int node, pair<modint, modint> toadd) {
    while (node != -1) {
      int cmas = master[node];
      modint prevval = getnode(cmas);
      seg[cmas].add(sind[node], toadd);
      modint nval = getnode(cmas);
      toadd = make_pair(0, nval - prevval);
      node = parent[cmas];
    }
  }
} T;
int main() {
  int v1, q, sz = 1;
  vector<pair<int, pair<int, int> > > operation;
  cin.sync_with_stdio(false);
  cin >> v1 >> q;
  operation.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> operation[i].first >> operation[i].second.first;
    operation[i].second.first--;
    if (operation[i].first == 1) {
      cin >> operation[i].second.second;
      T.addEdge(operation[i].second.first, sz++);
    }
  }
  T.dfsinit();
  T.hldinit();
  T.addnode(0, make_pair(0, v1));
  sz = 1;
  for (auto op : operation) {
    if (op.first == 1) {
      T.addnode(op.second.first, make_pair(1, 0));
      T.addnode(sz++, make_pair(0, op.second.second));
    } else {
      cout << T.getnode(op.second.first) << '\n';
    }
  }
  return 0;
}
