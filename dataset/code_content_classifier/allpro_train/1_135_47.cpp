#include <bits/stdc++.h>
using namespace std;
void solveTask() {
  long long x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  bool ok1 = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ==
             ((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
  bool ok2 = ((x3 - x1) * (y2 - y1)) != ((y3 - y1) * (x2 - x1));
  if (ok1 && ok2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int main() {
  solveTask();
  ios_base::sync_with_stdio(false);
  return 0;
}
