#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == 'r') cout << i + 1 << endl;
  for (int i = s.length() - 1; i >= 0; i--)
    if (s[i] == 'l') cout << i + 1 << endl;
}