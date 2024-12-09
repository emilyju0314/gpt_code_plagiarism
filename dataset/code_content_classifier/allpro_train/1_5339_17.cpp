#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  cout << (n / 10) * 10 + (n % 10 < 5 ? 0 : 10) << endl;
  return 0;
}
