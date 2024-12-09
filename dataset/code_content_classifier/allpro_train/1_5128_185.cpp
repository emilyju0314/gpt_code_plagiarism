#include <bits/stdc++.h>
using namespace std;
int main() {
  int strings[6];
  for (int i = 0; i < 6; i++) {
    cin >> strings[i];
  }
  int n;
  cin >> n;
  vector<pair<int, int> > keys;
  int minl, maxl, d;
  for (int i = 0; i < n; i++) {
    cin >> d;
    for (int j = 0; j < 6; j++) {
      keys.push_back(make_pair(d - strings[j], i));
    }
  }
  sort(keys.begin(), keys.end());
  vector<int> cnt(n);
  int c = 0;
  int minr = 1e9;
  int l = 0;
  int r = 0;
  while (l < 6 * n) {
    while (c < n && r < 6 * n) {
      cnt[keys[r].second]++;
      if (cnt[keys[r].second] == 1) {
        c++;
      }
      r++;
    }
    if (r == 6 * n) break;
    if (keys[r - 1].first - keys[l].first < minr) {
      minr = keys[r - 1].first - keys[l].first;
    }
    if (cnt[keys[l].second] == 1) {
      c--;
    }
    cnt[keys[l].second]--;
    l++;
  }
  cout << minr << endl;
}
