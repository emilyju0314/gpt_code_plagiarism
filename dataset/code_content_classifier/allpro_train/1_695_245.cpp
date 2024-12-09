#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
  if (abs(a) > abs(b))
    return true;
  else
    return false;
}
bool isinc(int ar[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (ar[i] > ar[i + 1]) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char ch = (char)((i % 4) + 97);
    cout << ch;
  }
  return 0;
}
