#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int n;
  cin >> n;
  switch (n % 4) {
    case 0:
      cout << "1 A" << endl;
      break;
    case 1:
      cout << "0 A" << endl;
      break;
    case 2:
      cout << "1 B" << endl;
      break;
    case 3:
      cout << "2 A" << endl;
      break;
  }
  return 0;
}
