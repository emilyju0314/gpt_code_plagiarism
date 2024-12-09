#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100001;
const int MOD = 1e9 + 7;
mt19937 rnd(100);
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, x;
  vector<vector<int> > a;
  cin >> n >> m;
  a.assign(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> x;
      a[i][j] = (int)(x != a[i][j]);
    }
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) sum += a[i][j];
    if (sum % 2) {
      cout << "No";
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) sum += a[j][i];
    if (sum % 2) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
