#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> b(n + 1);
  vector<int> k(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    k[a[i]] = b[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << k[i] << " ";
  }
}
