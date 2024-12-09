#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 1;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, long long> us;
    long long mn = INT_MAX;
    for (long long i = 0; i < n; i++) {
      us[s[i]]++;
    }
    for (long long i = 0; i < k; i++) {
      if (!us['A' + i]) {
        cout << "0";
        return 0;
      }
    }
    for (long long i = 0; i < n; i++) {
      mn = min(mn, us[s[i]]);
    }
    cout << mn * k;
  }
  return 0;
}
