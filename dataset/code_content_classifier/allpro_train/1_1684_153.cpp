#include <bits/stdc++.h>
using namespace std;
int n;
int a[100086];
bool judge(int pos) {
  int i;
  for (i = pos + 1; i <= n; i++) {
    if (a[i] < a[i - 1]) return false;
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int pos = -1;
  for (int i = 2; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    cout << "0" << endl;
    return 0;
  }
  if ((!judge(pos)) || a[n] > a[1]) {
    cout << "-1" << endl;
    return 0;
  } else {
    cout << n - pos + 1 << endl;
  }
}
