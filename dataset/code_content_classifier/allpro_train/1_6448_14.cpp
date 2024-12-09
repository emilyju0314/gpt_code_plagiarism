#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n & (n - 1))
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
