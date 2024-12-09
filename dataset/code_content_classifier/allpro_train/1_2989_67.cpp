#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  long long x;
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    char c;
    int v;
    cin >> c >> v;
    if (c == '+')
      x += v;
    else {
      if (x >= v)
        x -= v;
      else
        ++ans;
    }
  }
  cout << x << " " << ans << "\n";
}
