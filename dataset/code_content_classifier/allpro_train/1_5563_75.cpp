#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    int n;
    cin >> n;
    vector<long long> a;
    for (int i = 0; i < n; i++) {
      long long ai;
      cin >> ai;
      a.push_back(ai);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    if (sum % n > 0) {
      cout << "-1" << endl;
      continue;
    }
    long long avg = sum / n;
    vector<int> opi;
    vector<int> opj;
    vector<int> opx;
    for (int i = 1; i < n; i++) {
      if (a[i] % (i + 1) > 0) {
        long long toadd = i + 1 - a[i] % (i + 1);
        opi.push_back(1);
        opj.push_back(i + 1);
        opx.push_back(toadd);
        a[i] += toadd;
      }
      if (a[i] > 0) {
        long long tosubtract = a[i];
        opi.push_back(i + 1);
        opj.push_back(1);
        opx.push_back(a[i] / (i + 1));
        a[i] = 0;
      }
    }
    for (int i = 1; i < n; i++) {
      opi.push_back(1);
      opj.push_back(i + 1);
      opx.push_back(avg);
    }
    if (opi.size() == 0) {
      cout << 0 << endl;
      continue;
    }
    cout << opi.size() << endl;
    for (int i = 0; i < opi.size(); i++) {
      cout << opi[i] << " " << opj[i] << " " << opx[i] << endl;
    }
  }
  return 0;
}
