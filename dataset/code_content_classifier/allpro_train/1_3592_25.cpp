#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
struct xyi {
  int x, y, i;
  bool operator<(const xyi& a) const {
    if (x < a.x) return true;
    if (y < a.y) return true;
    return false;
  }
};
pair<int, int> xy[100007];
map<pair<int, int>, int> id;
const long long MOD = 1e9 + 9;
const int OFS = 1234;
bool check(int k) {
  int x = xy[k].first;
  int y = xy[k].second;
  bool remove = true;
  for (int i = -1; i <= 1; ++i)
    if (id[make_pair(x + i, y + 1)] >= OFS) {
      bool supported = false;
      for (int j = -1; j <= 1; ++j) {
        int sp = id[make_pair(x + i + j, y)];
        if (sp >= OFS && sp != k + OFS) supported = true;
      }
      if (!supported) {
        remove = false;
        break;
      }
    }
  return remove;
}
int main() {
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    xy[i] = make_pair(x, y);
    id[xy[i]] = i + OFS;
  }
  set<int> S;
  for (int i = 0; i < m; ++i)
    if (check(i)) S.insert(i);
  long long res = 0;
  bool even = true;
  while (!S.empty()) {
    int k;
    if (even) {
      auto rit = S.rbegin();
      k = *rit;
      S.erase(k);
      id[xy[k]] = -1;
    } else {
      auto it = S.begin();
      k = *it;
      S.erase(it);
      id[xy[k]] = -1;
    }
    (res *= m) %= MOD;
    (res += k) %= MOD;
    int x = xy[k].first;
    int y = xy[k].second;
    for (int i = -2; i <= 2; ++i)
      if (i != 0) {
        pair<int, int> tmp = make_pair(x + i, y);
        if (id[tmp] >= OFS && !check(id[tmp] - OFS)) {
          auto cur = S.find(id[tmp] - OFS);
          if (cur != S.end()) S.erase(cur);
        }
      }
    for (int i = -1; i <= 1; ++i) {
      pair<int, int> tmp = make_pair(x + i, y - 1);
      if (id[tmp] >= OFS && check(id[tmp] - OFS)) {
        S.insert(id[tmp] - OFS);
      }
    }
    even = !even;
  }
  cout << res << endl;
  return 0;
}
