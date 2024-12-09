#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int a, b, n;
  cin >> a >> b >> n;
  int flag = 1;
  for (int i = 0; i < 10; i++) {
    if (((a * 10) + i) % b == 0) {
      a = a * 10 + i;
      flag = 0;
      break;
    }
  }
  if (flag == 0) {
    cout << a;
    for (int i = 0; i < n - 1; i++) {
      cout << 0;
    }
    cout << endl;
  } else
    cout << -1 << endl;
}
