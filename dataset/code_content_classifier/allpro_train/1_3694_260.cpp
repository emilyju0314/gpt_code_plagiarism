#include <bits/stdc++.h>
using namespace std;
int ans[500000];
int main() {
  int n, x;
  scanf("%d", &n);
  vector<pair<int, int> > a, b;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(make_pair(x, i));
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    b.push_back(make_pair(x, i));
  }
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  for (int i = 0; i < n; i++) {
    ans[b[i].second] = a[i].first;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
