#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long result = n / 2;
  if (n & 1) {
    result -= n;
  }
  cout << result << endl;
  return 0;
}
