#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l;
  string str;
  cin >> str;
  k = str.size();
  if (k == 1) {
    cout << str[0];
    return 0;
  } else if (k % 2 == 0) {
    l = (k / 2) - 1;
    for (i = 0, j = 1; i <= l, j <= l + 1; i++, j++) {
      cout << str[l - i] << str[l + j];
    }
    return 0;
  } else {
    l = (k / 2);
    cout << str[l];
    for (i = 1, j = 1; i <= l, j <= l; i++, j++) {
      cout << str[l + j] << str[l - i];
    }
    return 0;
  }
  return 0;
}
