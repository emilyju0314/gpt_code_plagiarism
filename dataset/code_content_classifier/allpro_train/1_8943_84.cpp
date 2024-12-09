#include <bits/stdc++.h>
using namespace std;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
void solve(long long int x1, long long int x2, long long int a, long long int b,
           int swapped) {
  long long int dif = x2 - x1;
  if (a <= 0) {
    if (dif > b)
      puts("DRAW");
    else {
      puts("FIRST");
      if (swapped)
        cout << x1 << endl;
      else
        cout << x2 << endl;
    }
  } else {
    dif %= a + b;
    if (dif == 0)
      puts("SECOND");
    else if (dif < a)
      puts("DRAW");
    else if (dif <= b) {
      puts("FIRST");
      if (swapped) {
        cout << x2 - dif << endl;
      } else {
        cout << x1 + dif << endl;
      }
    } else
      puts("DRAW");
  }
}
long long int x1, x2, a, b;
int main() {
  cin >> x1 >> x2 >> a >> b;
  if (x1 < x2) {
    if (b > 0)
      solve(x1, x2, a, b, 0);
    else
      puts("DRAW");
  } else {
    if (a < 0)
      solve(x2, x1, -b, -a, 1);
    else
      puts("DRAW");
  }
  return 0;
}
