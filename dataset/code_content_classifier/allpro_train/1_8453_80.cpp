#include <bits/stdc++.h>
using namespace std;
const int Max = 1002;
struct node {
  int x;
  int y;
} xx[Max];
bool cmp(const node &a, const node &b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
int main() {
  int n, m, k, t;
  while (cin >> n >> m >> k >> t) {
    for (int i = 0; i < k; i++) {
      cin >> xx[i].x;
      cin >> xx[i].y;
    }
    sort(xx, xx + k, cmp);
    int cn;
    int x;
    int y;
    int flag;
    int flagk;
    for (int i = 0; i < t; i++) {
      cn = 0;
      cin >> x >> y;
      flag = (x - 1) * m + y;
      for (int j = 0; j < k; j++) {
        flagk = (xx[j].x - 1) * m + xx[j].y;
        if (flagk >= flag)
          break;
        else {
          cn++;
        }
      }
      if (flag == flagk) {
        cout << "Waste" << endl;
        continue;
      } else {
        if ((flag - cn) % 3 == 1)
          cout << "Carrots" << endl;
        else if ((flag - cn) % 3 == 2)
          cout << "Kiwis" << endl;
        else
          cout << "Grapes" << endl;
      }
    }
  }
  return 0;
}
