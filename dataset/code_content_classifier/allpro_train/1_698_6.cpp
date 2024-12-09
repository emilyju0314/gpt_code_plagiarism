#include <bits/stdc++.h>
using namespace std;
int a, b, p;
int main() {
  cin >> a >> b >> p;
  int tmp = 1000000000 % p;
  for (int x = 0; x <= p + 10 && x <= a; x++) {
    if (1LL * tmp * x % p < p - b && 1LL * tmp * x % p > 0) {
      cout << "1 ";
      printf("%09d\n", x);
      return 0;
    }
  }
  cout << "2\n";
}
