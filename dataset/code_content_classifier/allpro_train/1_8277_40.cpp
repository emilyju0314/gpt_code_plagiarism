#include <bits/stdc++.h>
using namespace std;
struct Test {
  int n, e, t;
  vector<pair<int, int>> haters;
  vector<vector<int>> preferences;
  Test(int n, int e) : n(n), e(e), haters(e), preferences(n), t(0) {
    for (auto& item : haters) {
      cin >> item.first >> item.second;
      --item.first;
      --item.second;
    }
    for (auto& item : preferences) {
      int size;
      cin >> size;
      item.resize(size);
      for (auto& i : item) {
        cin >> i;
        t = max(t, i);
        ;
      }
    }
  }
  vector<int> group;
  vector<int> trainer;
  void run() {
    group.resize(t + 1);
    trainer.resize(n + 1);
    srand(time(0));
    while (true) {
      for (int i = 1; i <= t; ++i) {
        group[i] = rand() % 2;
      }
      for (int i = 0; i < n; ++i) {
        trainer[i] = preferences[i][rand() % preferences[i].size()];
      }
      int level = 0;
      for (auto& item : haters) {
        level += group[trainer[item.first]] != group[trainer[item.second]];
      }
      if (2 * level >= e) {
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << trainer[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= t; ++i) {
      cout << group[i] + 1 << ' ';
    }
    cout << '\n';
  }
};
int main() {
  int n, e;
  cin >> n >> e;
  Test a(n, e);
  a.run();
  return 0;
}
