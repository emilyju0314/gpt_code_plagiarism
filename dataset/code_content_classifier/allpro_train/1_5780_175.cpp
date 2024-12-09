#include <iostream>
#include <cmath>
#include <string>
using namespace std;

signed main() {
  string a, b; cin >> a >> b;
  int n = stoi(a+b);
  int m = (int)sqrt(n);

  cout << (n == m*m ? "Yes" : "No") << endl;
}
