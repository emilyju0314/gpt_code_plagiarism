#include <bits/stdc++.h>
using namespace std;
map<int, int> Map;
set<int> Set, Sec;
int ans;
int main() {
  int N, K;
  int num;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    scanf("%d", &num);
    Set.insert(num);
    if (Map.find(num) == Map.end()) {
      Map.insert(make_pair(num, 1));
    } else {
      Map[num] = Map[num] + 1;
    }
  }
  set<int>::iterator iter = Set.begin();
  set<int>::iterator lst = iter;
  iter++;
  for (; iter != Set.end(); iter++) {
    if (*lst + K >= *iter) {
      Sec.insert(*lst);
    }
    lst++;
  }
  for (iter = Sec.begin(); iter != Sec.end(); iter++) {
    ans += Map[*iter];
  }
  cout << N - ans << endl;
  return 0;
}
