#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  char arr[300][300];
  int hash[26] = {0};
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) cin >> arr[i][j];
  }
  char diagonal = arr[0][0];
  int flag = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j || i + j == n - 1) {
        if (arr[i][j] != diagonal) {
          flag = 1;
          break;
        }
      } else {
        if (arr[i][j] == diagonal) {
          flag = 1;
          break;
        } else {
          hash[arr[i][j] - 97] = 1;
        }
      }
    }
    if (flag == 1) break;
  }
  if (flag == 1)
    cout << "NO";
  else {
    int count = 0;
    for (i = 0; i < 26; i++) {
      if (hash[i] != 0) count++;
    }
    if (count == 1)
      cout << "YES";
    else
      cout << "NO";
  }
}
