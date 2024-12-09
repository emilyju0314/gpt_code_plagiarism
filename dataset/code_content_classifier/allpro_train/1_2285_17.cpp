#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int res[] = {1,         0, 18,        0, 1800,      0, 670320,    0,
             734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};
int main() {
  int n;
  cin >> n;
  cout << res[n - 1];
  return 0;
}
