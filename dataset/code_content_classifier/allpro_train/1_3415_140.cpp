#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int max2;
  max2 = a + b + c;
  int max;
  max = a * b * c;
  if (max < max2) max = max2;
  if (max < (a + b) * c) max = (a + b) * c;
  if (max < (b + c) * a) max = (b + c) * a;
  if (max < (a + b + c)) max = a + b + c;
  cout << max;
}
