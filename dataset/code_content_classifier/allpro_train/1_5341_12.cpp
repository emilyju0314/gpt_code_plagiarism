#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int b = 0;
  ;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (v < 0) v = -v;
    b = b + v;
  }
  cout << b << endl;
  return 0;
}
