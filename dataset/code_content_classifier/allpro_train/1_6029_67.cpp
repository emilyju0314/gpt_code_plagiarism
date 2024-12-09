#include <bits/stdc++.h>
const int N = 1000001;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, c;
  cin >> n >> m >> c;
  int a[n + 1];
  fill(a, a + n + 1, c + 10);
  while (m--) {
    int e;
    cin >> e;
    if (e <= c / 2) {
      for (int i = 1; i < n + 1; i++) {
        if (e < a[i]) {
          a[i] = e;
          cout << i << '\n' << flush;
          break;
        }
      }
    } else {
      for (int i = n; i; i--) {
        if (a[i] == c + 10 || a[i] < e) {
          a[i] = e;
          cout << i << '\n' << flush;
          break;
        }
      }
    }
    bool cs = (a[1] < c + 10);
    for (int i = 2; i < n + 1; i++) {
      if (a[i] == c + 10 || a[i - 1] > a[i]) {
        cs = false;
        break;
      }
    }
    if (cs) {
      return 0;
    }
  }
}
