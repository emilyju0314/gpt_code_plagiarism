#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<long long, long long> a[3];
  for (int i = 0; i < 3; i++) cin >> a[i].first >> a[i].second;
  int x_equal = 0, y_equal = 0;
  long long x_max[2], y_max[2];
  x_max[0] = x_max[1] = a[0].first;
  y_max[0] = y_max[1] = a[0].second;
  long long x_rem, y_rem;
  int cnt = 0;
  for (int i = 1; i < 3; i++) {
    if (a[i].first == a[0].first) {
      cnt++;
      y_max[0] = max(y_max[0], a[i].second);
      y_max[1] = min(y_max[1], a[i].second);
    } else
      y_rem = a[i].second;
  }
  if (cnt)
    x_equal = cnt + 1;
  else if (a[1].first == a[2].first) {
    x_equal = 2;
    y_max[0] = max(a[1].second, a[2].second);
    y_max[1] = min(a[1].second, a[2].second);
    y_rem = a[0].second;
  }
  cnt = 0;
  for (int i = 1; i < 3; i++) {
    if (a[i].second == a[0].second) {
      cnt++;
      x_max[0] = max(x_max[0], a[i].first);
      x_max[1] = min(x_max[1], a[i].first);
    } else
      x_rem = a[i].first;
  }
  if (cnt)
    y_equal = cnt + 1;
  else if (a[1].second == a[2].second) {
    y_equal = 2;
    x_max[0] = max(a[1].first, a[2].first);
    x_max[1] = min(a[1].first, a[2].first);
    x_rem = a[0].first;
  }
  if (x_equal == 3 || y_equal == 3) {
    cout << "1\n";
    return 0;
  } else if (x_equal == 2 && y_equal == 2) {
    cout << "2\n";
    return 0;
  } else if (x_equal == 2) {
    if (y_rem < y_max[0] && y_rem > y_max[1]) {
      cout << "3\n";
      return 0;
    }
    cout << "2\n";
    return 0;
  } else if (y_equal == 2) {
    if (x_rem < x_max[0] && x_rem > x_max[1]) {
      cout << "3\n";
      return 0;
    }
    cout << "2\n";
    return 0;
  } else
    cout << "3\n";
  return 0;
}
