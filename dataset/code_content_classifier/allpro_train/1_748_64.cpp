#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, b = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s1, s;
    cin >> s1 >> s;
    if (s == "soft")
      a++;
    else
      b++;
  }
  if (a == 1 && b == 0) {
    cout << 1;
    return 0;
  }
  if (a == 0 && b == 1) {
    cout << 1;
    return 0;
  }
  if (a == 1 && b == 1) {
    cout << 2;
    return 0;
  }
  a = max(a, b);
  for (int i = 1; i < 1000; i++)
    if (i % 2 == 1) {
      if (i * i / 2 + 1 >= a) {
        cout << i;
        return 0;
      }
    } else {
      if (i * i / 2 >= a) {
        cout << i;
        return 0;
      }
    }
  return 0;
}
