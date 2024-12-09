#include <bits/stdc++.h>
using namespace std;
bool cp1(tuple<int, int, int>& a, tuple<int, int, int>& b) {
  if (get<1>(a) != get<1>(b)) return (get<1>(a) < get<1>(b));
  return get<0>(a) < get<0>(b);
}
bool cp2(tuple<int, int, int, int>& a, tuple<int, int, int, int>& b) {
  if (get<1>(a) != get<1>(b)) return (get<1>(a) < get<1>(b));
  return get<0>(a) > get<0>(b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> get<0>(a[i]) >> get<1>(a[i]);
    get<2>(a[i]) = i;
  }
  int m;
  cin >> m;
  vector<tuple<int, int, int, int>> b(m);
  for (int i = 0; i < m; i++) {
    cin >> get<0>(b[i]) >> get<1>(b[i]) >> get<2>(b[i]);
    get<3>(b[i]) = i + 1;
  }
  sort(a.begin(), a.end(), cp1);
  sort(b.begin(), b.end(), cp2);
  set<pair<int, int>> st;
  vector<int> ans(n);
  int t = 0;
  for (int i = 0; i < m; i++) {
    while (t < n && get<1>(a[t]) <= get<1>(b[i])) {
      st.insert(make_pair(get<0>(a[t]), get<2>(a[t])));
      t++;
    }
    auto u = st.lower_bound(make_pair(get<0>(b[i]), 0));
    while (get<2>(b[i]) && u != st.end()) {
      get<2>(b[i])--;
      ans[(*u).second] = get<3>(b[i]);
      st.erase(u);
      u = st.lower_bound(make_pair(get<0>(b[i]), 0));
    }
  }
  if (!st.empty() || t < n) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (auto c : ans) cout << c << ' ';
  cout << endl;
}
