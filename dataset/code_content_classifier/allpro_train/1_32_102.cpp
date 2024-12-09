#include <bits/stdc++.h>
using namespace std;
string to(int n, int r) {
  string k = "";
  while (n != 0) {
    k = (char)((n % r) + 48) + k;
    n /= r;
  }
  return k;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k - 1; i++) {
    for (int j = 1; j <= k - 1; j++) cout << to(i * j, k) << " ";
    cout << endl;
  }
  return 0;
}
