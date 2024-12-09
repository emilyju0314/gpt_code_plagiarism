#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, k;
  cin >> n >> k;
  if (n < 2 * k + 1)
    printf("%d", -1);
  else {
    cout << n * k << endl;
    int h;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        if ((i + j) % n)
          h = (i + j) % n;
        else
          h = n;
        printf("%d %d\n", i, h);
      }
    }
  }
  return 0;
}
