#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long int n, a, b;
  while (t--) {
    cin >> n >> a >> b;
    cout << (n - min(a, b) + 1) << endl;
  }
}
