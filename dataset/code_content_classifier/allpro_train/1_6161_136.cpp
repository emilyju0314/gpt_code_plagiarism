#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int last = 0;
    long long int y = n;
    while (y >= 2) {
      long long int ans = 0;
      long long int temp = 0;
      while (temp <= y) {
        ans++;
        temp = ((3 * (ans) * (ans)) + (ans)) / 2;
      }
      ans = ans - 1;
      temp = (3 * (ans) * (ans) + (ans)) / 2;
      y = y - temp;
      last++;
    }
    cout << last << endl;
  }
  return 0;
}
