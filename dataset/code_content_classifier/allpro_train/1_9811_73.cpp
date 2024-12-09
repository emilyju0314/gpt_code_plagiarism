#include <bits/stdc++.h>
using namespace std;
int n, r, R;
int main() {
  cin >> n >> R >> r;
  if (n != 1) {
    if (r * (1 / sin(3.14159265358979323846 / n) + 1) <= R + 1e-5) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (r <= R) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
