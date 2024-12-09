#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[102], r, x, n;
  for (int i = 0; i < 102; i++) {
    arr[i] = 0;
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r;
    for (int j = 0; j < r; j++) {
      cin >> x;
      arr[x]++;
    }
  }
  for (int i = 0; i < 102; i++) {
    if (arr[i] == n) {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}
