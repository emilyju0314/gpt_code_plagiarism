#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k, x;
  cin >> k;
  string a[12] = {"January",   "February", "March",    "April",
                  "May",       "June",     "July",     "August",
                  "September", "October",  "November", "December"};
  for (int i = 0; i < 12; i++) {
    if (s == a[i]) {
      x = i;
      break;
    }
  }
  k = (k + x) % 12;
  cout << a[k] << "\n";
}
