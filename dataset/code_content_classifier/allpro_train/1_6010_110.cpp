#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int d;
  if (min(m, n) & 1) {
    cout << "Akshat"
         << "\n";
  } else {
    cout << "Malvika"
         << "\n";
  }
  return 0;
}
