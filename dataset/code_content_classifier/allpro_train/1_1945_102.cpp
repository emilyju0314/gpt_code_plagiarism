#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  string a[3];
  cin >> a[0] >> a[1] >> a[2];
  for (i = 0; i < 3; i++) {
    if ((a[i] == "rock") && (a[(i + 1) % 3] == "scissors") &&
        (a[(i + 2) % 3] == "scissors")) {
      break;
    }
    if ((a[i] == "scissors") && (a[(i + 1) % 3] == "paper") &&
        (a[(i + 2) % 3] == "paper")) {
      break;
    }
    if ((a[i] == "paper") && (a[(i + 1) % 3] == "rock") &&
        (a[(i + 2) % 3] == "rock")) {
      break;
    }
  }
  if (i == 0) {
    cout << 'F' << endl;
  } else if (i == 1) {
    cout << 'M' << endl;
  } else if (i == 2) {
    cout << 'S' << endl;
  } else {
    cout << '?' << endl;
  }
}
