#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string second;
    cin >> second;
    int a[n];
    for (int i = 0; i < n; i++) {
      a[i] = int(second[i]) - int('0');
    }
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
      v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    int ans[n];
    memset(ans, 2, 4 * n);
    ans[v[0].second] = 1;
    int prev = v[0].second;
    int c = 0;
    int val = -1;
    for (int i = 1; i < n; i++) {
      if (c == 0) {
        if (v[i].second < prev) {
          c = 1;
          val = v[i].first;
        } else {
          ans[v[i].second] = 1;
          prev = v[i].second;
        }
      } else {
        if (v[i].first == val) {
          if (v[i].second > prev) ans[v[i].second] = 1;
        } else
          break;
      }
    }
    for (int i = 0; i < n; i++)
      if (ans[i] != 1) ans[i] = 2;
    bool b = 0;
    prev = -1;
    for (int i = 0; i < n; i++) {
      if (prev == -1) {
        if (ans[i] == 2) prev = i;
      } else {
        if (ans[i] == 2) {
          if (a[prev] > a[i]) b = 1;
          prev = i;
        }
      }
    }
    if (b)
      cout << '-';
    else {
      for (int i = 0; i < n; i++) cout << ans[i];
    }
    cout << endl;
  }
}
