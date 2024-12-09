#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  bool ckr;
  int a = 0, b = 0, c = 0, i, ln, ok = 0;
  cin >> s;
  ln = s.size();
  for (i = 0; i < ln; i++) {
    if (s[i] == '+')
      ok = 1;
    else if (s[i] == '=')
      ok = 2;
    else if (!ok && s[i] == '|')
      a++;
    else if (ok == 1 && s[i] == '|')
      b++;
    else if (ok == 2 && s[i] == '|')
      c++;
  }
  if (a + b == c)
    cout << s;
  else if (a + b == c + 2) {
    if (a > b) {
      for (i = 1; i < a; i++) cout << "|";
      cout << "+";
      for (i = 1; i <= b; i++) cout << "|";
    } else {
      for (i = 1; i <= a; i++) cout << "|";
      cout << "+";
      for (i = 1; i < b; i++) cout << "|";
    }
    cout << "=|";
    for (i = 1; i <= c; i++) cout << "|";
    cout << endl;
  } else if (a + b == c - 2) {
    for (i = 1; i <= a; i++) cout << "|";
    cout << "+";
    for (i = 1; i <= b; i++) cout << "|";
    cout << "|=";
    for (i = 1; i < c; i++) cout << "|";
    cout << endl;
  } else
    cout << "Impossible" << endl;
}
