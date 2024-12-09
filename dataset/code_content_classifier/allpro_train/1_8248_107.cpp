#include <bits/stdc++.h>
using namespace std;
int main() {
  int m;
  cin >> m;
  int b[m], l[m];
  int mb[m];
  for (int i = 1; i <= m; i++) {
    cin >> b[i] >> l[i];
    if (b[i] == 1) {
      mb[i] = 1;
    } else if ((b[i] - 2) % l[i] == 0) {
      mb[i] = ((b[i] - 2) / l[i]) + 1;
    } else if ((b[i] - 2) % l[i] > 0) {
      mb[i] = ((b[i] - 2) / l[i]) + 2;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << mb[i] << endl;
  }
}
