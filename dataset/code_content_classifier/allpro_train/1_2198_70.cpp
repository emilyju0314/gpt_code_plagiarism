#include <bits/stdc++.h>
using namespace std;
int n;
int l, r, mid;
long long t;
string a;
bool check(int cnt) {
  if (cnt == -1) return 0;
  int temp = cnt;
  int ends = 0, las;
  long long ans = 0;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == 'H') {
      cnt--;
      ends = i;
    }
    if (a[i] == 'S') {
      cnt++;
      if (cnt == 0) ends = i;
    }
  }
  if (cnt < 0) return 0;
  cnt = temp;
  for (int i = 0; i <= ends; i++) {
    ans++;
    if (a[i] == 'H') {
      cnt--;
      if (cnt == -1) {
        if ((ends - i) * 2 + ans <= t) return 1;
        las = i;
      }
    }
    if (a[i] == 'S') {
      cnt++;
      if (cnt == 0) ans = ans + (i - las) * 2;
    }
  }
  return ans <= t;
}
int main() {
  cin >> n >> t;
  cin >> a;
  l = 0, r = n + 3;
  while (l + 1 < r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (r > n) {
    cout << "-1";
    return 0;
  }
  while (check(r - 1)) r--;
  cout << r;
  return 0;
}
