#include <bits/stdc++.h>
using namespace std;
int main() {
  int l3, l4, l5;
  cin >> l3 >> l4 >> l5;
  long double vol;
  vol =
      (long double)((pow(l3, 3) / (6 * sqrt(2))) + (sqrt(2) * pow(l4, 3) / 6) +
                    ((5 + sqrt(5)) * (pow(l5, 3) / 24)));
  cout << fixed;
  cout << setprecision(12);
  cout << vol << endl;
}
