#include <bits/stdc++.h>
using namespace std;
int main() {
  int count, n, tmp;
  cin >> count;
  while (count-- > 0) {
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      a.push_back(tmp);
    }
    int maxPile = *max_element(a.begin(), a.end());
    int sumPile = accumulate(a.begin(), a.end(), 0);
    if (maxPile * 2 > sumPile || sumPile & 1) {
      cout << "T" << endl;
    } else {
      cout << "HL" << endl;
    }
  }
  return 0;
}
