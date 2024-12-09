#include <bits/stdc++.h>
using namespace std;
const int n = 10000020;
int a[n] = {0};
int main() {
  int k;
  cin >> k;
  int m = k;
  for (int i = 0; i < k; i++) {
    int p;
    cin >> p;
    a[p] = 1;
    while (a[m] == 1) {
      cout << m << " ";
      m--;
    }
    cout << endl;
  }
  return 0;
}
