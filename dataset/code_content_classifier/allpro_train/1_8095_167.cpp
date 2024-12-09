#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, min1, min2, min3, max1, max2, max3;
  while (cin >> n) {
    cin >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;
    int sum = 0;
    sum += min2 + min3 + min1;
    while (n > sum) {
      if (max1 > min1) {
        sum++;
        min1++;
      } else if (max2 > min2) {
        sum++;
        min2++;
      } else if (max3 > min3) {
        sum++;
        min3++;
      }
    }
    cout << min1 << " " << min2 << " " << min3 << endl;
  }
  return 0;
}
