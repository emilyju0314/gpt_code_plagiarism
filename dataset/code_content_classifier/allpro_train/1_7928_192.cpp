#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, before, after;
  cin >> n;
  while (n--) {
    cin >> s >> before >> after;
    if (before >= 2400 && before < after) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
