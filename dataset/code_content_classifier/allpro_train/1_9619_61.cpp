#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, stairways = 1, z;
  vector<int> max_stairs, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> z;
    x.push_back(z);
    if (x[i] == 1 && i != 0) {
      stairways++;
      max_stairs.push_back(x[i - 1]);
    }
  }
  max_stairs.push_back(x.back());
  cout << stairways << endl;
  for (int i = 0; i < max_stairs.size(); i++) {
    cout << max_stairs[i] << " ";
  }
  cout << endl;
  return 0;
}
