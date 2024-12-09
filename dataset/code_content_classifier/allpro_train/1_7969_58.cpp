#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  int n, k;
  cin >> n >> k;
  int g = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    g = gcd(g, x);
  }
  set<int> ans;
  for (long long i = 0, s = 0; i < k; i++, s += g) {
    ans.insert(s % k);
  }
  cout << ans.size() << "\n";
  for (auto aa : ans) {
    cout << aa << " ";
  }
  return 0;
}
