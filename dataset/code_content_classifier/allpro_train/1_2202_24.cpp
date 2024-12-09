#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, res = 0;
  cin >> a >> b;
  while (a && b) {
    if (a > b)
      res += a / b, a %= b;
    else
      res += b / a, b %= a;
  }
  cout << res;
  return 0;
}
