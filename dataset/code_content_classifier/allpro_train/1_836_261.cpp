#include <bits/stdc++.h>
using namespace std;
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m;
  cin >> n >> m;
  set<int> row, col;
  char mat[n][m];
  for (int i = 0; i < n; i++) cin >> mat[i];
  for (long long i = (0); i < (n); ++i) {
    for (long long j = (0); j < (n); ++j) {
      long long cnt = 0, cnt1 = 0;
      for (long long k = (0); k < (m); ++k) {
        if (mat[i][k] == '#' && mat[j][k] == '#') cnt++;
        if (mat[i][k] == '#') cnt1++;
      }
      if (cnt == 0 || cnt == cnt1)
        continue;
      else {
        cout << "No";
        exit(0);
      }
    }
  }
  cout << "Yes";
}
