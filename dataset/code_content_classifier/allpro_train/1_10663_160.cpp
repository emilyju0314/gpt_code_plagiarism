#include <bits/stdc++.h>
using namespace std;
template <typename F, typename S>
ostream& operator<<(ostream& os, const pair<F, S>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, vector<T> const& x) {
  os << "{ ";
  for (auto& y : x) os << y << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, set<T> const& x) {
  os << "{ ";
  for (auto& y : x) os << y << " ";
  return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[";
  typename multiset<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename F, typename S>
ostream& operator<<(ostream& os, const map<F, S>& v) {
  os << "[";
  typename map<F, S>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
const long long int MOD = 1e9 + 7;
const int N = 3e5 + 100;
long long int hh(long long int a, long long int b) {
  return ((a) < (b) ? (a) : (b)) * ((long long int)1e7) +
         ((a) > (b) ? (a) : (b));
}
int cnt[N];
unordered_set<long long int> se;
bool check1(vector<int>& v, int sz) {
  for (auto i : v)
    if (cnt[i] != sz) return false;
  return true;
}
bool check2(vector<int>& v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (se.find(hh(v[i], v[j])) != se.end()) return false;
    }
  }
  return true;
}
void _main_main() {
  long long int n, m, x, y;
  cin >> n >> m;
  while (m--) {
    cin >> x >> y;
    se.insert(hh(x, y));
    cnt[x]++;
    cnt[y]++;
  }
  vector<int> v1, v2, v3, v4;
  v1.push_back(1);
  for (int i = 2; i <= n; i++) {
    if (se.find(hh(1ll, i)) != se.end())
      v2.push_back(i);
    else
      v1.push_back(i);
  }
  if (v2.size() < 2) {
    cout << -1 << "\n";
    return;
  }
  for (auto i : v2) {
    if (se.find(hh(i, v2[0])) != se.end()) {
      v4.emplace_back(i);
    } else
      v3.emplace_back(i);
  }
  if (v3.empty()) {
    cout << -1 << "\n";
    return;
  }
  if (v4.empty()) {
    cout << -1 << "\n";
    return;
  }
  if (!check1(v1, v3.size() + v4.size())) {
    cout << -1 << "\n";
    return;
  }
  if (!check1(v3, v1.size() + v4.size())) {
    cout << -1 << "\n";
    return;
  }
  if (!check1(v4, v1.size() + v3.size())) {
    cout << -1 << "\n";
    return;
  }
  vector<pair<int, int> > pp;
  pp.push_back({v1.size(), 1});
  pp.push_back({v3.size(), 3});
  pp.push_back({v4.size(), 4});
  sort(pp.begin(), pp.end());
  for (int i = 0; i < 2; i++) {
    if (pp[i].second == 1) {
      if (!check2(v1)) {
        cout << -1 << "\n";
        return;
      }
    }
    if (pp[i].second == 3) {
      if (!check2(v3)) {
        cout << -1 << "\n";
        return;
      }
    }
    if (pp[i].second == 4) {
      if (!check2(v4)) {
        cout << -1 << "\n";
        return;
      }
    }
  }
  long long int ans[n + 5];
  for (auto i : v1) ans[i] = 1;
  for (auto i : v3) ans[i] = 2;
  for (auto i : v4) ans[i] = 3;
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testCase = 1;
  for (int i = 0; i < testCase; i++) {
    _main_main();
  }
}
