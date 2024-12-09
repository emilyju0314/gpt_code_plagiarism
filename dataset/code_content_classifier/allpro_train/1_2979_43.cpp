#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long X = 0, x = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == 'x') x++;
    if (s[i] == 'X') X++;
  }
  if (x == X) {
    cout << "0\n" << s << endl;
  } else if (x > X) {
    long long c = X;
    for (long long i = 0; i < s.size(); i++) {
      if (c == n / 2) {
        break;
      }
      if (s[i] == 'x') {
        s[i] = 'X';
        c++;
      }
    }
    cout << c - X << endl << s << endl;
  } else if (x < X) {
    long long c = x;
    for (long long i = 0; i < s.size(); i++) {
      if (c == n / 2) {
        break;
      }
      if (s[i] == 'X') {
        s[i] = 'x';
        c++;
      }
    }
    cout << c - x << endl << s << endl;
  }
  return 0;
}
