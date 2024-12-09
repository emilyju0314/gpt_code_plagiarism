#include <bits/stdc++.h>
using namespace std;
int ar[100];
int mat[100][100], cnt[21][21], n, m, f, s;
int chk() {
  memset(cnt, 0, sizeof(cnt));
  int a;
  for (int i = 0; i < n; i++) {
    a = 0;
    for (int j = 0; j < m; j++) {
      if (ar[j] != mat[i][j] && cnt[i][j] == 0) {
        a++;
        if (a == 2) return 0;
        int b = 0;
        for (int k = 0; k < m; k++) {
          if (mat[i][k] == ar[j]) {
            if (ar[k] == mat[i][j] && ar[j] == mat[i][k])
              cnt[i][j]++, cnt[i][k]++, b++;
          }
        }
        if (b == 0) {
          f = mat[i][j] - 1;
          s = j;
          return 0;
        }
      }
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  int i, j, x = 0, y;
  cin >> n >> m;
  for (i = 0; i < m; i++) ar[i] = i + 1;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> mat[i][j];
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      swap(ar[i], ar[j]);
      x = max(chk(), x);
      swap(ar[i], ar[j]);
    }
  x = max(chk(), x);
  for (i = 0; i < n; i++) swap(mat[i][f], mat[i][s]);
  x = max(chk(), x);
  if (x == 0)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
