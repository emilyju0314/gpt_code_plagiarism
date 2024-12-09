#include <bits/stdc++.h>
using namespace std;

int main() {

  int q;
  cin >> q;

  vector<int> A;
  for (int i = 0; i < q; i++) {
    int query, x;
    cin >> query;
    if (query == 0) {
      cin >> x;
      A.push_back(x);
    } else if (query == 1) {
      cin >> x;
      cout << A[x] << endl;
    } else {
      A.pop_back();
    }
  }

  return 0;

}
