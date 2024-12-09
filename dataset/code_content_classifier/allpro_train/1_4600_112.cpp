#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long h, n;
    cin >> h >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.push_back(0);
    long long cnt = 0;
    for (int i = 0; i <= n; i++) {
      if (a[i] <= 2) break;
      if (i + 1 <= n && a[i] - a[i + 1] > 1) {
        a[i] = a[i + 1] + 1;
        i--;
        continue;
      }
      if (i + 2 <= n && a[i + 2] != a[i] - 2) {
        a[i + 1]--;
        cnt++;
        continue;
      }
      i++;
    }
    cout << cnt << "\n";
  }
}
