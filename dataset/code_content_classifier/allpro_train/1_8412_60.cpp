#include <bits/stdc++.h>
using namespace std;
const int mod = 1E6 + 3;
const int size = 5E5 + 1;
char *str[size];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < (int)n; i++) {
    str[i] = (char *)malloc(m + 1);
    cin >> str[i];
  }
  int res = 1;
  for (int i = 0; i < (int)n; i++) {
    int sign = 0;
    for (int j = 0; j < (int)m; j++) {
      int c = str[i][j] - '0';
      if (c == 1 || c == 2) sign |= j % 2 + 1;
      if (c == 3 || c == 4) sign |= 2 - j % 2;
    }
    if (sign == 0)
      res = res * 2 % mod;
    else if (sign == 3)
      res = 0;
  }
  for (int j = 0; j < (int)m; j++) {
    int sign = 0;
    for (int i = 0; i < (int)n; i++) {
      int c = str[i][j] - '0';
      if (c == 1 || c == 4) sign |= i % 2 + 1;
      if (c == 3 || c == 2) sign |= 2 - i % 2;
    }
    if (sign == 0)
      res = res * 2 % mod;
    else if (sign == 3)
      res = 0;
  }
  cout << res << endl;
  return 0;
}
