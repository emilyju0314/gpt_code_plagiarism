#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0, res = 0, n, k, i, item, answer = -1;
  cin >> n >> k;
  for (i = 0; i < n; ++i) {
    cin >> item;
    if (item > 8) {
      sum += 8;
      res += (item - 8);
    } else {
      sum += item;
      int t = 8 - item;
      if (res > t) {
        sum += t;
        res -= t;
      } else {
        sum += res;
        res = 0;
      }
    }
    if (sum >= k) {
      if (answer == -1) answer = i + 1;
    }
  }
  cout << answer << endl;
  return 0;
}
