#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size(), a[n];
  for (int i = 0; i < n; i++) {
    a[i] = (s[i] - 'a');
  }
  int p = 0;
  while (p < n) {
    if (a[p]) break;
    p++;
  }
  int q = p + 1;
  while (q < n) {
    if (!a[q]) break;
    q++;
  }
  if (p == n) {
    for (int i = 0; i < n - 1; i++) cout << "a";
    cout << "z";
  } else {
    for (int i = p; i < q; i++) {
      a[i]--;
    }
    for (int i = 0; i < n; i++) {
      char h = ('a' + a[i]);
      cout << h;
    }
  }
}
