#include <bits/stdc++.h>
using namespace std;
const int N = 5500;
vector<pair<int, int> > g;
int n, u, v;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> u >> v;
    g.push_back(make_pair(u, v));
  }
  int last = 0;
  sort(g.begin(), g.end());
  for (int i = 0; i < n; i++) {
    if (g[i].second >= last) {
      last = g[i].second;
    } else {
      last = g[i].first;
    }
  }
  cout << last << "\n";
  return 0;
}
