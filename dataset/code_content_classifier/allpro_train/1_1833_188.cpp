#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long spend = 0;
    while (n >= 10) {
      int rem = n % 10;
      int cashback = n / 10;
      spend += (cashback * 10);
      n = cashback + rem;
    }
    spend += n;
    cout << spend << endl;
  }
  return 0;
}
