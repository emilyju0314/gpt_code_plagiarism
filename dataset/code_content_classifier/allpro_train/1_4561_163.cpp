#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, l;
vector<pair<int, string>> v;
string s, ss, s2;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    v.push_back(make_pair(s.length(), s));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; ++i) {
    s2 = v[i + 1].second;
    for (int j = 0; j <= v[i + 1].first - v[i].first; ++j) {
      ss.clear();
      for (int k = j; k < j + v[i].first; ++k) {
        ss += s2[k];
      }
      if (ss == v[i].second) break;
      if (j == v[i + 1].first - v[i].first) return printf("NO"), 0;
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; ++i) {
    cout << v[i].second << endl;
  }
  return 0;
}
