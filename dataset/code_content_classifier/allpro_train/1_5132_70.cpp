#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, currX, currY, k, dx, dy;
  int stepx, stepy, step;
  long long int total = 0;
  scanf("%d%d", &n, &m);
  scanf("%d%d", &currX, &currY);
  scanf("%d", &k);
  while (k--) {
    scanf("%d%d", &dx, &dy);
    if (dx > 0) {
      stepx = (n - currX) / dx;
    } else if (dx == 0) {
      stepx = INT_MAX;
    } else {
      stepx = (currX - 1) / (-dx);
    }
    if (dy > 0) {
      stepy = (m - currY) / dy;
    } else if (dy == 0) {
      stepy = INT_MAX;
    } else {
      stepy = (currY - 1) / (-dy);
    }
    step = (stepx < stepy) ? stepx : stepy;
    total += step;
    currX = currX + step * dx;
    currY = currY + step * dy;
  }
  cout << total;
  printf("\n");
  return 0;
}
