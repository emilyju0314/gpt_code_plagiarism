#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<long> vt;
    long i = 0, n, temp, count = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      vt.push_back(temp);
    }
    sort(vt.begin(), vt.end());
    while (i < n) {
      if (vt[i] <= count) {
        count++;
      } else {
        temp = count;
        bool check = true;
        for (int j = i; j < n; j++) {
          if (vt[j] <= temp) {
            check = true;
            temp++;
            i = j;
            break;
          } else {
            check = false;
            temp++;
          }
        }
        if (check == false)
          break;
        else
          count = temp;
      }
      i++;
    }
    cout << count << endl;
  }
  return 0;
}
