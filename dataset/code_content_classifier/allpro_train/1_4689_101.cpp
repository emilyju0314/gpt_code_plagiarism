#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 5;
struct node {
  int l, r;
  int idx;
  bool operator<(const node& rhs) const {
    if (r != rhs.r) return r < rhs.r;
    if (l != rhs.l) return l < rhs.l;
    return idx < rhs.idx;
  }
} in[maxn];
int cnt[maxn];
bool cmp(const node& a, const node& b) { return a.l < b.l; }
int main(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &in[i].l, &in[i].r);
    in[i].idx = i;
    cnt[in[i].l]++;
    cnt[in[i].r + 1]--;
  }
  sort(in + 1, in + n + 1, cmp);
  int pos = 1;
  priority_queue<node> pq;
  vector<int> res;
  for (int i = 1; i < maxn; i++) {
    while (pos <= n && in[pos].l == i) {
      pq.push(in[pos++]);
    }
    cnt[i] += cnt[i - 1];
    while (cnt[i] > k) {
      cnt[i]--;
      cnt[pq.top().r + 1]++;
      res.push_back(pq.top().idx);
      pq.pop();
    }
  }
  printf("%d\n", res.size());
  for (int x : res) printf("%d ", x);
  printf("\n");
  return 0;
}
