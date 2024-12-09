#include <bits/stdc++.h>
using namespace std;
const int N = 300 * 1000 + 10, mod = 1e9 + 7;
long long a[N], ps[N];
long long b[N], d[N];
int l[N], r[N];
long long mn[4 * N], mx[4 * N];
void build(int s = 0, int e = N, int ind = 1) {
  if (e - s == 1) {
    mn[ind] = mx[ind] = ps[s];
    return;
  }
  int mid = (s + e) / 2;
  build(s, mid, 2 * ind);
  build(mid, e, 2 * ind + 1);
  mn[ind] = min(mn[2 * ind], mn[2 * ind + 1]);
  mx[ind] = max(mx[2 * ind], mx[2 * ind + 1]);
}
long long get_max(int l, int r, int s = 0, int e = N, int ind = 1) {
  if (l <= s && e <= r) return mx[ind];
  if (r <= s || e <= l) return -2e18;
  int mid = (s + e) / 2;
  return max(get_max(l, r, s, mid, 2 * ind),
             get_max(l, r, mid, e, 2 * ind + 1));
}
long long get_min(int l, int r, int s = 0, int e = N, int ind = 1) {
  if (l <= s && e <= r) return mn[ind];
  if (r <= s || e <= l) return 2e18;
  int mid = (s + e) / 2;
  return min(get_min(l, r, s, mid, 2 * ind),
             get_min(l, r, mid, e, 2 * ind + 1));
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> a[i];
    a[i] = x - a[i];
    ps[i + 1] = ps[i] + a[i];
  }
  build();
  for (int i = 0; i < n - 1; i++) b[i] = d[i + 1] - d[i];
  vector<int> st;
  for (int i = 0; i < n - 1; i++) {
    while (st.size() && b[st.back()] <= b[i]) st.pop_back();
    l[i] = (st.size() ? st.back() : -1);
    st.push_back(i);
  }
  st.clear();
  for (int i = n - 2; i > -1; i--) {
    while (st.size() && b[st.back()] <= b[i]) st.pop_back();
    r[i] = (st.size() ? st.back() : n - 1);
    st.push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, a[i]);
  for (int i = 0; i < n - 1; i++) {
    int s = l[i] + 1, e = r[i];
    ans = max(ans, get_max(i + 2, e + 2) - get_min(s, i + 1) - b[i] * b[i]);
  }
  cout << ans << endl;
}
