#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << p.first << ' ' << p.second;
}
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& x : v) in >> x;
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (auto x : v) out << x << ' ';
  return out;
}
int n;
int cost[200005];
int a[200005], ind;
bool vis[200005], vis1[200005];
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n;
  int ans = 0;
  for (long long i = (1); i < (n + 1); ++i) cin >> cost[i];
  for (long long i = (1); i < (n + 1); ++i) {
    cin >> a[i];
    if (i == a[i]) {
      vis[i] = 1;
      ans += cost[i];
    }
  }
  for (long long i = (1); i < (n + 1); ++i) {
    set<int> st;
    bool f = 0;
    if (!vis[i]) {
      int nm = i;
      while (!vis[nm]) {
        st.insert(nm);
        vis[nm] = 1;
        nm = a[nm];
      }
      if (st.find(nm) == st.end()) {
        continue;
      }
      int minm = cost[nm];
      int xx = a[nm];
      while (xx != nm) {
        minm = min(minm, cost[xx]);
        xx = a[xx];
      }
      ans += minm;
    }
  }
  cout << ans;
}
