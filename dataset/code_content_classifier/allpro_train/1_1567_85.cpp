#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  long long sum = 0, x, delt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    long long cur = min(x / 2, delt);
    sum += cur;
    x -= 2 * cur;
    delt -= cur;
    sum += x / 3;
    x %= 3;
    delt += x;
  }
  cout << sum;
  return 0;
}
