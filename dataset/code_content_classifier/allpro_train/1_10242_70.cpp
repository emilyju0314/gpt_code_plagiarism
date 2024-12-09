#include <bits/stdc++.h>
using namespace std;
int A, X, Y;
double A2;
int main() {
  int nr;
  cin >> A >> X >> Y;
  A2 = (double)A;
  A2 /= 2.0;
  if (Y > 0 && Y < A) {
    if (X > -A2 && X < A2) {
      cout << "1"
           << "\n";
      return 0;
    } else {
      cout << "-1"
           << "\n";
      return 0;
    }
  } else {
    if (Y == 0 || Y % A == 0) {
      cout << "-1"
           << "\n";
      return 0;
    } else {
      nr = Y / A;
      if (nr % 2 == 0) {
        if (X > -A && X < A) {
          nr /= 2;
          nr *= 3;
          if (X < 0)
            cout << nr << "\n";
          else {
            if (X == 0)
              cout << "-1"
                   << "\n";
            else
              cout << (nr + 1) << "\n";
          }
          return 0;
        } else {
          cout << "-1"
               << "\n";
          return 0;
        }
      } else {
        if (X > -A2 && X < A2) {
          nr++;
          nr /= 2;
          nr *= 3;
          nr--;
          cout << nr << "\n";
          return 0;
        } else {
          cout << "-1"
               << "\n";
          return 0;
        }
      }
    }
  }
  return 0;
}
