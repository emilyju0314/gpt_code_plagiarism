#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, i, j, k, w, l, d, count = 0, x, max = INT_MIN,
                                        min = INT_MAX, lane, desk;
  char g;
  cin >> n >> m >> k;
  d = m;
  w = m * 2;
  if (k >= w) {
    if (k % w != 0)
      lane = k / w + 1;
    else {
      lane = k / w;
    }
  } else {
    lane = 1;
  }
  if (k & 1) {
    g = 'L';
  } else {
    g = 'R';
  }
  if (g == 'R') {
    x = w * lane;
    while (x != k) {
      x -= 2;
      d--;
    }
  } else {
    x = w * lane;
    x -= 1;
    while (x != k) {
      x -= 2;
      d--;
    }
  }
  cout << lane << " " << d << " " << g << "\n";
  return 0;
}
