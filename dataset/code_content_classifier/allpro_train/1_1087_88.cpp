#include <bits/stdc++.h>
using namespace std;
bool myfunction(int i, int j) { return ((i % 10) > (j % 10)); }
bool myfunction1(int i, int j) { return ((i % 100) > (j % 100)); }
int main() {
  int n, k;
  vector<int> skills;
  while (scanf("%d %d", &n, &k) == 2) {
    int n1 = n, temp, total_skill = 0;
    skills.push_back(-1);
    while (n1--) {
      cin >> temp;
      skills.push_back(temp);
    }
    sort(skills.begin() + 1, skills.end(), myfunction);
    for (int i = 1; i <= n; i++) {
      int t = 10 - (skills[i]) % 10;
      if (t <= k && t != 0) {
        skills[i] += t;
        k -= t;
      }
    }
    for (int i = 1; i <= n; i++) total_skill += skills[i] / 10;
    total_skill += k / 10;
    if (total_skill > n * 10)
      cout << n * 10 << endl;
    else
      cout << total_skill << endl;
    skills.clear();
  }
  return 0;
}
