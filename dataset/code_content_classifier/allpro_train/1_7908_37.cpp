#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int arr[t];
  int x;
  cin >> x;
  arr[0] = x;
  int min = x;
  int index_min = 0;
  for (int u = 1; u < t; u++) {
    cin >> x;
    if (min > x) {
      min = x;
      index_min = u;
    }
    arr[u] = x;
  }
  for (int s = 0; s < t; s++) {
    if (arr[s] == min && index_min != s) {
      cout << "Still Rozdil" << endl;
      goto ss;
    }
  }
  cout << index_min + 1 << endl;
ss:;
}
