#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5 + 10;
int n, m, T, k;
vector<pair<int, int>> a, b, ab, other;
vector<int> ans;
int check(int mid) {
  if ((int)a.size() < k - mid) return 2e9 + 1;
  if ((int)b.size() < k - mid) return 2e9 + 1;
  if (mid + max(0, k - mid) * 2 > m) return 2e9 + 1;
  int nd = m - mid, res = 0;
  ans.clear();
  vector<pair<int, int>> vec;
  for (int i = 0; i < mid; i++) res += ab[i].first, ans.push_back(ab[i].second);
  for (int i = mid; i < ab.size(); i++) vec.push_back(ab[i]);
  for (int i = 0; i < k - mid; i++)
    res += a[i].first + b[i].first, nd -= 2, ans.push_back(a[i].second),
        ans.push_back(b[i].second);
  for (int i = max(0, k - mid); i < a.size(); i++) vec.push_back(a[i]);
  for (int i = max(0, k - mid); i < b.size(); i++) vec.push_back(b[i]);
  for (int i = 0; i < other.size(); i++) vec.push_back(other[i]);
  sort(vec.begin(), vec.end());
  for (int i = 0; i < nd && i < vec.size(); i++)
    res += vec[i].first, ans.push_back(vec[i].second);
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 1, x1, x2, x3; i <= n; ++i) {
    cin >> x1 >> x2 >> x3;
    if (x2 && x3)
      ab.push_back({x1, i});
    else if (x2)
      a.push_back({x1, i});
    else if (x3)
      b.push_back({x1, i});
    else
      other.push_back({x1, i});
  }
  sort(a.begin(), a.end()), sort(b.begin(), b.end()),
      sort(ab.begin(), ab.end()), sort(other.begin(), other.end());
  int l = 0, r = min((int)ab.size(), m);
  while (r - l > 10) {
    int midl = l + (r - l) / 3, midr = r - (r - l) / 3;
    if (check(midl) >= check(midr))
      l = midl;
    else
      r = midr;
  }
  int res = 2e9 + 1, Min_idx = -1;
  for (int i = l; i <= r; i++) {
    int tmp = check(i);
    if (tmp < res) res = tmp, Min_idx = i;
  }
  if (Min_idx == -1) return puts("-1"), 0;
  cout << check(Min_idx) << endl;
  for (auto a : ans) cout << a << " ";
  return 0;
}
