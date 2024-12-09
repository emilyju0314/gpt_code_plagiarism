#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t) {
    int n, mx;
    long long r = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    mx = v[0];
    for (int i = 0; i < n; i++) {
      if ((v[i] - r) >= mx) {
        mx = v[i] - r;
      }
      r += v[i] - r;
    }
    cout << mx << endl;
    t--;
  }
}
