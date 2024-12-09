#include <bits/stdc++.h>
using namespace std;
using namespace std;
struct point {
  long long x;
  long long y;
  point(long long a = 0, long long b = 0) {
    x = a;
    y = b;
  }
};
double sqr(double a) { return a * a; }
bool cmp(long long a, long long b) { return a < b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int m;
  int x, y, a, b;
  x = y = 0;
  cin >> m;
  for (int i = 2; i <= 500000; i++) {
    a = i;
    while (a % 2 == 0) {
      a = a / 2;
      x++;
    }
    while (a % 5 == 0) {
      a = a / 5;
      y++;
    }
    if (min(x, y) == m) {
      a = i;
      break;
    }
    if (min(x, y) > m) {
      cout << 0;
      return 0;
    }
  }
  vector<int> z;
  z.push_back(a);
  b = a;
  for (int i = 0; i < 20; i++) {
    b++;
    a = b;
    while (a % 2 == 0) {
      a = a / 2;
      x++;
    }
    while (a % 5 == 0) {
      a = a / 5;
      y++;
    }
    if (min(x, y) == m) z.push_back(b);
    if (min(x, y) > m) {
      break;
    }
  }
  cout << z.size() << endl;
  for (int i = 0; i < z.size(); i++) {
    cout << z[i] << " ";
  }
  return 0;
}
