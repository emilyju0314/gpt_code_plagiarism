#include <bits/stdc++.h>
using namespace std;
void print(int t[], int n) {
  for (int i = 0; i < n; i++) cout << t[i] << " ";
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  int a[26] = {0};
  for (int i = 0; i < n; i++) {
    string p;
    cin >> p;
    a[p[0] - 'a']++;
  }
  int ret = 0;
  for (int i = 0; i < 26; i++)
    if (a[i] > 1) {
      if (a[i] % 2 == 0) {
        ret += (a[i] / 2) * (a[i] / 2 - 1);
      } else {
        ret += (a[i] / 2) * (a[i] / 2 - 1) / 2;
        ret += (a[i] / 2 + 1) * (a[i] / 2 + 1 - 1) / 2;
      }
    }
  cout << ret << endl;
  return 0;
}
