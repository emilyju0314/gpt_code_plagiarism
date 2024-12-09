#include <iostream>
using namespace std;

int main() {
  int X, t;
  cin >> X >> t;
  cout << max(X - t, 0) << endl;
}
