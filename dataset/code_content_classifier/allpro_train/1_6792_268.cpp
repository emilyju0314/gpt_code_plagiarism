#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  int arr[n - 1];
  for (int i = 0; i < n - 1; i++) cin >> arr[i];
  int i = 1;
  while (true) {
    if (i == t) {
      cout << "yes";
      break;
    } else if (i > t) {
      cout << "no";
      break;
    } else {
      i = i + arr[i - 1];
    }
  }
}
