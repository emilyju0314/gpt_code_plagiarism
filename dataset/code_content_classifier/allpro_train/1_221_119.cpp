#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, player1, player2, watcher = 3;
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[0] == 3) {
      cout << "NO";
      return 0;
    }
    if (i != 0) {
      player1 = a[i - 1];
      player2 = watcher;
      watcher = 6 - player1 - player2;
      if (watcher == a[i]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
