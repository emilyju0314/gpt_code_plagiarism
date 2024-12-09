#include <bits/stdc++.h>
using namespace std;
int arr[200000];
int main() {
  int k;
  map<int, int> mapi;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    if (mapi[k] == 0) {
      mapi[k]++;
    } else {
      mapi[k]++;
    }
  }
  map<int, int>::iterator it;
  int cnt = 0;
  for (it = mapi.begin(); it != mapi.end(); it++) {
    int t1 = it->first;
    int t2 = it->second;
    if (t1 != cnt + 1) {
      if (t2 >= t1 - cnt) {
        cnt = t1;
      } else {
        cnt += t2;
      }
    } else {
      cnt++;
    }
  }
  cout << cnt + 1 << endl;
  return 0;
}
