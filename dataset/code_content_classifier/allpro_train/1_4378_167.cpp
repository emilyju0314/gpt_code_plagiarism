#include <bits/stdc++.h>
using namespace std;
const string days[7] = {"mon", "tus", "wed", "thu", "fri", "sut", "sun"};
bool isLeap(int n) {
  if (n % 4 == 0)
    if (n % 100 == 0)
      if (n % 400 == 0)
        return 1;
      else
        return 0;
    else
      return 1;
  return 0;
}
int main() {
  int n, idx = 0;
  cin >> n;
  for (int i = n + 1;; i++) {
    if (i % 4 == 0) {
      if (i % 100 == 0) {
        if (i % 400 == 0)
          if (idx == 5)
            idx = 0;
          else if (idx == 6)
            idx = 1;
          else
            idx += 2;
        else if (idx == 6)
          idx = 0;
        else
          idx++;
      } else if (idx == 5)
        idx = 0;
      else if (idx == 6)
        idx = 1;
      else
        idx += 2;
    } else if (idx == 6)
      idx = 0;
    else
      idx++;
    if (isLeap(n) == isLeap(i) && idx == 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
