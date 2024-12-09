#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  bool o = false;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '0') {
      o = true;
      cout << (a.substr(0, i) + a.substr(i + 1)) << endl;
      break;
    }
  }
  if (o == false) {
    cout << (a.substr(0, a.size() - 1)) << endl;
  }
}
