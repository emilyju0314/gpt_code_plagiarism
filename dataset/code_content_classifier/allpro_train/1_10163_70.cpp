#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
void solve() {
  long long int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  long long int area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long int x = INT_MAX, y = INT_MAX;
      long long int l = 1, b = 1;
      for (int k = i; k < n; k++) {
        if (s[k][j] == '1') {
          l--;
          break;
        }
        int flag = 0;
        b = 1;
        for (int l = j; l < m; l++) {
          if ((s[k][l] == '0') && flag == 1) {
            b++;
          } else if (s[k][l] == '0') {
            flag = 1;
          } else {
            y = min(y, b);
            break;
          }
          if (b == y) {
            break;
          }
        }
        y = min(y, b);
        area = max(area, 2 * (l + y));
        l++;
      }
    }
  }
  cout << area << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
