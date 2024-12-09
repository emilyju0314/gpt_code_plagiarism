#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100500;
int arr[100];
int f1(int a, int b) { return a ^ b; }
int f2(int a, int b) { return a | b; }
int f3(int a, int b) { return a & b; }
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int a1 = f1(a, b);
  int b1 = f2(c, d);
  int c1 = f3(b, c);
  int d1 = f1(a, d);
  int a2 = f3(a1, b1);
  int b2 = f2(c1, d1);
  int res = f1(a2, b2);
  cout << res;
  return 0;
}
