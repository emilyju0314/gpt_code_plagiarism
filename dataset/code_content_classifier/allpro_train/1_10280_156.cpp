#include <bits/stdc++.h>
using namespace std;
struct MergeSortTree {
  vector<vector<long long>> tree;
  MergeSortTree(const vector<long long>& v) {
    tree.resize(4 * v.size());
    build(1, 1, v.size(), v);
  }
  void build(long long id, long long l, long long r,
             const vector<long long>& v) {
    if (l == r) {
      tree[id].push_back(v[l - 1]);
      return;
    }
    build(2 * id, l, (l + r) / 2, v);
    build(2 * id + 1, (l + r) / 2 + 1, r, v);
    merge((tree[2 * id]).begin(), (tree[2 * id]).end(),
          (tree[2 * id + 1]).begin(), (tree[2 * id + 1]).end(),
          back_inserter(tree[id]));
  }
  long long query(long long id, long long l, long long r, long long x,
                  long long y, long long k) {
    if (r < x || l > y) return 0;
    if (x <= l && r <= y) {
      return tree[id].size() -
             (lower_bound((tree[id]).begin(), (tree[id]).end(), k) -
              tree[id].begin());
    }
    return query(2 * id, l, (l + r) / 2, x, y, k) +
           query(2 * id + 1, (l + r) / 2 + 1, r, x, y, k);
  }
};
vector<long long> el;
long long N, a, tot;
int main() {
  cin >> N;
  el.reserve(N);
  for (long long i = 0; i < N; i++) {
    cin >> a;
    el.push_back(a);
  }
  MergeSortTree mst = MergeSortTree(el);
  for (long long i = 1; i <= N; i++) {
    tot += mst.query(1, 1, N, i + 1, el[i - 1], i);
  }
  cout << tot << '\n';
  return 0;
}
