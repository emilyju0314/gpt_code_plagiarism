#include <bits/stdc++.h>
using namespace std;
int N = 1e5 + 10;
map<char, int> mp;
int main() {
  string s;
  cin >> s;
  int sa = 0;
  for (int i = 0; i < s.length(); i++) {
    if (sa == 0 && s[i] == 'a') {
      mp['a']++;
    } else if (sa == 0 && s[i] == 'b') {
      sa = 1;
      mp['b']++;
    } else if (sa == 1 && s[i] == 'b') {
      mp['b']++;
    } else if (sa == 1 && s[i] == 'c') {
      sa = 2;
      mp['c']++;
    } else if (sa == 2 && s[i] == 'c') {
      mp['c']++;
    } else {
      printf("NO\n");
      return 0;
    }
  }
  if (mp['c'] > 0 && mp['b'] > 0 && mp['a'] > 0) {
    if (mp['c'] == mp['a'] || mp['c'] == mp['b']) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  } else {
    printf("NO\n");
  }
}
