#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  while (cin >> s1 >> s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int l = 0;
    int a = 0;
    for (int i = 0; i < len1; ++i) {
      if (s1[i] == s2[l]) l++;
      if (l == len2) {
        a = 1;
        break;
      }
    }
    int ss1[26];
    memset(ss1, 0, sizeof(ss1));
    int ss2[26];
    memset(ss2, 0, sizeof(ss2));
    int arr = 1;
    int both = 1;
    for (int i = 0; i < len1; ++i) ss1[s1[i] - 'a']++;
    for (int i = 0; i < len2; ++i) ss2[s2[i] - 'a']++;
    for (int i = 0; i < 26; ++i) {
      if (ss1[i] != ss2[i]) arr = 0;
      if (ss1[i] < ss2[i]) both = 0;
    }
    if (a)
      cout << "automaton" << endl;
    else if (arr)
      cout << "array" << endl;
    else if (both)
      cout << "both" << endl;
    else
      cout << "need tree" << endl;
  }
  return 0;
}
