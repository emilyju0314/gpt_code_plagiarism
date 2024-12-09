#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, hello = "hello";
  cin >> a;
  int n = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == hello[n]) ++n;
    if (n == hello.size()) break;
  }
  if (n == hello.size())
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
