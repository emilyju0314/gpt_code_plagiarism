#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 50;
const int INF = 1 << 30;
int flag = 1, pre = 0;
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int tmp = 0;
    scanf("%d", &tmp);
    if (pre && !tmp) flag = 0;
    if (pre) {
      tmp--;
      pre = 0;
    }
    if (tmp % 2) {
      pre = 1;
    }
  }
  if (flag && !pre)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
