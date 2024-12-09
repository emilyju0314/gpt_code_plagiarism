#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a[n];
  int c1 = 0, c2 = 0;
  int f = 0;
  int b[n];
  int sum = 0;
  for (int i = 0; i < n; i++) b[i] = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      a[i] = 0;
      c1++;
    } else {
      a[i] = 1;
      c2++;
    }
  }
  if (c1 != c2)
    cout << "-1" << endl;
  else {
    if (a[0] == 0) b[0] = 1;
    if (a[0] == 1) b[0] = -1;
    for (int i = 1; i < n; i++) {
      if (a[i] == 0) b[i] = b[i - 1] + 1;
      if (a[i] == 1) b[i] = b[i - 1] - 1;
    }
    int i = 0;
    for (i = 0; i < n; i++) {
      if (b[i] == -1) {
        for (int j = i + 1; j < n; j++) {
          if (b[j] == 0) {
            sum = sum + (j - i + 1);
            i = j;
            break;
          }
        }
      }
    }
    cout << sum << endl;
  }
}
