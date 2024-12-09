#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  int ai = 0, gi = 0;
  string str = "";
  for (int i = 0; i < n; i++) {
    if (abs(ai + v[i].first - gi) > 500) {
      if (abs(gi + v[i].second - ai) > 500) {
        if (v[i].first < v[i].second) {
          ai += v[i].first;
          str += "A";
        } else {
          gi += v[i].second;
          str += "G";
        }
      } else {
        gi += v[i].second;
        str += "G";
      }
    } else {
      str += "A";
      ai += v[i].first;
    }
  }
  if (abs(ai - gi) > 500) {
    cout << -1 << endl;
  } else {
    cout << str << endl;
  }
  return 0;
}
