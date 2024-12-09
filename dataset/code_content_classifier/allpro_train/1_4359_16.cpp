#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  if (x == 3) {
    cout << 5 << endl;
    return 0;
  }
  int n = 1;
  while ((n - 1) * (n - 1) / 2 + n < x) n += 2;
  cout << n << endl;
  return 0;
}
