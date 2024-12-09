#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5;
const int mod = 1e7 + 7;
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= MAXN; ++i) {
    for (int j = 0; j <= MAXN; ++j) {
      if (i * 4 + j * 7 == n) {
        for (int four = 1; four <= i; ++four) {
          cout << "4";
        }
        for (int seven = 1; seven <= j; ++seven) {
          cout << "7";
        }
        return 0;
      }
      if (i * 4 + j * 7 > n) {
        break;
      }
    }
  }
  cout << -1;
  return 0;
}
