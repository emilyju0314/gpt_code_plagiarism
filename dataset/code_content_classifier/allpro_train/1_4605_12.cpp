#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
const long long MX = 2e5 + 105;
int ara[MX];
int Next[MX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  multiset<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  Next[1] = 0;
  for (int i = 1; i <= k; i++) {
    cin >> ara[i];
    if (i == 1) continue;
    if (ara[i] == ara[i - 1])
      Next[i] = Next[i - 1];
    else
      Next[i] = i - 1;
  }
  vector<vector<int> > fi;
  vector<int> sz;
  int c = 0;
  while (!s.empty()) {
    auto it = s.end();
    it--;
    vector<int> cur;
    int total = 0;
    while (1) {
      total++;
      auto it1 = it;
      cur.push_back(*it);
      int x = ara[(*it)] - total;
      if (x) {
        if (it == s.begin() || s.size() == 1) {
          s.erase(it1);
          break;
        }
        it--;
      } else {
        if (Next[(*it)] == 0 || s.size() == 1) {
          s.erase(it1);
          break;
        }
        it = s.upper_bound(Next[(*it)]);
        if (it == s.begin()) {
          s.erase(it1);
          break;
        }
        it--;
      }
      s.erase(it1);
    }
    sz.push_back(cur.size());
    fi.push_back(cur);
  }
  cout << fi.size() << endl;
  for (int i = 0; i < fi.size(); i++) {
    cout << sz[i] << ' ';
    for (auto x : fi[i]) cout << x << ' ';
    cout << endl;
  }
}
