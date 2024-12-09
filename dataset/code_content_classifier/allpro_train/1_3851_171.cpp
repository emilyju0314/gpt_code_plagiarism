#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0;
  cin >> n;
  if (n < 4)
    cout << "NO";
  else if (n % 4 == 0) {
    cout << "YES" << endl;
    for (int i = n + 1 - 1; i >= 7; i--) {
      cout << i << " - " << i - 1 << " = " << 1 << endl;
      cout << i - 3 << " + " << 1 << " = " << i - 2 << endl;
      cout << i - 2 << " - " << i - 2 << " = 0" << endl;
      cout << i - 4 << " + " << 0 << " = " << i - 4 << endl;
      i -= 3;
    }
    cout << 4 << " * " << 3 << " = 12" << endl;
    cout << 12 << " * " << 1 << " = 12" << endl;
    cout << 12 << " * " << 2 << " = 24" << endl;
  } else if (n % 4 == 1) {
    cout << "YES" << endl;
    for (int i = n + 1 - 1; i >= 7; i--) {
      cout << i << " - " << i - 1 << " = " << 1 << endl;
      cout << i - 3 << " + " << 1 << " = " << i - 2 << endl;
      cout << i - 2 << " - " << i - 2 << " = 0" << endl;
      cout << i - 4 << " + " << 0 << " = " << i - 4 << endl;
      i -= 3;
    }
    cout << 4 << " * " << 5 << " = 20" << endl;
    cout << 20 << " + " << 3 << " = 23" << endl;
    cout << 23 << " + " << 2 << " = 25" << endl;
    cout << 25 << " - " << 1 << " = 24" << endl;
  } else if (n % 4 == 2) {
    cout << "YES" << endl;
    for (int i = n + 1 - 1; i >= 7; i--) {
      cout << i << " - " << i - 1 << " = " << 1 << endl;
      cout << i - 3 << " + " << 1 << " = " << i - 2 << endl;
      cout << i - 2 << " - " << i - 2 << " = 0" << endl;
      cout << i - 4 << " + " << 0 << " = " << i - 4 << endl;
      i -= 3;
    }
    cout << 6 << " - " << 5 << " = 1" << endl;
    cout << 1 << " * " << 1 << " = 1" << endl;
    cout << 4 << " * " << 3 << " = 12" << endl;
    cout << 12 << " * " << 1 << " = 12" << endl;
    cout << 12 << " * " << 2 << " = 24" << endl;
  } else if (n % 4 == 3) {
    cout << "YES" << endl;
    cout << 5 << " - " << 3 << " = 2" << endl;
    cout << 4 << " * " << 2 << " = 8" << endl;
    cout << 1 << " + " << 2 << " = 3" << endl;
    cout << 8 << " * " << 3 << " = 24" << endl;
    for (int i = n + 1 - 1; i >= 6; i--) {
      cout << i << " - " << i - 1 << " = " << 1 << endl;
      cout << 24 << " * " << 1 << " = " << 24 << endl;
      i -= 1;
    }
  }
  return 0;
}
