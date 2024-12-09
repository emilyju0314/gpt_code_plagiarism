#include <bits/stdc++.h>
using namespace std;
const int maxn = 1024;
int num[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> num[i];
  for (int i = 1; i <= n; i++) {
    if (!(num[i] & 1))
      cout << num[i] - 1 << ' ';
    else
      cout << num[i] << ' ';
  }
  cout << endl;
}
