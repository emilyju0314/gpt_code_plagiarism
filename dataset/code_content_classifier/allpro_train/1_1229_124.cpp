#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<long long int> vec;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    vec.push_back(value);
  }
  sort(vec.begin(), vec.end());
  int i = 0, j = 0, count = 0;
  while (i <= vec.size() - 1) {
    if (vec[i] >= (j + 1)) {
      count += 1;
      j += 1;
      i += 1;
    } else {
      i += 1;
    }
  }
  cout << count << endl;
  return 0;
}
