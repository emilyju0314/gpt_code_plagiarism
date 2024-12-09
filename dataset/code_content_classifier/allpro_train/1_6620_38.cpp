#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  if (n < 4) {
    cout << "NO\n";
  } else if (n % 4 == 0 || n % 4 == 2) {
    cout << "YES\n";
    for (i = n; i != 4; i -= 2) cout << i << " - " << i - 1 << " = 1\n";
    for (i = 0; i < (n - 4) / 2; i++) cout << "1 * 1 = 1\n";
    cout << "1 * 2 = 2\n";
    cout << "2 * 3 = 6\n";
    cout << "6 * 4 = 24\n";
  } else if (n % 4 == 3) {
    cout << "YES\n";
    for (i = n; i != 7; i -= 2) cout << i << " - " << i - 1 << " = 1\n";
    for (i = 0; i < (n - 7) / 2; i++) cout << "1 * 1 = 1\n";
    cout << "7 + 6 = 13\n";
    cout << "13 + 5 = 18\n";
    cout << "18 + 4 = 22\n";
    cout << "3 - 2 = 1\n";
    cout << "1 + 1 = 2\n";
    cout << "22 + 2 = 24\n";
  } else if (n % 4 == 1) {
    cout << "YES\n";
    for (i = n; i != 5; i -= 2) cout << i << " - " << i - 1 << " = 1\n";
    for (i = 0; i < (n - 5) / 2; i++) cout << "1 * 1 = 1\n";
    cout << "5 - 3 = 2\n";
    cout << "2 * 4 = 8\n";
    cout << "1 + 2 = 3\n";
    cout << "8 * 3 = 24\n";
  }
  return 0;
}
