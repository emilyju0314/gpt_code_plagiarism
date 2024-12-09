#include <bits/stdc++.h>
using namespace std;
int main() {
  long long total, before, after, gas, capacity, k;
  cin >> total >> capacity >> gas >> k;
  before = gas;
  after = total - gas;
  if (k == 1) {
    if (before > capacity || after > capacity)
      cout << "-1" << endl;
    else if (capacity >= total)
      cout << "0" << endl;
    else
      cout << "1" << endl;
  } else if (k == 2) {
    if (before > capacity || 2 * after > capacity)
      cout << "-1" << endl;
    else if (2 * total <= capacity)
      cout << "0" << endl;
    else if (before + 2 * after <= capacity)
      cout << "1" << endl;
    else
      cout << "2" << endl;
  } else {
    if (before > capacity)
      cout << "-1" << endl;
    else if (2 * before > capacity || 2 * after > capacity)
      cout << "-1" << endl;
    else {
      long long taken = capacity;
      long long ans = 0;
      bool dir = false;
      while (k--) {
        if (dir == false) {
          dir = true;
          taken -= before;
          if (k == 0 && taken < after) {
            ans++;
            taken = capacity;
          } else if (taken < 2 * after && k) {
            ans++;
            taken = capacity;
          }
          taken -= after;
        } else if (dir == true) {
          dir = false;
          taken -= after;
          if (k == 0 && taken < before) {
            ans++;
            taken = capacity;
          } else if (taken < 2 * before && k) {
            ans++;
            taken = capacity;
          }
          taken -= before;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
