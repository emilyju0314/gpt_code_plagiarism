#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  string a[101], b[101];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (i = 0; i < n; i++) {
    if (b[i] == "rat") cout << a[i] << endl;
  }
  for (i = 0; i < n; i++) {
    if (b[i] == "woman" || b[i] == "child") cout << a[i] << endl;
  }
  for (i = 0; i < n; i++) {
    if (b[i] == "man") cout << a[i] << endl;
  }
  for (i = 0; i < n; i++) {
    if (b[i] == "captain") cout << a[i] << endl;
  }
}