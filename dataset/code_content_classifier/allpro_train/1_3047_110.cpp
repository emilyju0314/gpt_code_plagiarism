#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
      cout << "No\n";
      continue;
    }
    vector<pair<int, int>> a_pairs(n / 2), b_pairs(n / 2);
    for (int i = 0; i < n / 2; i++) {
      if (a[i] <= a[n - 1 - i]) {
        a_pairs[i] = make_pair(a[i], a[n - 1 - i]);
      } else {
        a_pairs[i] = make_pair(a[n - 1 - i], a[i]);
      }
      if (b[i] <= b[n - 1 - i]) {
        b_pairs[i] = make_pair(b[i], b[n - 1 - i]);
      } else {
        b_pairs[i] = make_pair(b[n - 1 - i], b[i]);
      }
    }
    sort(a_pairs.begin(), a_pairs.end());
    sort(b_pairs.begin(), b_pairs.end());
    bool good = true;
    for (int i = 0; i < n / 2; i++) {
      if (a_pairs[i] != b_pairs[i]) {
        good = false;
        break;
      }
    }
    if (good) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
