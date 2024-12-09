#include <bits/stdc++.h>
using namespace std;
int consis[201][201];
bool appear[201];
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  memset(consis, 0, sizeof(consis));
  memset(appear, false, sizeof(appear));
  for (int i = 0; i < (n * (n - 1)) / 2; i++) {
    int m;
    cin >> m;
    int temp[200];
    for (int j = 0; j < m; j++) {
      cin >> temp[j];
      appear[temp[j]] = true;
    }
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        if (j != k) consis[temp[j]][temp[k]] += 1;
      }
    }
  }
  if (n == 2) {
    int index = 1;
    while (appear[index] == false) index++;
    cout << 1 << " " << index;
    cout << endl;
    index++;
    vector<int> ans;
    for (; index <= 200; index++) {
      if (appear[index]) ans.push_back(index);
    }
    cout << ans.size() << " ";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  } else {
    int count = 0;
    for (int i = 1; i <= 200; i++) {
      if (appear[i]) count++;
    }
    while (count > 0) {
      int index = 1;
      vector<int> ans = vector<int>();
      while (appear[index] == false) index++;
      appear[index] = false;
      ans.push_back(index);
      count--;
      for (int i = 1; i <= 200; i++) {
        if (consis[index][i] == n - 1) {
          ans.push_back(i);
          appear[i] = false;
          count--;
        }
      }
      cout << ans.size() << " ";
      for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
      cout << endl;
    }
  }
  return 0;
}
