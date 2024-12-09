#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char second[1002];
  char t[1002];
  scanf("%s %s", second, t);
  int k = 0;
  int x, y;
  int finalsmall = 1e7;
  for (int i = 0; i <= m - n; i++) {
    int small = 0;
    for (int j = 0; j < n; j++) {
      if (second[j] != t[i + j]) small++;
    }
    if (small < finalsmall) {
      finalsmall = small;
      k = i;
    }
  }
  cout << finalsmall << endl;
  for (int i = 0; i < n; i++) {
    if (second[i] != t[i + k]) cout << i + 1 << " ";
  }
  cout << endl;
  return 0;
}
