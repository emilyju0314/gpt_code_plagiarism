#include <bits/stdc++.h>
using namespace std;
const int N = 200002, M = 998244353;
int n, q;
int tree[4 * N], lazyMul[4 * N], lazyAdd[4 * N];
set<pair<int, int> > disjointRanges[N];
void addRange(pair<int, int> p, set<pair<int, int> > &st) {
  while (true) {
    auto it = st.lower_bound({p.first, p.first});
    if (it != st.end() and (*it).second <= p.second)
      st.erase(it);
    else
      break;
  }
  auto it = st.upper_bound({p.first, p.first});
  if (it != st.begin()) {
    --it;
    if ((*it).second >= p.second) return;
    ++it;
  }
  if (it != st.begin()) {
    --it;
    if ((*it).second >= p.first - 1) {
      p.first = (*it).first;
      st.erase(it);
    }
  }
  it = st.upper_bound({p.first, p.first});
  if (it != st.end() and (*it).first <= p.second + 1) {
    p.second = (*it).second;
    st.erase(it);
  }
  st.insert(p);
}
bool totallyCovered(pair<int, int> p, set<pair<int, int> > &st) {
  auto it = st.lower_bound({p.first, p.first});
  if (it != st.end() and (*it).first == p.first)
    return (*it).second >= p.second;
  if (it != st.begin()) {
    --it;
    return (*it).second >= p.second;
  }
  return false;
}
bool partiallyCovered(pair<int, int> p, set<pair<int, int> > &st) {
  auto it = st.lower_bound({p.first, p.first});
  if (it != st.end() and (*it).first <= p.second) return true;
  if (it != st.begin()) {
    --it;
    return p.first <= (*it).second;
  }
  return false;
}
void propagate(int i, int l, int r) {
  tree[i] = (1ll * tree[i] * lazyMul[i] % M + lazyAdd[i] * (r - l + 1ll)) % M;
  if (l < r) {
    lazyMul[2 * i] = 1ll * lazyMul[2 * i] * lazyMul[i] % M;
    lazyAdd[2 * i] = (1ll * lazyAdd[2 * i] * lazyMul[i] + lazyAdd[i]) % M;
    lazyMul[2 * i + 1] = 1ll * lazyMul[2 * i + 1] * lazyMul[i] % M;
    lazyAdd[2 * i + 1] =
        (1ll * lazyAdd[2 * i + 1] * lazyMul[i] + lazyAdd[i]) % M;
  }
  lazyMul[i] = 1;
  lazyAdd[i] = 0;
}
int query(int i, int start, int end, int l, int r) {
  propagate(i, start, end);
  if (l <= start && r >= end) return tree[i];
  if (r < start || l > end) return 0;
  int mid = (start + end) / 2;
  return (query(2 * i, start, mid, l, r) +
          query(2 * i + 1, mid + 1, end, l, r)) %
         M;
}
int check(int l, int r, int v) {
  if (totallyCovered({l, r}, disjointRanges[v])) return 1;
  if (!partiallyCovered({l, r}, disjointRanges[v])) return 2;
  return 0;
}
void update(int i, int start, int end, int l, int r, int v) {
  propagate(i, start, end);
  if (l <= start && r >= end) {
    int t = check(start, end, v);
    if (t == 1) {
      lazyMul[i] = lazyMul[i] * 2 % M;
      propagate(i, start, end);
      return;
    } else if (t == 2) {
      ++lazyAdd[i];
      propagate(i, start, end);
      return;
    }
  }
  if (r < start || l > end) return;
  int mid = (start + end) / 2;
  update(2 * i, start, mid, l, r, v);
  update(2 * i + 1, mid + 1, end, l, r, v);
  tree[i] = (tree[2 * i] + tree[2 * i + 1]) % M;
}
int main() {
  fill(lazyMul, lazyMul + 4 * N, 1);
  scanf("%d%d", &n, &q);
  while (q--) {
    int t, l, r, x;
    scanf("%d%d%d", &t, &l, &r);
    if (t == 1) {
      scanf("%d", &x);
      update(1, 1, n, l, r, x);
      addRange({l, r}, disjointRanges[x]);
    } else
      printf("%d\n", query(1, 1, n, l, r));
  }
}
