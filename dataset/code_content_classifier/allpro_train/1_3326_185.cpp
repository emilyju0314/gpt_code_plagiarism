#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char x[101];
  int capital, small, num;
  cin >> x;
  for (int i = 0; x[i]; i++) {
    if (x[i] >= 48 && x[i] <= 57) num = 1;
    if (x[i] >= 65 && x[i] <= 90) capital = 1;
    if (x[i] >= 97 && x[i] <= 122) small = 1;
  }
  if (strlen(x) >= 5 && small == 1 && capital == 1 && num == 1)
    cout << "Correct";
  else
    cout << "Too weak";
}
