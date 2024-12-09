#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<string> m(n);
  for (int i = 0; i < n; i++) cin >> m[i];
  bool poss = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int count = 0;
      if (i > 0 && m[i - 1][j] == 'o') count++;
      if (i < n - 1 && m[i + 1][j] == 'o') count++;
      if (j > 0 && m[i][j - 1] == 'o') count++;
      if (j < n - 1 && m[i][j + 1] == 'o') count++;
      if (count % 2) {
        poss = false;
        break;
      }
    }
    if (!poss) break;
  }
  if (poss)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
  return 0;
}
