#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3, b1, b2, b3, n;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
  if (((a1 + a2 + a3 + 4) / 5 + (b1 + b2 + b3 + 9) / 10) <= n) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}