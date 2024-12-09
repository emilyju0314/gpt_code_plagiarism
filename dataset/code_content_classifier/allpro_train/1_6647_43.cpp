#include <iostream>
using namespace std;

int main () {
  int x, y;
  cin >> x >> y;
  cout << (0 == x % y ? -1 : x) << endl;
  return 0;
}