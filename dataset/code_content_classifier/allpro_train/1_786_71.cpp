#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const int maxn = 1000000;
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 0;
  int r = n - 1;
  string res = "";
  int ans = -1;
  while (l <= r) {
    if (res.size() == 0) {
      if (a[l] < a[r]) {
        res += 'L';
        ans = a[l];
        l++;
      } else if (a[l] > a[r]) {
        res += 'R';
        ans = a[r];
        r--;
      } else {
        int nbl = 0;
        int nbr = 0;
        string sl = "";
        string sr = "";
        for (int i = l + 1; i <= r; i++) {
          if (a[i] > a[i - 1]) {
            nbl++;
            sl += 'L';
          } else {
            break;
          }
        }
        for (int i = r - 1; i >= l; i--) {
          if (a[i] > a[i + 1]) {
            nbr++;
            sr += 'R';
          } else {
            break;
          }
        }
        if (nbl > nbr) {
          res += sl + 'L';
        } else {
          res += sr + 'R';
        }
        break;
      }
    } else {
      if ((a[l] <= ans) and (a[r] <= ans)) {
        break;
      } else {
        if ((a[l] > ans) and (a[r] > ans)) {
          if (a[l] < a[r]) {
            res += 'L';
            ans = a[l];
            l++;
          } else if (a[l] > a[r]) {
            res += 'R';
            ans = a[r];
            r--;
          } else {
            int nbl = 0;
            int nbr = 0;
            string sl = "";
            string sr = "";
            for (int i = l + 1; i <= r; i++) {
              if (a[i] > a[i - 1]) {
                nbl++;
                sl += 'L';
              } else {
                break;
              }
            }
            for (int i = r - 1; i >= l; i--) {
              if (a[i] > a[i + 1]) {
                nbr++;
                sr += 'R';
              } else {
                break;
              }
            }
            if (nbl > nbr) {
              res += sl + 'L';
            } else {
              res += sr + 'R';
            }
            break;
          }
        } else if (a[r] > ans) {
          res += 'R';
          ans = a[r];
          r--;
        } else {
          res += 'L';
          ans = a[l];
          l++;
        }
      }
    }
  }
  cout << res.size() << endl;
  cout << res;
}
