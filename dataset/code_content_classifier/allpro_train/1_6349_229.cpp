#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = v[0] + 1;
  for (int i = 1; i < n; i++) {
    ans += abs(v[i] - v[i - 1]);
    ans += 2;
  }
  cout << ans;
}