#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, n, x, s = 0;
  cin >> d >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> x;
    s += d - x;
  }
  cin >> x;
  cout << s;
}
