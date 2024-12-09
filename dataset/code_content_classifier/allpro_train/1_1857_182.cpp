#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a < b) {
    cout << "-1";
    return 0;
  }
  int c;
  if (a % 2 == 0)
    c = a / 2;
  else
    c = (a / 2) + 1;
  while ((c % b) != 0) c++;
  cout << c;
  return 0;
}
