#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[7] = {0};
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    arr[a - 1]++;
  }
  if (arr[0] != n / 3) {
    cout << "-1";
  } else if (arr[1] + arr[2] != n / 3) {
    cout << "-1";
  } else if (arr[3] + arr[5] != n / 3) {
    cout << "-1";
  } else if (arr[3] > arr[1]) {
    cout << "-1";
  } else {
    n /= 3;
    while (n--) {
      cout << "1 ";
      if (arr[1]) {
        cout << "2 ";
        arr[1]--;
        if (arr[3]) {
          cout << "4";
          arr[3]--;
        } else if (arr[5]) {
          cout << "6";
          arr[5]--;
        }
      } else if (arr[2]) {
        cout << "3 ";
        arr[2]--;
        if (arr[5]) {
          cout << "6";
          arr[5]--;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
