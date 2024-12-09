#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  unsigned int t;
  cin >> t;
  while (t--) {
    int b, p, f, h, c;
    scanf("%d", &b);
    scanf("%d", &p);
    scanf("%d", &f);
    scanf("%d", &h);
    scanf("%d", &c);
    int prof = 0;
    if (h >= c) {
      if (b >= 2 * p) {
        prof = prof + p * h;
        b = b - 2 * p;
      } else {
        prof = prof + (b / 2) * h;
        b = b - 2 * (b / 2);
      }
      if (b > 1) {
        if (b >= 2 * f) {
          prof = prof + f * c;
          b = b - 2 * f;
        } else {
          prof = prof + (b / 2) * c;
          b = b - 2 * (b / 2);
        }
      }
    } else {
      if (b >= 2 * f) {
        prof = prof + f * c;
        b = b - 2 * f;
      } else {
        prof = prof + (b / 2) * c;
        b = b - 2 * (b / 2);
      }
      if (b > 1) {
        if (b >= 2 * p) {
          prof = prof + p * h;
          b = b - 2 * f;
        } else {
          prof = prof + (b / 2) * h;
          b = b - 2 * (b / 2);
        }
      }
    }
    cout << prof << endl;
  }
}
