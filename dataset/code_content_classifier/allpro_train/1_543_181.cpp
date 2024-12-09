#include <bits/stdc++.h>
using namespace std;
long long int y, k, n, a, cnt = 0;
int main() {
  cin >> y >> k >> n;
  a = n - y;
  for (int j = 1, i = k; i <= n; j++, i = k * j) {
    if (i > y) {
      cout << i - y << " ";
      cnt++;
    }
  }
  if (cnt == 0) {
    cout << -1 << endl;
  }
  return 0;
}
