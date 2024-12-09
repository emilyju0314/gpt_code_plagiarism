#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int i, n, d, h, start = 1, end = 2;
  cin >> n >> d >> h;
  if (d > (2 * h) || (d == 1 && h == 1 && n != 2)) {
    cout << "-1" << endl;
  } else {
    for (i = 0; i < h; i++) {
      cout << start << " " << end << endl;
      start = end;
      end++;
    }
    start = 1;
    for (i = 0; i < (d - h); i++) {
      cout << start << " " << end << endl;
      start = end;
      end++;
    }
    if (d == h) {
      start = 2;
    } else {
      start = 1;
    }
    for (i = end; i <= n; i++) {
      cout << start << " " << end << endl;
      end++;
    }
  }
  return 0;
}
