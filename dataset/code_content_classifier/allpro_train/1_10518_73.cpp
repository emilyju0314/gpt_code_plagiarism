#include <bits/stdc++.h>
using namespace std;
string firstname[100010];
string lastname[100010];
int f[100010];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> firstname[i] >> lastname[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
  string cur = "";
  for (int i = 1; i <= n; i++) {
    int index = f[i];
    string small = min(firstname[index], lastname[index]);
    string big = max(firstname[index], lastname[index]);
    if (cur < small) {
      cur = small;
    } else if (cur < big) {
      cur = big;
    } else {
      cout << "NO " << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
