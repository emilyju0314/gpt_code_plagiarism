#include <bits/stdc++.h>
using namespace std;
int T;
struct pos {
  int x, y, fir1, fir2, las1, las2;
} maxi, mini, now;
string str;
int main() {
  scanf("%d", &T);
  while (T--) {
    maxi.x = maxi.y = 0;
    maxi.fir1 = mini.fir1 = maxi.fir2 = mini.fir2 = maxi.las1 = mini.las1 =
        maxi.las2 = mini.las2 = -1;
    mini.x = mini.y = 0;
    now.x = now.y = 0;
    cin >> str;
    int siz = str.size();
    for (int i = 0; i < siz; i++) {
      if (str[i] == 'A') now.y--;
      if (str[i] == 'S') now.x++;
      if (str[i] == 'D') now.y++;
      if (str[i] == 'W') now.x--;
      if (now.x == mini.x) mini.las1 = i;
      if (now.x == maxi.x) maxi.las1 = i;
      if (now.y == mini.y) mini.las2 = i;
      if (now.y == maxi.y) maxi.las2 = i;
      if (now.x > maxi.x) maxi.x = now.x, maxi.las1 = i, maxi.fir1 = i;
      if (now.y > maxi.y) maxi.y = now.y, maxi.las2 = i, maxi.fir2 = i;
      if (now.x < mini.x) mini.x = now.x, mini.las1 = i, mini.fir1 = i;
      if (now.y < mini.y) mini.y = now.y, mini.las2 = i, mini.fir2 = i;
    }
    if (maxi.x - mini.x < maxi.y - mini.y)
      swap(maxi.x, maxi.y), swap(mini.x, mini.y), swap(maxi.las1, maxi.las2),
          swap(mini.las1, mini.las2), swap(maxi.fir1, maxi.fir2),
          swap(mini.fir1, mini.fir2);
    if ((maxi.las2 < mini.fir2 || maxi.fir2 > mini.las2) && maxi.y - mini.y > 1)
      printf("%lld\n", (maxi.y - mini.y) * (long long)(maxi.x - mini.x + 1));
    else if ((maxi.las1 < mini.fir1 || maxi.fir1 > mini.las1) &&
             maxi.x - mini.x > 1)
      printf("%lld\n", (maxi.y - mini.y + 1) * (long long)(maxi.x - mini.x));
    else
      printf("%lld\n",
             (maxi.y - mini.y + 1) * (long long)(maxi.x - mini.x + 1));
  }
  return 0;
}
