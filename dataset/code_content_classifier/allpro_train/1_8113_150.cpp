#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  map<long long, long long> toPresent;
  for (int i = 0; i < n; i++) {
    long long val, profit;
    cin >> val >> profit;
    if (toPresent.count(val) == 0)
      toPresent[val] = profit;
    else
      toPresent[val] = max(toPresent[val], profit);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    long long val, profit;
    cin >> val >> profit;
    if (toPresent.count(val) == 0)
      toPresent[val] = profit;
    else
      toPresent[val] = max(toPresent[val], profit);
  }
  long long maxProfit = 0;
  for (map<long long, long long>::iterator it = toPresent.begin();
       it != toPresent.end(); it++) {
    maxProfit += it->second;
  }
  cout << maxProfit << "\n";
}
