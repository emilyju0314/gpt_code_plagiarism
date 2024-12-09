#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, m, a;
  char c;
  scanf("%d%c%d", &h, &c, &m);
  cin >> a;
  m += a;
  h += m / 60;
  m -= (m / 60) * 60;
  h -= (h / 24) * 24;
  if (h < 10)
    cout << "0" << h << ":";
  else
    cout << h << ":";
  if (m < 10)
    cout << "0" << m;
  else
    cout << m;
  return 0;
}
