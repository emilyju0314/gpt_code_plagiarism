#include <bits/stdc++.h>
using namespace std;
void calc() {
  int r, g, b, res = 30;
  cin >> r >> g >> b;
  if (r % 2) r++;
  if (g % 2) g++;
  if (b % 2) b++;
  r /= 2;
  g /= 2;
  b /= 2;
  res = max(res, 30 + (r == 0 ? 0 : (r - 1) * 3));
  res = max(res, 30 + (g == 0 ? 0 : (g - 1) * 3 + 1));
  res = max(res, 30 + (b == 0 ? 0 : (b - 1) * 3 + 2));
  cout << res;
}
int main() {
  calc();
  return 0;
}
