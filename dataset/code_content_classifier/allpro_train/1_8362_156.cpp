#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y;
  cin >> x >> y;
  long long sum = 0;
  long long count = x - 1;
  long long Max = x * (x - 1) / 2;
  while (y-- && sum < Max) {
    sum += count;
    count--;
    if (sum == Max) {
      break;
    }
    sum += count;
    count--;
  }
  cout << sum << endl;
  return 0;
}
