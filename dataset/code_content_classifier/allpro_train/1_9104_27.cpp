#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<int> a, b, diff;
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int n;
    cin >> n;
    bool answer = true;
    a.clear();
    b.clear();
    diff.clear();
    a.resize(n + 1);
    b.resize(n + 1);
    diff.resize(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
      diff[i] = b[i] - a[i];
      if (diff[i] < 0) answer = false;
    }
    int change = 0;
    for (int i = 0; i <= n; i++) {
      if (diff[i] != diff[i + 1]) change++;
    }
    if (change > 2) answer = false;
    cout << (answer ? "YES\n" : "NO\n");
  }
  return 0;
}
