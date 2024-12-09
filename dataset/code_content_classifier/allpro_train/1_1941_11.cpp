#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  while (cin >> n >> m) {
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < (int)(n); i++)
      for (int i = 0; i < (int)(m); i++) {
        int t;
        cin >> t;
        if (t == 11)
          a++;
        else if (t == 0)
          c++;
        else
          b++;
      }
    int a1 = a % n;
    int a2 = a / n;
    int b1 = b % n;
    int b2 = b / n;
    int f = 0;
    int k = 0;
    for (int i = 0; i < (int)(n); i++) {
      for (int j = 0; j < (int)(m); j++) {
        if (a) {
          cout << "11";
          a--;
          f = j;
          k = i;
        } else if (c && k == i - 1 && j <= f) {
          cout << "00";
          c--;
        } else if (b) {
          cout << (i & 1 ? "01" : "10");
          b--;
        } else if (c) {
          cout << "00";
          c--;
        }
        if (j == m - 1)
          cout << endl;
        else
          cout << " ";
      }
    }
  }
  return 0;
}
