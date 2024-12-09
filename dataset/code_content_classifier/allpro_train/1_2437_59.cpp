#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 100;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << "1 " << n - 1;
    for (int i = (1); i <= (n); ++i) cout << " " << i;
    cout << endl;
    int k;
    cin >> k;
    int l = 2, r = n;
    while (l < r) {
      int mid = l + r >> 1;
      cout << "1 " << mid - l + 1 << " 1";
      for (int i = (l); i <= (mid); ++i) cout << " " << i;
      cout << endl;
      int x;
      cin >> x;
      if (x < k)
        l = mid + 1;
      else
        r = mid;
    }
    cout << "1 " << n - 1 << " " << l;
    for (int i = (1); i <= (n); ++i)
      if (i != l) cout << " " << i;
    cout << endl;
    int x;
    cin >> x;
    cout << "-1 " << x << endl;
  }
}
