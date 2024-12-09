#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> a) {
  int sum = 0;
  for (int x : a) {
    sum += x;
    if (sum == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, j;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    for (j = 0; j < 2; j++) {
      if (check(a)) {
        cout << "YES\n";
        for (int x : a) {
          cout << x << " ";
        }
        cout << "\n";
        break;
      }
      reverse(a.begin(), a.end());
    }
    if (j == 2) {
      cout << "NO\n";
    }
  }
  return 0;
}
