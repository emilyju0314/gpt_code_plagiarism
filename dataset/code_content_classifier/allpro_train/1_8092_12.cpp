#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    int day = n;
    int j = 0;
    int q = m;
    while (m <= day) {
      day++;
      m = m + q;
    }
    cout << day << endl;
  }
  return 0;
}
