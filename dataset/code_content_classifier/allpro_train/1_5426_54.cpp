#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = INT_MAX;
const int lim = 3e5 + 5;
const int lim1 = 1e6 + 5;
long long power(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret *= a;
    a *= a;
    if (ret >= mod) ret %= mod;
    if (a >= mod) a %= mod;
    b >>= 1;
  }
  return ret;
}
long long inv(long long x) { return power(x, mod - 2); }
int a[lim], cnt[lim1];
long long tree[4 * lim], mxx[4 * lim];
void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = a[start];
    mxx[node] = tree[node];
    return;
  }
  int mid = (start + end) >> 1;
  build(2 * node + 1, start, mid);
  build(2 * node + 2, mid + 1, end);
  tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  mxx[node] = max(mxx[2 * node + 1], mxx[2 * node + 2]);
}
void update(int node, int start, int end, int low, int high) {
  if (low > end || high < start || mxx[node] <= 2) return;
  if (start == end) {
    tree[node] = cnt[tree[node]];
    mxx[node] = tree[node];
    return;
  }
  int mid = (start + end) >> 1;
  update(2 * node + 1, start, mid, low, high);
  update(2 * node + 2, mid + 1, end, low, high);
  tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  mxx[node] = max(mxx[2 * node + 1], mxx[2 * node + 2]);
}
long long query(int node, int start, int end, int low, int high) {
  if (low > end || high < start) return 0;
  if (start >= low && end <= high) return tree[node];
  int mid = (start + end) >> 1;
  long long q1 = query(2 * node + 1, start, mid, low, high);
  long long q2 = query(2 * node + 2, mid + 1, end, low, high);
  return q1 + q2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  for (int i = 1; i < lim1; i++)
    for (int j = i; j < lim1; j += i) cnt[j]++;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  build(0, 0, n - 1);
  int x, y, z;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    if (x & 1) {
      update(0, 0, n - 1, y - 1, z - 1);
      continue;
    }
    cout << query(0, 0, n - 1, y - 1, z - 1) << "\n";
  }
}
