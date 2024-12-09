#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[25];
  int n;
  cin >> n;
  n--;
  cin >> a;
  int L = strlen(a);
  char b[25];
  int M = L;
  while (n--) {
    cin >> b;
    for (int i = M - 1; i >= 0; i--) {
      if (b[i] != a[i]) M = i;
    }
  }
  cout << M << endl;
  return 0;
}
