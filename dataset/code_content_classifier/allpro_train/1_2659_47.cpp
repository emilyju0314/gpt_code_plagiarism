#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  getchar();
  string s, scopy1, scopy2;
  cin >> s;
  scopy1 = s;
  scopy2 = s;
  if (n > 3) {
    scopy1.erase(0, n - 3);
    scopy2.erase(3, n - 3);
  }
  if (s == "01" || s == "10") {
    cout << "Yes" << endl;
    return 0;
  }
  if (s == "00" || s == "0" || scopy2 == "001" || scopy1 == "100") {
    cout << "No" << endl;
    return 0;
  }
  if (s.find("000") != string::npos || s.find("11") != string::npos) {
    cout << "No" << endl;
  } else
    cout << "Yes" << endl;
  return 0;
}
