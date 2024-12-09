#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string st;
    cin >> st;
    int a[26] = {0};
    for (int i = 0; i < st.length(); i++) {
      a[st[i] - 97]++;
    }
    int f = 0, s = 0, d = 0;
    for (int i = 0; i < 26; i++) {
      if (a[i] > 0) {
        s = i;
        break;
      }
    }
    for (int i = 25; i >= 0; i--) {
      if (a[i] > 0) {
        d = i;
        break;
      }
    }
    for (int i = s; i <= d; i++) {
      if (a[i] != 1) {
        f = 1;
        break;
      }
    }
    if (f == 1) {
      cout << "NO" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
}
