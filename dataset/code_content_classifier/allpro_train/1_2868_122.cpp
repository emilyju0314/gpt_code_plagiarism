#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m;
vector<int> a[N];
int num[N];
long long ans;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      a[j].push_back(x);
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 0; i < n; i++) {
      num[i] = 0;
    }
    for (int i = 0; i < a[j].size(); i++) {
      if (a[j][i] <= n * m && (a[j][i] - j) % m == 0) {
        int y = (a[j][i] - j) / m;
        num[(i - y + n) % n]++;
      }
    }
    long long ans1 = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
      ans1 = min(ans1, i + n - num[i]);
    }
    ans += ans1;
  }
  cout << ans << endl;
}
