#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<pair<char, int> > v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  n = s.size();
  for (int i = 0, c = 1; i < n; i++, c++) {
    if (i == n - 1 || s[i] != s[i + 1]) {
      v.push_back({s[i], c});
      c = 0;
    }
  }
  if (v.size() % 2 == 0 || v[v.size() / 2].second < 2) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < v.size() / 2; i++) {
    if (v[i].first != v[v.size() - i - 1].first ||
        v[i].second + v[v.size() - i - 1].second < 3) {
      cout << 0 << '\n';
      return 0;
    }
  }
  cout << (v[v.size() / 2].second + 1) << '\n';
  return 0;
}
