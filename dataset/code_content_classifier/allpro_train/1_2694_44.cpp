#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int cont, num[3], n, k, p;
  cin >> p;
  for (int j = 0; j < p; j++) {
    memset(num, 0, sizeof num);
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> k;
      ++num[k % 3];
    }
    cont = num[0];
    int l = min(num[1], num[2]);
    cont += l;
    num[1] -= l, num[2] -= l;
    cont += (num[1] + num[2]) / 3;
    cout << cont << endl;
  }
  return 0;
}
