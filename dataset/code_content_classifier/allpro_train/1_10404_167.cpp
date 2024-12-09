#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, x;
  cin >> n >> k;
  long long sum = 2 * (n + k), num = (long long)sqrt(sum);
  for (long long i = max((long long)0, num - 10); i <= num + 10; i++) {
    if (i * (i + 3) == sum) {
      x = i;
      break;
    }
  }
  cout << n - x;
}
