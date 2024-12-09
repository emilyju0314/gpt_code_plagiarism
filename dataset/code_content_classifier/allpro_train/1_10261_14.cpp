#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int s, m, l, xl, xxl, k;
int arr[5];
map<string, int> mp;
string sz[] = {"S", "M", "L", "XL", "XXL"};
string size;
int main() {
  for (int i = 0; i < 5; ++i) cin >> arr[i];
  mp["S"] = 0;
  mp["M"] = 1;
  mp["L"] = 2;
  mp["XL"] = 3;
  mp["XXL"] = 4;
  cin >> k;
  while (k--) {
    cin >> size;
    if (arr[mp[size]] > 0) {
      cout << size << endl;
      --arr[mp[size]];
    } else {
      int r = mp[size] + 1;
      int l = mp[size] - 1;
      bool notFound = true;
      while (notFound) {
        if (r < 5 && arr[r] > 0) {
          --arr[r];
          notFound = false;
          cout << sz[r] << endl;
        } else if (l > -1 && arr[l] > 0) {
          --arr[l];
          notFound = false;
          cout << sz[l] << endl;
        }
        ++r, --l;
      }
    }
  }
  return 0;
}
