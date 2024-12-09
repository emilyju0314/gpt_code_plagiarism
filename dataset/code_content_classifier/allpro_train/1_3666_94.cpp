#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char arr[100][100];
  int coordi[6];
  int start = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == '*') {
        coordi[start] = i;
        ++start;
        coordi[start] = j;
        ++start;
      }
    }
  }
  if (coordi[0] == coordi[2]) {
    if (coordi[1] == coordi[5]) {
      cout << coordi[4] + 1 << " " << coordi[3] + 1;
    } else if (coordi[5] == coordi[3]) {
      cout << coordi[4] + 1 << " " << coordi[1] + 1;
    }
  } else if (coordi[2] == coordi[4]) {
    if (coordi[1] == coordi[5]) {
      cout << coordi[0] + 1 << " " << coordi[3] + 1;
    } else if (coordi[1] == coordi[3]) {
      cout << coordi[0] + 1 << " " << coordi[5] + 1;
    }
  } else if (coordi[0] == coordi[4]) {
    if (coordi[1] == coordi[3]) {
      cout << coordi[2] + 1 << " " << coordi[5] + 1;
    } else if (coordi[5] == coordi[3]) {
      cout << coordi[2] + 1 << " " << coordi[1] + 1;
    }
  }
  return 0;
}
