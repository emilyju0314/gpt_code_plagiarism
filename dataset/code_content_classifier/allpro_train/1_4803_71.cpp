#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n == 1 || n == 2) {
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }
  if (n == 3) {
    cout << 2 << endl;
    cout << 1 << ' ' << 3 << endl;
  }
  if (n == 4) {
    cout << 4 << endl;
    cout << 2 << ' ' << 4 << ' ' << 1 << ' ' << 3 << endl;
  }
  if (n > 4) {
    cout << n << endl;
    for (int i = 1; i <= n; i = i + 2) {
      cout << i << ' ';
    }
    for (int i = 2; i <= n; i = i + 2) {
      cout << i << ' ';
    }
  }
}
