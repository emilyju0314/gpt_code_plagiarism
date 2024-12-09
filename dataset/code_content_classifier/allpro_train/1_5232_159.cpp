#include <bits/stdc++.h>
using namespace std;
int main() {
  string ss;
  int k;
  while (cin >> ss >> k) {
    int len = ss.size();
    for (int i = 0; i < len; ++i) {
      int id = i;
      int mx = ss[i] - '0';
      for (int j = i + 1; j < len && j <= i + k; ++j) {
        if (ss[j] - '0' > mx) {
          mx = ss[j] - '0';
          id = j;
        }
      }
      for (int l = id; l > i; --l) {
        --k;
        swap(ss[l], ss[l - 1]);
      }
    }
    cout << ss << endl;
  }
  return 0;
}
