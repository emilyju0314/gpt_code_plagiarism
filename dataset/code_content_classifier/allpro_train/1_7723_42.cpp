#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int x = s[s.size() - 1] - '0';
  cout << x % 2;
  return 0;
}
