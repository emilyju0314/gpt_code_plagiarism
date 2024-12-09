#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[262192];
struct segt {
  long long value, lz;
};
vector<int> disc;
segt tree[262192 << 2];
pair<int, int> domino[262192];
int tmp[262192 << 1];
long long ans[262192];
void pushdown(int l, int r, int index) {
  if (l > r) return;
  if (tree[index].lz != -1) {
    if (l != r) {
      tree[(index << 1)].value =
          1ll * tree[index].lz * (((l + r) >> 1) - l + 1);
      tree[(index << 1 | 1)].value =
          1ll * tree[index].lz * (r - ((l + r) >> 1));
      tree[(index << 1)].lz = tree[(index << 1 | 1)].lz = tree[index].lz;
    }
    tree[index].lz = -1;
  }
}
void update(int start, int end, int l, int r, int index, int val) {
  if (start > end || l > r || start > r || l > end) return;
  pushdown(l, r, index);
  if (start <= l && r <= end) {
    tree[index].lz = val;
    tree[index].value = 1ll * val * (r - l + 1);
    return;
  }
  if (end <= ((l + r) >> 1)) {
    update(start, end, l, ((l + r) >> 1), (index << 1), val);
  } else if (start >= ((l + r) >> 1) + 1) {
    update(start, end, ((l + r) >> 1) + 1, r, (index << 1 | 1), val);
  } else {
    update(start, end, l, ((l + r) >> 1), (index << 1), val);
    update(start, end, ((l + r) >> 1) + 1, r, (index << 1 | 1), val);
  }
  tree[index].value = tree[(index << 1)].value + tree[(index << 1 | 1)].value;
}
long long query(int start, int end, int l, int r, int index) {
  if (start > end || l > r || start > r || l > end) return 0;
  pushdown(l, r, index);
  if (start <= l && r <= end) return tree[index].value;
  if (end <= ((l + r) >> 1)) {
    return query(start, end, l, ((l + r) >> 1), (index << 1));
  }
  if (start >= ((l + r) >> 1) + 1) {
    return query(start, end, ((l + r) >> 1) + 1, r, (index << 1 | 1));
  }
  return query(start, end, l, ((l + r) >> 1), (index << 1)) +
         query(start, end, ((l + r) >> 1) + 1, r, (index << 1 | 1));
}
void build(int l, int r, int index) {
  if (l > r) return;
  tree[index].lz = -1;
  if (l == r) {
    tree[index].value = disc[l + 1] - disc[l];
    return;
  }
  build(l, ((l + r) >> 1), (index << 1));
  build(((l + r) >> 1) + 1, r, (index << 1 | 1));
  tree[index].value = tree[(index << 1)].value + tree[(index << 1 | 1)].value;
}
int main() {
  int n, i, j = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d%d", &domino[i].first, &domino[i].second);
    tmp[j++] = domino[i].first;
    tmp[j++] = domino[i].second + domino[i].first;
  }
  sort(tmp, tmp + j);
  for (i = 0; i < j; ++i) {
    if (i == 0 || tmp[i] != tmp[i - 1]) {
      disc.push_back(tmp[i]);
    }
  }
  int sz = (int)disc.size() - 2;
  build(0, sz, 1);
  int q;
  scanf("%d", &q);
  for (i = 1; i <= q; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].emplace_back(y, i);
  }
  for (i = n; i >= 1; --i) {
    int L =
        lower_bound(disc.begin(), disc.end(), domino[i].first) - disc.begin();
    int R = lower_bound(disc.begin(), disc.end(),
                        domino[i].first + domino[i].second) -
            disc.begin() - 1;
    update(L, R, 0, sz, 1, 0);
    for (auto np : g[i]) {
      int idx = lower_bound(disc.begin(), disc.end(), domino[np.first].first) -
                disc.begin() - 1;
      ans[np.second] = query(L, idx, 0, sz, 1);
    }
  }
  for (i = 1; i <= q; ++i) {
    printf("%I64d\n", ans[i]);
  }
  return 0;
}
