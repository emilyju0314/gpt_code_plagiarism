#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int a[100001];
    int c = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]] = i;
    }
    bool d = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != i && !d) {
        if (a[m[i]] == i && a[i] == m[i]) {
          swap(a[i], a[m[i]]);
          d = 1;
        }
      }
      if (a[i] == i) {
        c++;
      }
    }
    if (!d) {
      d = c = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] != i && !d) {
          if (a[m[i]] == i || a[i] == m[i]) {
            swap(a[i], a[m[i]]);
            d = 1;
          }
        }
        if (a[i] == i) {
          c++;
        }
      }
      cout << c << endl;
    } else {
      cout << c << endl;
    }
  }
  return 0;
}
