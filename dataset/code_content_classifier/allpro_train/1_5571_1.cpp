#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, i, Min = 10E6, x, y, req, total = 0, flag = 0;
  map<long int, long int> M1, M2;
  map<long int, long int>::iterator it, it1;
  cin >> n;
  if (n % 2 == 0)
    req = n / 2;
  else
    req = n / 2 + 1;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    if ((it = M1.find(x)) != M1.end())
      it->second++;
    else
      M1.insert(pair<long int, long int>(x, 1));
    if (x != y) {
      if ((it = M2.find(y)) != M2.end())
        it->second++;
      else
        M2.insert(pair<long int, long int>(y, 1));
    }
  }
  for (it1 = M1.begin(); it1 != M1.end(); it1++)
    if (it1->second >= req) {
      flag = 1;
      break;
    }
  if (flag == 0) {
    for (it1 = M1.begin(); it1 != M1.end(); it1++) {
      if ((it = M2.find(it1->first)) != M2.end())
        if (it->second + it1->second >= req && req - it1->second < Min) {
          flag = 2;
          Min = req - it1->second;
        }
    }
    if (Min == 10E6)
      for (it1 = M2.begin(); it1 != M2.end(); it1++)
        if (it1->second >= req && req < Min) {
          flag = 2;
          Min = req;
          break;
        }
  }
  if (flag == 1)
    cout << 0;
  else if (flag == 2)
    cout << Min;
  else
    cout << -1;
  return 0;
}
