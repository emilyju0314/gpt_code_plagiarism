#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << (a < 11 || a > 21 ? 0 : a == 20 ? 15 : 4) << endl;
}