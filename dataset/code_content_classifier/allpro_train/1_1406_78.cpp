#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int MAX = 4e2;
int n;
int main() {
  cin >> n;
  map<int, long long> m;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x - i] += x;
    ans = max(m[x - i], ans);
  }
  cout << ans << '\n';
  return 0;
}
