#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, r = 0, g = 0, b = 0, maxi, spare, maxi2, mini;
  string s;
  cin >> x >> s;
  for (int i = 1; i < x; i++) {
    if (s[i] == s[i - 1]) r++;
  }
  cout << r;
}
