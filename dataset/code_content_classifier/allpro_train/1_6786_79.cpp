#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      if (j) cout << " ";
      if (i == j)
        cout << b;
      else
        cout << 0;
    }
    cout << endl;
  }
  return 0;
}
