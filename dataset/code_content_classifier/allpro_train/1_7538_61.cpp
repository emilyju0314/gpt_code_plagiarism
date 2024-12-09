#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, m, c = 0, w1, w2, h1, h2, ans = 0;
  cin >> w1 >> h1 >> w2 >> h2;
  ans = w1 + 2 + w2 + 2 + 2 * h1 + 2 * h2;
  if (w1 > w2) {
    ans = ans + (w1 + 2 - (w2 + 2));
  }
  cout << ans;
}
