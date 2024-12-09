#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << '?' << ' ';
  fflush(stdout);
  for (int i = 0; i < 100; i++) {
    cout << i << ' ';
    fflush(stdout);
  }
  cout << endl;
  int n;
  cin >> n;
  cout << '?' << ' ';
  fflush(stdout);
  long long a = 0;
  for (int i = 0; i < 100; i++) {
    a += (1 << 7);
    cout << a << ' ';
    fflush(stdout);
  }
  cout << endl;
  int b;
  cin >> b;
  bitset<14> x(n), y(b), z;
  for (int i = 0; i < 14; i++) {
    if (i < 7)
      z[i] = y[i];
    else
      z[i] = x[i];
  }
  cout << "! " << z.to_ulong();
}
