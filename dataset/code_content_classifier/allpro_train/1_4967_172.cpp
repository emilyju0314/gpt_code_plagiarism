#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b) {
  if (b > a) swap(a, b);
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
int main(void) {
  int N, a;
  cin >> N;
  int MV = 0;
  int g = 0;
  for (int i = 1; i <= N; i++) {
    cin >> a;
    g = GCD(a, g);
    if (a > MV) MV = a;
  }
  MV = MV / g;
  if ((MV - N) % 2 == 0)
    cout << "Bob";
  else
    cout << "Alice";
  cout << endl;
  return 0;
}
