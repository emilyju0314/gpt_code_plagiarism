#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  long long int n;
  while (cin >> n) {
    long long int t;
    if (n < 11)
      cout << "1" << endl;
    else {
      t = n / 2 + n / 3 + n / 5 + n / 7 - n / 6 - n / 10 - n / 14 - n / 15 -
          n / 21 - n / 35 + n / 30 + n / 42 + n / 70 + n / 105 - n / 210;
      cout << n - t << endl;
    }
  }
  return 0;
}
