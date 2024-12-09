#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int points = 0, counter = 1;
  cin >> n;
  int arra[n], arrb[n];
  for (int i = 0; i < n; i++) {
    cin >> arra[i];
    cin >> arrb[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arrb[j] > arrb[i]) {
        swap(arrb[j], arrb[i]);
        swap(arra[j], arra[i]);
      } else if (arrb[j] == arrb[i]) {
        if (arra[j] > arra[i]) {
          swap(arrb[j], arrb[i]);
          swap(arra[j], arra[i]);
        }
      } else {
        continue;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (counter > 0) {
      points += arra[i];
      counter += arrb[i] - 1;
    } else {
      break;
    }
  }
  cout << points;
  return 0;
}
