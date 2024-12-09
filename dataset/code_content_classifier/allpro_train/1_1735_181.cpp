#include <bits/stdc++.h>
using namespace std;
int func2(int a, int b);
void func1(int l, int sum, int p, int y);
int n, *c;
bool ans = 0;
int main() {
  string s;
  cin >> n >> s;
  c = new int[n];
  for (int i = 0; i < n; i++) {
    c[i] = s[i] - '0';
  }
  func1(n, 0, 0, 1);
  if (ans == 1) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
void func1(int l, int sum, int p, int y) {
  for (int i = 1; i <= l - (1 - p) * 1; i++) {
    int t = func2(n - l, n - l + i);
    if (p * t < sum)
      continue;
    else if (p * t > sum)
      return;
    func1(l - i, t, p >= 0, y + 1);
  }
  if (l == 0) {
    ans = 1;
  }
}
int func2(int a, int b) {
  int sum = 0;
  for (int i = a; i < b; i++) sum += c[i];
  return sum;
}
