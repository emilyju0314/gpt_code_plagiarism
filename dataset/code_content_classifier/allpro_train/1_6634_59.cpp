#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int mat[n + 1][m + 1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  long long cntx1 = 0, cntx2 = 0, cnty1 = 0, cnty2 = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 1) cntx1++;
      if (mat[i][j] == 0) cntx2++;
    }
    sum += pow(2, cntx1) + pow(2, cntx2) - 2;
    cntx1 = 0;
    cntx2 = 0;
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (mat[i][j] == 1) cnty1++;
      if (mat[i][j] == 0) cnty2++;
    }
    sum += pow(2, cnty1) + pow(2, cnty2) - 2;
    cnty1 = 0;
    cnty2 = 0;
  }
  cout << sum - n * m << "\n";
  return 0;
}
