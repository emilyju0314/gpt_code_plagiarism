#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int index = ceil((float)k / 2);
    vector<vector<int>> v(index, vector<int>(26, 0));
    for (int i = 0; i < index; i++) {
      int num = 0;
      for (int j = i; j < n; j = j + k) {
        v[i][s[j] - 'a']++;
        int curr = k * num + k - i - 1;
        if (j != curr) v[i][s[curr] - 'a']++;
        num++;
      }
    }
    int total = 0;
    for (int i = 0; i < index; i++) {
      int m = 0;
      for (int j = 0; j < 26; j++) {
        if (v[i][j] > m) m = v[i][j];
      }
      total += m;
    }
    cout << n - total << "\n";
  }
  return 0;
}
