#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 2)
    cout << 1 << endl << 1 << " " << 1 << endl;
  else if (n == 3)
    cout << 0 << endl << 2 << " " << 1 << " " << 2 << endl;
  else {
    long long p = n * (n + 1);
    p /= 2;
    if (p % 2 == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
    int i = 1;
    if (p % 2 == 0)
      p /= 2;
    else {
      p /= 2;
      p++;
    }
    vector<long long> v;
    long long m = n + 1;
    while (p) {
      if (p < m) {
        v.push_back(p);
        p = 0;
      } else {
        v.push_back(i);
        v.push_back(m - i);
        p -= m;
        i++;
      }
    }
    cout << v.size();
    for (int i = 0; i < v.size(); i++) cout << " " << v[i];
  }
}
