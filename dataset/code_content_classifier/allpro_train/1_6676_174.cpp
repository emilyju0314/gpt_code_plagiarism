#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> vec(n, vector<char>(m));
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> vec[i][j];
      if (vec[i][j] == '*') c++;
    }
  }
  int c1 = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (vec[i][j] == '*' && vec[i - 1][j] == '*' && vec[i + 1][j] == '*' &&
          vec[i][j - 1] == '*' && vec[i][j + 1] == '*') {
        int c1 = 1;
        for (int k = i - 1; k >= 0; k--) {
          if (vec[k][j] == '*')
            c1++;
          else
            break;
        }
        for (int k = i + 1; k < n; k++) {
          if (vec[k][j] == '*')
            c1++;
          else
            break;
        }
        for (int k = j - 1; k >= 0; k--) {
          if (vec[i][k] == '*')
            c1++;
          else
            break;
        }
        for (int k = j + 1; k < m; k++) {
          if (vec[i][k] == '*')
            c1++;
          else
            break;
        }
        if (c1 == c)
          cout << "YES";
        else
          cout << "NO";
        return 0;
      }
    }
  }
  cout << "NO";
}
