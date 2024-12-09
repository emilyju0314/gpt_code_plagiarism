#include <bits/stdc++.h>
using namespace std;
long long a, b, x, y;
int main() {
  cin >> a >> b >> x >> y;
  if (x + y < a + b) {
    cout << "Vasiliy" << endl;
  } else if (x >= a and y >= b) {
    cout << "Polycarp" << endl;
  } else if (max(x, y) >= a + b) {
    cout << "Polycarp" << endl;
  } else
    cout << "Vasiliy" << endl;
}
