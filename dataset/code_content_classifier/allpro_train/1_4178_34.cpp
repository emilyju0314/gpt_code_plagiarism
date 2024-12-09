#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, d, i, j, k;
    cin >> a >> b >> c >> d;
    if ((a + b) % 2 == 0) {
      if (c >= 1 && d >= 1) {
        cout << "Tidak Tidak Ya Ya"
             << "\n";
      } else if (c >= 1) {
        if (a >= 1)
          cout << "Tidak Tidak Ya Ya"
               << "\n";
        else
          cout << "Tidak Tidak Ya Tidak"
               << "\n";
      } else if (d >= 1) {
        if (b >= 1)
          cout << "Tidak Tidak Ya Ya"
               << "\n";
        else
          cout << "Tidak Tidak Tidak Ya"
               << "\n";
      } else {
        if (a >= 1 && b >= 1)
          cout << "Tidak Tidak Ya Ya"
               << "\n";
        else if (a >= 1)
          cout << "Tidak Tidak Tidak Ya"
               << "\n";
        else
          cout << "Tidak Tidak Ya Tidak"
               << "\n";
      }
    } else {
      if (a >= 1 && b >= 1) {
        cout << "Ya Ya Tidak Tidak"
             << "\n";
      } else if (a >= 1) {
        if (c >= 1)
          cout << "Ya Ya Tidak Tidak"
               << "\n";
        else
          cout << "Ya Tidak Tidak Tidak"
               << "\n";
      } else if (b >= 1) {
        if (d >= 1)
          cout << "Ya Ya Tidak Tidak"
               << "\n";
        else
          cout << "Tidak Ya Tidak Tidak"
               << "\n";
      } else {
        cout << "Tidak Tidak Tidak Tidak"
             << "\n";
      }
    }
  }
}
