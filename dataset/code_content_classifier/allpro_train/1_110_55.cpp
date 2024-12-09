#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int INF = 105000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, ans = 0;
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[i].first = x, a[i].second = y;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j].first == a[i].second && j != i) {
        ans++;
      }
    }
  }
  cout << ans;
}
