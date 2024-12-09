#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.') {
      if (s[i - 1] + 1 > '9') {
        cout << "GOTO Vasilisa." << endl;
        return 0;
      }
      if (s[i + 1] < '5') {
        a = i - 1;
        break;
      } else if (s[i + 1] >= '5') {
        ++s[i - 1];
        a = i - 1;
        break;
      }
    }
  }
  for (int i = 0; i < a + 1; ++i) {
    cout << s[i];
  }
  cout << endl;
}
