#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if (((a * c * e) < (b * d * f)) || (!c && d) || (!a && b && d))
    cout << endl << "Ron";
  else
    cout << endl << "Hermione";
  return 0;
}
