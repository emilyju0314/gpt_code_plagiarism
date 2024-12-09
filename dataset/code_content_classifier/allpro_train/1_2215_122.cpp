#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, a, out = 0;
  ;
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a <= h) out++;
    if (a > h) out = out + 2;
  }
  cout << out;
  return 0;
}
