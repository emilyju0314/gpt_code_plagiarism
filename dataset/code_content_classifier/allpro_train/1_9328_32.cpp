#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int i, a, num = 0;
  cin >> a;
  cin >> str;
  for (i = 1; i < a - 1; i++) {
    if (str[i] == 'x') {
      if ((str[i + 1] == 'x') && (str[i - 1] == 'x')) {
        num++;
      }
    }
  }
  cout << num << endl;
  return 0;
}
