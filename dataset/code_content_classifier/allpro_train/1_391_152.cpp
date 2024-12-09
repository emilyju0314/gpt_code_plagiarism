#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = ({
    int x;
    scanf("%d", &x);
    x;
  }),
      k = ({
        int x;
        scanf("%d", &x);
        x;
      }),
      ans = 0;
  for (int i = (0); i < (n); i += (1)) {
    int x = ({
      int x;
      scanf("%d", &x);
      x;
    });
    ans += (x + k - 1) / k;
  }
  cout << (ans + 1) / 2;
}
