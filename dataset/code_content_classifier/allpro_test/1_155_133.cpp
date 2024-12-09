#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    vector<pair<int, int>> v1, v2;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        v1.push_back({p[i], i});
      } else {
        v2.push_back({p[i], i});
      }
    }
    int l = v1.size();
    int r = v2.size();
    if (l == 0 || r == 0) {
      for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
      }
      cout << endl;
      continue;
    }
    int j = 1;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); i++) {
      v1[i].first = j;
      p[v1[i].second] = j;
      j++;
    }
    for (int i = 0; i < v2.size(); i++) {
      v2[i].first = j;
      p[v2[i].second] = j;
      j++;
    }
    for (int i = 0; i < n; i++) {
      cout << p[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
