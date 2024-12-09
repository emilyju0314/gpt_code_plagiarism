#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[m][3];
  int i, j, k;
  for (i = 0; i < m; i++) {
    for (j = 0; j < 3; j++) cin >> arr[i][j];
  }
  int colours[100001];
  for (i = 0; i < 100001; i++) colours[i] = 0;
  int flag[4];
  for (i = 0; i < m; i++) {
    for (k = 0; k <= 3; k++) flag[k] = 0;
    for (j = 0; j < 3; j++) {
      if (colours[arr[i][j]] > 0) flag[colours[arr[i][j]]] = 1;
    }
    for (j = 0; j < 3; j++) {
      if (colours[arr[i][j]] > 0) {
        continue;
      } else {
        for (k = 1; k <= 3; k++) {
          if (flag[k] == 0) {
            flag[k] = 1;
            colours[arr[i][j]] = k;
            break;
          }
        }
      }
    }
  }
  for (i = 0; i < 100001; i++)
    if (colours[i] != 0) cout << colours[i] << " ";
  return 0;
}
