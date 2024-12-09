#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ones, nones, qelems;
  int *arr;
  int *l;
  int *r;
  ones = 0;
  nones = 0;
  cin >> n;
  cin >> m;
  arr = new int[n + 1];
  l = new int[m];
  r = new int[m];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> l[i];
    cin >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1)
      ones++;
    else
      nones++;
  }
  for (int i = 0; i < m; i++) {
    qelems = r[i] - l[i] + 1;
    if (qelems % 2 != 0)
      cout << "0" << endl;
    else {
      if (ones >= qelems / 2 && nones >= qelems / 2)
        cout << "1" << endl;
      else
        cout << "0" << endl;
    }
  }
  return 0;
}
