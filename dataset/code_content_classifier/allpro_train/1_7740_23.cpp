#include <bits/stdc++.h>
using namespace std;
int counter = 0;
int main() {
  int n, diff;
  cin >> n >> diff;
  int heights[n];
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (abs(heights[i] - heights[j]) <= diff ||
          abs(heights[j] - heights[i]) <= diff) {
        counter += 2;
      }
    }
  }
  cout << counter;
}
