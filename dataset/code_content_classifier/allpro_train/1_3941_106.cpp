#include <bits/stdc++.h>
using namespace std;
int n;
int a[100002];
bool done[100002];
bool printed[100002];
int len[100002];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int one = 0;
  int two = 0;
  for (int i = 1; i <= n; i++) {
    int cur = i;
    int l = 0;
    while (!done[cur]) {
      done[cur] = true;
      cur = a[cur];
      l++;
    }
    if (l == 1) one = cur;
    if (l == 2) two = cur;
    len[cur] = l;
  }
  if (one != 0) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      if (i != one) {
        cout << one << " " << i << endl;
      }
    }
  } else if (two != 0) {
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if ((len[i] & 1) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES" << endl;
      cout << two << " " << a[two] << endl;
      for (int i = 1; i <= n; i++) {
        if (i != two && i != a[two]) {
          int that = i;
          while (!printed[that]) {
            cout << two << " " << that << endl;
            printed[that] = true;
            two = a[two];
            that = a[that];
          }
        }
      }
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}
