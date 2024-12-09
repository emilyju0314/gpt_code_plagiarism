#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int xoxo, count = 0, digitttt;
  cin >> xoxo;
  while (xoxo != 0) {
    digitttt = xoxo % 10;
    if (digitttt == 4 || digitttt == 7) {
      count++;
    }
    xoxo = xoxo / 10;
  }
  if (count == 4 || count == 7) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
