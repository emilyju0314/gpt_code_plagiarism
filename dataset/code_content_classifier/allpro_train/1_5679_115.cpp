#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, s, x;
  int len, i, j, ans = 0;
  map<string, int> first;
  scanf("%d", &len);
  int b, c, d, e, f, g, h;
  cin >> a;
  cin >> b;
  first[a] += (b * 100);
  cin >> c;
  first[a] -= (c * 50);
  cin >> d >> e >> f >> g >> h;
  first[a] += (d + e + f + g + h);
  ans = first[a];
  x = a;
  len -= 1;
  while (len--) {
    int b, c, d, e, f, g, h;
    cin >> a;
    cin >> b;
    first[a] += (b * 100);
    cin >> c;
    first[a] -= (c * 50);
    cin >> d >> e >> f >> g >> h;
    first[a] += (d + e + f + g + h);
    if (first[a] > ans) {
      ans = first[a];
      x = a;
    }
  }
  cout << x;
  return 0;
}
