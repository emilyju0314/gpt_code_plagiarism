#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  cin >> x;
  int i = 0;
  while (i < x.length()) {
    if (x[i] == '9' && i == 0)
      cout << '9';
    else
      cout << min((char)(('9' - x[i]) + '0'), x[i]);
    i++;
  }
  return 0;
}
