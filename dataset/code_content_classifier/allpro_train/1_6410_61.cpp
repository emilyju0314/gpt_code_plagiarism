#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r, test;
  cin >> l >> r;
  cout << "YES" << endl;
  for (long long i = l; i <= r; i += 2) {
    cout << i << " " << i + 1 << endl;
  }
}