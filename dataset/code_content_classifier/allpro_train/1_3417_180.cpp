#include <bits/stdc++.h>
using namespace std;
long long int pw(long long int a, long long int b, long long int mod) {
  if (!b) return 1;
  if (b & 1) return a * pw(a * a % mod, b / 2, mod) % mod;
  return pw(a * a % mod, b / 2, mod) % mod;
}
const long long int N = 3e5 + 10;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e18;
int n, A[N], L[N][2], seg[N << 2], mn[N << 2], lazy[N << 2];
long long int ans;
vector<int> vec[2];
void Build(int id, int l, int r) {
  if (r - l == 1) {
    mn[id] = l;
    seg[id] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  Build(2 * id, l, mid);
  Build(2 * id + 1, mid, r);
  mn[id] = min(mn[2 * id], mn[2 * id + 1]);
  seg[id] = 0;
  if (mn[id] == mn[2 * id]) seg[id] += seg[2 * id];
  if (mn[id] == mn[2 * id + 1]) seg[id] += seg[2 * id + 1];
}
void Shift(int id, int l, int r) {
  if (lazy[id] == 0) return;
  mn[id] += lazy[id];
  if (r - l > 1) {
    lazy[2 * id] += lazy[id];
    lazy[2 * id + 1] += lazy[id];
  }
  lazy[id] = 0;
}
void Update(int id, int l, int r, int ql, int qr, int v) {
  Shift(id, l, r);
  if (qr <= l || r <= ql) return;
  if (ql <= l && r <= qr) {
    lazy[id] += v;
    return Shift(id, l, r);
  }
  int mid = (l + r) >> 1;
  Update(2 * id, l, mid, ql, qr, v);
  Update(2 * id + 1, mid, r, ql, qr, v);
  mn[id] = min(mn[2 * id], mn[2 * id + 1]);
  seg[id] = 0;
  if (mn[id] == mn[2 * id]) seg[id] += seg[2 * id];
  if (mn[id] == mn[2 * id + 1]) seg[id] += seg[2 * id + 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    A[u - 1] = v - 1;
  }
  Build(1, 0, n);
  for (int i = 0; i < n; i++) {
    while (!vec[0].empty() && A[i] > A[vec[0].back()]) {
      int dif = A[i] - A[vec[0].back()];
      Update(1, 0, n, L[vec[0].back()][0], vec[0].back() + 1, dif);
      vec[0].pop_back();
    }
    L[i][0] = (vec[0].empty() ? 0 : vec[0].back() + 1);
    vec[0].push_back(i);
    while (!vec[1].empty() && A[i] < A[vec[1].back()]) {
      int dif = A[vec[1].back()] - A[i];
      Update(1, 0, n, L[vec[1].back()][1], vec[1].back() + 1, dif);
      vec[1].pop_back();
    }
    L[i][1] = (vec[1].empty() ? 0 : vec[1].back() + 1);
    vec[1].push_back(i);
    Update(1, 0, n, 0, i + 1, -i);
    ans += seg[1];
    Update(1, 0, n, 0, i + 1, +i);
  }
  cout << ans << '\n';
  return 0;
}
