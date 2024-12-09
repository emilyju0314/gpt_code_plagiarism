#include <bits/stdc++.h>
using namespace std;
string s;
int n, j;
bool f(bool positive) {
  ++j;
  if (positive) {
    while (j < n and s[j] == '-') {
      if (not f(false)) return false;
    }
    if (j >= n) return false;
    ++j;
  } else {
    while (j < n and s[j] == '+') {
      if (not f(true)) return false;
    }
    if (j >= n) return false;
    ++j;
  }
  return true;
}
int main() {
  cin >> s;
  n = s.length();
  if (n % 2 == 1)
    cout << "No" << endl;
  else {
    j = 0;
    bool b = true;
    while (b and j < n) {
      if (s[j] == '+')
        b = f(true);
      else
        b = f(false);
    }
    if (b)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
