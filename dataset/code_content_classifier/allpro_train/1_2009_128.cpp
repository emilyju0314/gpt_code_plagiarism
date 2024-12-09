#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b, tc;
  cin >> tc;
  while (tc--) {
    cin >> a >> b;
    cout << (b - a % b) % b << endl;
  }
}
