#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int k;
  cin >> k;
  vector<pair<int, pair<int, int>>> a;
  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int j = 0; j < n; j++) {
      cin >> v[j];
    }
    int sum = accumulate(v.begin(), v.end(), 0);
    for (int j = 0; j < n; j++) {
      a.push_back(make_pair(sum - v[j], make_pair(i, j)));
    }
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < (int)a.size() - 1; i++) {
    if ((a[i].first == a[i + 1].first) &&
        (a[i].second.first != a[i + 1].second.first)) {
      cout << "YES" << endl;
      cout << a[i + 1].second.first + 1 << " " << a[i + 1].second.second + 1
           << endl;
      cout << a[i].second.first + 1 << " " << a[i].second.second + 1 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
