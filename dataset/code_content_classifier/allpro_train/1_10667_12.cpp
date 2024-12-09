#include <bits/stdc++.h>
using namespace std;
void printArray(int a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
void printVector(vector<int> v) {
  for (auto x : v) cout << x << " ";
  cout << "\n";
}
string reversed(string s) {
  string t = "";
  for (int i = s.length() - 1; i >= 0; i--) t += s[i];
  return t;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  for (int i1 = 0; i1 < t; i1++) {
    int n, ans = 1;
    cin >> n;
    std::vector<int> v[200], count[200];
    for (int i = 0; i < 200; i++) {
      count[i].push_back(0);
    }
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      v[a - 1].push_back(i);
      if (i == 0)
        count[a - 1][0] = 1;
      else {
        for (int j = 0; j < 200; j++) {
          if (j == a - 1)
            count[j].push_back(count[j][i - 1] + 1);
          else
            count[j].push_back(count[j][i - 1]);
        }
      }
    }
    for (int i = 0; i < 200; i++) {
      for (int j = 0; j < v[i].size() / 2; j++) {
        for (int k = 0; k < 200; k++) {
          ans = max(ans, 2 * j + 2 + count[k][v[i][v[i].size() - 1 - j] - 1] -
                             count[k][v[i][j]]);
        }
      }
    }
    cout << ans << "\n";
  }
}
