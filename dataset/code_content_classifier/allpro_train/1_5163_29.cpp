#include <bits/stdc++.h>
using namespace std;
char a[1000][4];
int main() {
  int n;
  cin >> n;
  if (n % 2) {
    for (int i = 0; i < n; i += 2) {
      a[i][0] = 'a' + i % 6;
      a[i + 1][0] = 'a' + i % 6;
    }
    for (int i = 0; i < n; i += 2) {
      a[i][1] = 'f' + i % 6;
      a[i + 1][1] = 'f' + i % 6;
    }
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < n - 1; i++) cout << a[i][j];
      cout << 'z';
      cout << endl;
    }
    for (int j = 0; j < 2; j++) {
      cout << 'w';
      for (int i = 0; i < n - 1; i++) cout << a[i][j];
      cout << endl;
    }
  } else {
    if (n == 2) {
      cout << "jj\nhh\ngg\nff";
      return 0;
    }
    for (int i = 0; i < n; i += 2)
      cout << (char)('a' + i % 6) << (char)('a' + i % 6);
    cout << endl << 'z';
    for (int i = 1; i < n - 1; i += 2)
      cout << (char)('f' + i % 6) << (char)('f' + i % 6);
    cout << 'z' << endl;
    cout << 'z';
    for (int i = 1; i < n - 1; i += 2)
      cout << (char)('q' + i % 6) << (char)('q' + i % 6);
    cout << 'z' << endl;
    for (int i = 0; i < n; i += 2)
      cout << (char)('a' + i % 6) << (char)('a' + i % 6);
  }
}
