#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int *arr = new int[n];
    int *sorted = new int[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sorted[i] = arr[i];
    }
    int c = 0;
    sort(sorted, sorted + n);
    for (int i = 0; i < n; i++) {
      if (arr[i] != sorted[i]) {
        c++;
      }
    }
    if (c <= 2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    delete[] arr;
  }
  return 0;
}
