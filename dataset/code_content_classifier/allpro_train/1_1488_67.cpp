#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int q, n;
  cin >> q;
  while (q--) {
    cin >> n;
    if (n == 2)
      cout << 2 << endl;
    else if (n == 3)
      cout << 1 << endl;
    else if (n % 2 == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
