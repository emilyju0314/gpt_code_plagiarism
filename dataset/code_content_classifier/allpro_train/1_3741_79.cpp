#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long int n, cnt = 0, a, b;
    cin >> n;
    if (n == 1)
      cout << "0" << endl;
    else {
      if (n & 1)
        cnt += n / 2;
      else
        cnt += (n / 2 - 1);
      cout << cnt << endl;
    }
  }
  return 0;
}
