#include <bits/stdc++.h>
using namespace std;
int a, b, tmp;
int main() {
  cin >> a >> b;
  tmp = 0;
  while (b != 0) {
    tmp = (tmp * 10) + (b % 10);
    b = b / 10;
  }
  b = tmp;
  a += b;
  cout << a << endl;
}
