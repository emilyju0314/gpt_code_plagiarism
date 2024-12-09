#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long m, k;
    cin >> k >> m;
    long long flag = 1, s = 0;
    while (1) {
      if (m == 0) {
        break;
      }
      long long o = m % 2;
      s = (s + (flag * o) % 1000000007) % 1000000007;
      m = m / 2;
      flag = (flag * k) % 1000000007;
    }
    cout << s << endl;
  }
  return 0;
}
