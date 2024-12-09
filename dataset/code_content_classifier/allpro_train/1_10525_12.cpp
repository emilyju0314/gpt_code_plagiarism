#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp, maxi = 0, maxinumber, i;
  map<int, int> counter;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> temp;
    if (!counter[temp]) {
      counter[temp] = 1;
    } else {
      counter[temp]++;
    }
    if (counter[temp] > maxi) {
      maxi = counter[temp];
      maxinumber = temp;
    }
  }
  cout << maxinumber << endl;
  return 0;
}
