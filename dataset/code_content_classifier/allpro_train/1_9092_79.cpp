#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    cout << 0 << endl;
  } else if (n == 2) {
    cout << 2 << endl;
    cout << 0 << endl;
    cout << 11 << endl;
  } else {
    cout << n - 1 << endl;
    for (int i = 0; i < n - 1; i++) {
      cout << 1;
      for (int j = 0; j < i; j++) cout << 0;
      cout << 1 << endl;
    }
  }
}

