#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  while (x--) {
    int R, P, S;
    string t;
    int n;
    cin >> n;
    cin >> R >> P >> S;
    cin >> t;
    int r = 0, s = 0, p = 0;
    for (int i = 0; i < t.length(); i++) {
      if (t[i] == 'R')
        r++;
      else if (t[i] == 'P')
        p++;
      else
        s++;
    }
    string f = "";
    int win = 0;
    for (int i = 0; i < t.length(); i++) {
      if (t[i] == 'R') {
        if (P) {
          P--;
          win++;
          f += 'P';
        } else if (S - p > R - s) {
          S--;
          f += 'S';
        } else {
          R--;
          f += 'R';
        }
        r--;
      }
      if (t[i] == 'P') {
        if (S) {
          S--;
          win++;
          f += 'S';
        } else if (R - s > P - r) {
          R--;
          f += 'R';
        } else {
          P--;
          f += 'P';
        }
        p--;
      }
      if (t[i] == 'S') {
        if (R) {
          R--;
          win++;
          f += 'R';
        } else if (S - p > P - r) {
          S--;
          f += 'S';
        } else {
          P--;
          f += 'P';
        }
        s--;
      }
    }
    int m = t.length() / 2 + t.length() % 2;
    if (win >= m)
      cout << "YES" << endl << f << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
