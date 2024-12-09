#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, i, temp;
  cin >> n >> k;
  if (n == 1) {
    if (k == 0) {
      cout << 1 << "\n";
      return 0;
    } else {
      cout << "-1\n";
      return 0;
    }
  }
  if (k < (n / 2) || k == 0) {
    cout << "-1\n";
    return 0;
  }
  temp = k - ((n - 2) / 2);
  cout << temp << " " << temp * 2 << " ";
  int index = 1;
  for (i = 2; i < n; i++) {
    if (index == temp || index == temp * 2) {
      i--;
      index++;
      continue;
    }
    cout << index << " ";
    index++;
  }
  cout << "\n";
}
