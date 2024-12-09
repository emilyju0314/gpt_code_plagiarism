#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, dif;
  cin >> a >> b;
  for (i = 1; i <= 1000000000000000000; i++) {
    if ((i * a) % 10 == 0 || (i * a - b) % 10 == 0) break;
  }
  cout << i;
  return 0;
}
