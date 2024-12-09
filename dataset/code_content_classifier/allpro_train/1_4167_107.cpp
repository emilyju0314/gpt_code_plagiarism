#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q;
  cin >> q;
  for (long long z = 0; z < q; z++) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string first;
    string second;
    string third;
    int t1 = 0, t2 = 1, t3 = 2;
    for (int i = 0; i < k; i++) {
      if (t1 == 0) {
        first.push_back('R');
      } else if (t1 == 1) {
        first.push_back('G');
      } else {
        first.push_back('B');
      }
      t1++;
      t1 %= 3;
      if (t2 == 0) {
        second.push_back('R');
      } else if (t2 == 1) {
        second.push_back('G');
      } else {
        second.push_back('B');
      }
      t2++;
      t2 %= 3;
      if (t3 == 0) {
        third.push_back('R');
      } else if (t3 == 1) {
        third.push_back('G');
      } else {
        third.push_back('B');
      }
      t3++;
      t3 %= 3;
    }
    int mmin = INT_MAX;
    t1 = 0, t2 = 0, t3 = 0;
    for (size_t i = 0; i <= s.length() - k; i++) {
      if (!i) {
        for (int j = 0; j < k; j++) {
          if (s[i + j] != first[j]) {
            t1++;
          }
          if (s[i + j] != second[j]) {
            t2++;
          }
          if (s[i + j] != third[j]) {
            t3++;
          }
        }
        if (t1 < mmin) {
          mmin = t1;
        }
        if (t2 < mmin) {
          mmin = t2;
        }
        if (t3 < mmin) {
          mmin = t3;
        }
        continue;
      }
      int a1 = t1;
      int a2 = t2;
      int a3 = t3;
      if (s[i - 1] == 'B') {
        t1 = a3;
      } else {
        t1 = a3 - 1;
      }
      if (s[i - 1] == 'R') {
        t2 = a1;
      } else {
        t2 = a1 - 1;
      }
      if (s[i - 1] == 'G') {
        t3 = a2;
      } else {
        t3 = a2 - 1;
      }
      if (s[i + k - 1] == second[k - 1]) {
        t1++;
        t3++;
      } else if (s[i + k - 1] == third[k - 1]) {
        t1++;
        t2++;
      } else {
        t2++;
        t3++;
      }
      if (t1 < mmin) {
        mmin = t1;
      }
      if (t2 < mmin) {
        mmin = t2;
      }
      if (t3 < mmin) {
        mmin = t3;
      }
    }
    cout << mmin << endl;
  }
  return 0;
}
