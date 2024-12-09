#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  float r, h, bot, up;
  cin >> r >> h;
  bot = (int(h) / int(r)) * 2;
  up = int(h) % int(r);
  if (4 * up * up > 3.0 * r * r) {
    cout << int(bot + 3);
    return 0;
  }
  if (up >= r / 2)
    cout << int(bot + 2);
  else
    cout << int(bot + 1);
  return 0;
}
