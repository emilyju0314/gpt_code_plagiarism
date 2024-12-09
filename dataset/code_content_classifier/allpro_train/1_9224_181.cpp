#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int startidx = 0, endidx = 0, count = 0, flag = 0, flag2 = 0;
  while (startidx < n) {
    while (s[endidx] == s[startidx]) {
      endidx++;
    }
    if (endidx - startidx >= 3) {
      flag = 1;
    }
    if (endidx - startidx >= 2) {
      flag2 += 1;
    }
    startidx = endidx;
    count++;
  }
  if (flag) {
    count += 2;
  } else if (flag2 >= 2) {
    count += 2;
  } else if (flag2 >= 1) {
    count++;
  }
  cout << count << endl;
}
