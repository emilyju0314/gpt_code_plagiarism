#include <bits/stdc++.h>
using namespace std;
char str[1000];
int main() {
  int a, b, i, r;
  cin >> a >> b >> r;
  if (a < (2 * r) || b < (2 * r))
    cout << "Second";
  else
    cout << "First";
}
