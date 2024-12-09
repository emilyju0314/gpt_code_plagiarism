#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int l, r, d;
    cin >> l >> r >> d;
    if (d < l) {
      cout << d;
    } else {
      cout << (long long int)(d * (1 + (floor)(r / d)));
    }
    cout << endl;
  }
}
