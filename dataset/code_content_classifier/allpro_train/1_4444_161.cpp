#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1;
  string s2;
  cin >> s1 >> s2;
  int len1 = s1.length();
  int len2 = s2.length();
  if (len1 != len2) {
    cout << "NO";
    return 0;
  } else {
    int count = 0;
    char char1a, char1b, char2a, char2b;
    for (int i = 0; i < len1; i++) {
      if (s1[i] != s2[i]) {
        count++;
        if (count == 1) {
          char1a = s1[i];
          char2a = s2[i];
        } else if (count == 2) {
          char1b = s1[i];
          char2b = s2[i];
        } else {
          cout << "NO";
          return 0;
        }
      }
    }
    if (char1a == char2b && char1b == char2a) {
      cout << "YES";
    } else
      cout << "NO";
  }
  return 0;
}
