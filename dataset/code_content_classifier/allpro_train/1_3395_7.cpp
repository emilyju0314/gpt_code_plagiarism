#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18, MOD = 1e9 + 7, MOD2 = 1e6 + 3;
const int M = 1e6;
int n, t, a[1000003], x, y, cnt[1000003];
set<pair<int, int> > s;
vector<int> ans[1000003];
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    fill(cnt, cnt + n + 2, 0);
    fill(ans, ans + n + 2, vector<int>());
    s.clear();
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    int off = -1;
    for (int i = 1; i <= n + 1; i++) {
      if (cnt[i])
        s.insert({cnt[i], i});
      else
        off = i;
    }
    for (int i = 0; i < x; i++) {
      auto mx = *s.rbegin();
      s.erase(mx);
      mx.first--;
      ans[mx.second].push_back(mx.second);
      s.insert(mx);
    }
    int mx = s.rbegin()->first;
    vector<int> v;
    for (auto a : s) {
      while (a.first--) {
        v.push_back(a.second);
      }
    }
    sort(v.begin(), v.end());
    int k = v.size(), neut = n - y;
    bool b = true;
    for (int i = 0; i < k; i++) {
      int j = (i + k / 2) % k;
      if (v[i] == v[j]) {
        if (!neut) b = false;
        neut--;
        ans[v[i]].push_back(off);
      } else
        ans[v[i]].push_back(v[j]);
    }
    if (b) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        if (neut && a[i] != ans[a[i]].back() && ans[a[i]].back() != off) {
          cout << off << ' ';
          neut--;
        } else
          cout << ans[a[i]].back() << ' ';
        ans[a[i]].pop_back();
      }
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
}
