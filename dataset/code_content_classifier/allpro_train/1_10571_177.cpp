#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << 2 * n / k + (!!((2 * n) % k)) + 5 * n / k + (!!((5 * n) % k)) +
              (8 * n) / k + (!!((8 * n) % k))
       << endl;
}
