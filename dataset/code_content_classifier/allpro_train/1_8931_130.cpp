#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int r, g, b;
    cin >> r >> g >> b;
    if (max(r, max(g, b)) <= min(r, min(g, b)) + r + g + b - max(r, max(g, b)) -
                                 min(r, min(g, b)) + 1)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
