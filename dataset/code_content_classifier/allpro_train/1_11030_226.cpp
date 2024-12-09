#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  string s;
  cin >> t;
  cin >> s;
  int num[10] = {0};
  int arr[10] = {0};
  int temp = t;
  while (temp > 0) {
    if (temp % 10 == 9) {
      num[6] += 1;
    } else if (temp % 10 == 5) {
      num[2] += 1;
    } else {
      num[temp % 10] += 1;
    }
    temp /= 10;
  }
  vector<int> dig;
  for (int i = 0; i < 10; i++) {
    if (num[i] != 0) {
      dig.push_back(i);
    }
  }
  for (int i = 0; i < s.size(); i++) {
    int x = s[i] - '0';
    if (x == 2 || x == 5)
      arr[2] += 1;
    else if (x == 6 || x == 9)
      arr[6] += 1;
    else
      arr[x] += 1;
  }
  int ans = 0;
  bool cont = true;
  while (cont) {
    for (int i : dig) {
      int req = num[i];
      int hav = arr[i];
      if (req > hav) {
        cont = false;
        break;
      } else {
        arr[i] -= req;
      }
    }
    if (cont) ans += 1;
  }
  cout << ans << endl;
  return 0;
}
