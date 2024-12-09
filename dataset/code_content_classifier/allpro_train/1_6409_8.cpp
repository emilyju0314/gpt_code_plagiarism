#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  long long int moves = 0;
  while (s.length() > 1) {
    long long int pp = 0;
    moves++;
    for (long long int i = 0; i < s.length(); i++) pp += (s[i] - '0');
    stringstream ss;
    ss << pp;
    s = ss.str();
  }
  cout << moves << endl;
  return 0;
}
