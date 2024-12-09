#include <bits/stdc++.h>
using namespace std;
string s, r;
unsigned long long a, b, c, d;
unsigned long long tonum(string s) {
  unsigned long long temp = 0;
  int i = 0;
  while (s[i] == '0') i++;
  for (; i < s.length(); i++) {
    temp *= 10;
    temp += ((int)s[i] - 48);
  }
  return temp;
}
unsigned long long convert(string s) {
  unsigned long long temp = 0;
  int i = 0;
  while (i < s.length() && s[i] == '0') i++;
  for (; i < s.length(); i++) {
    temp *= a;
    if ((int)s[i] < 60)
      temp += ((int)s[i] - 48);
    else
      temp += (((int)s[i] - 65) + 10);
  }
  return temp;
}
string tostring(int x) {
  string t(1, (char)x);
  return t;
}
string decimal2roman(int input) {
  const string roman[13] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                            "XL", "X",  "IX", "V",  "IV", "I"};
  const int decimal[13] = {1000, 900, 500, 400, 100, 90, 50,
                           40,   10,  9,   5,   4,   1};
  string romanvalue = "";
  for (int i = 0; i < 13; i++) {
    while (input >= decimal[i]) {
      input -= decimal[i];
      romanvalue += roman[i];
    }
  }
  return romanvalue;
}
int main() {
  cin >> s;
  a = tonum(s);
  cin >> s;
  if (s[0] == 'R') {
    cin >> s;
    c = tonum(s);
    d = convert(s);
    cout << decimal2roman(d) << endl;
  } else {
    b = tonum(s);
    cin >> s;
    c = tonum(s);
    d = convert(s);
    if (c == 0) {
      cout << c << endl;
      return 0;
    }
    while (d != 0) {
      r.append(tostring(d % b));
      d /= b;
    }
    int i = r.length() - 1;
    while (i >= 0 && r[i] == '0') i--;
    for (; i >= 0; i--) {
      if ((int)r[i] < 10)
        cout << (char)((int)r[i] + 48);
      else
        cout << (char)((int)r[i] + 55);
    }
    cout << endl;
  }
  return 0;
}
