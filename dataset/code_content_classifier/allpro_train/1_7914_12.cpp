#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int counts = 0;
  cin >> n;
  vector<int> number;
  int minimum, index = 1;
  int cost[9];
  for (int i = 0; i < 9; i++) {
    cin >> cost[i];
    if (i == 0) {
      minimum = cost[i];
    } else {
      if (minimum >= cost[i]) {
        minimum = cost[i];
        index = i + 1;
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    cost[i] -= minimum;
  }
  int min1 = cost[!(index - 1)];
  if (n < minimum) {
    cout << "-1";
  }
  for (int i = 0; i < 9; i++) {
    if ((i + 1 != index) && (min1 > cost[i])) {
      min1 = cost[i];
    }
  }
  while (n >= minimum) {
    number.push_back(index);
    n -= minimum;
    counts++;
  }
  for (int i = 0; i < counts; i++) {
    if (n < min1) {
      break;
    }
    for (int j = 9; j > 0; j--) {
      if ((j != index) && (n >= cost[j - 1])) {
        if (j > number[i]) {
          number[i] = j;
          n -= cost[j - 1];
          break;
        }
      }
    }
  }
  for (int i = 0; i < counts; i++) {
    cout << number[i];
  }
}
