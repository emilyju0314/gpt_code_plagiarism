#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int> > availability(n, vector<int>(5, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> availability[i][j];
      }
    }
    vector<string> count = {"01", "02", "03", "04", "12",
                            "13", "14", "23", "24", "34"};
    string answer = "NO";
    for (auto element : count) {
      int day1 = element[0] - '0', day2 = element[1] - '0';
      unordered_set<int> unique1, unique2;
      for (int i = 0; i < n; i++) {
        if (availability[i][day1] == 1) {
          unique1.insert(i);
        }
        if (availability[i][day2] == 1) {
          unique2.insert(i);
        }
      }
      if (unique1.size() == 0 || unique2.size() == 0) {
        continue;
      }
      if (unique1.size() < n / 2) {
        continue;
      }
      if (unique2.size() < n / 2) {
        continue;
      }
      unordered_set<int> unique;
      for (auto element : unique1) {
        unique.insert(element);
      }
      for (auto element : unique2) {
        unique.insert(element);
      }
      if (unique.size() < n) {
        continue;
      }
      answer = "YES";
      break;
    }
    cout << answer << endl;
  }
  return 0;
}
