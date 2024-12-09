#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s = "";
  while (n--) {
    s = char(n % 26 + 'a') + s;
    n /= 26;
  }
  cout << s << endl;
  return 0;
}