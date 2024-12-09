#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int ans[10000];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    int x;
    cin >> x;
    m[-x]++;
  }
  int pos = n - 1;
  for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
    int x = -it->first;
    while (it->second) {
      ans[pos] = x;
      --it->second;
      for (int i = pos + 1; i < n; ++i) m[-gcd(ans[pos], ans[i])] -= 2;
      pos--;
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  return 0;
}
