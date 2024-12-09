#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, r = 0, u = 0, j, k = 0;
  char *p;
  cin >> i;
  p = (char *)malloc(sizeof(char) * i);
  for (j = 0; j < i; j++) {
    cin >> *(p + j);
    if ((r == u) && (j != 0)) {
      if ((*(p + j) == 'U') && (*(p + j - 1) == 'U')) k++;
      if ((*(p + j) == 'R') && (*(p + j - 1) == 'R')) k++;
    }
    if (*(p + j) == 'U') u++;
    if (*(p + j) == 'R') r++;
  }
  cout << k;
  return 0;
}
