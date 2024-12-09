#include <bits/stdc++.h>
using namespace std;
int da, db;
int main() {
  cin >> da >> db;
  if (da == 9) {
    if (db == 1) {
      cout << 9 << ' ' << 10 << endl;
      return 0;
    }
    if (db == 9)
      cout << da * 10 << ' ' << db * 10 + 1 << endl;
    else
      cout << -1 << endl;
    return 0;
  }
  if (da == db) {
    cout << da * 10 << ' ' << db * 10 + 1 << endl;
    return 0;
  }
  if (db - da == 1) {
    cout << da << ' ' << db << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
