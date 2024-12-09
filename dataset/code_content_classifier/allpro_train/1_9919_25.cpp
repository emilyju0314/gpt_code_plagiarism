#include <bits/stdc++.h>
using namespace std;
int x[1005];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (i != x[i]) break;
    if (i == n) {
      cout << "0 0";
      return 0;
    }
  }
  int indexs = 0, indexe = 0;
  for (int i = 1; i <= n; ++i) {
    if (x[i] != i) {
      indexs = i;
      break;
    }
  }
  for (int i = n; i >= 0; --i) {
    if (x[i] != i) {
      indexe = i;
      break;
    }
  }
  int cop1 = indexs, cop2 = indexe;
  while (indexs < indexe) {
    swap(x[indexs], x[indexe]);
    indexs++;
    indexe--;
  }
  for (int i = 1; i <= n; ++i) {
    if (i != x[i]) break;
    if (i == n) {
      cout << cop1 << " " << cop2;
      return 0;
    }
  }
  cout << "0 0";
  return 0;
}
