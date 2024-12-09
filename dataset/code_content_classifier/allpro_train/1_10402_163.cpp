#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<pair<int, int> > q;
  int qIndex = 0;
  set<int> indexS;
  for (auto i = 0; i < n; i++) {
    cin >> a[i];
    q.push_back({a[i], i});
    indexS.insert(i);
  }
  sort(q.rbegin(), q.rend());
  unordered_set<int> t1;
  bool isT1 = true;
  while (!indexS.empty()) {
    while (!indexS.count(q[qIndex].second)) qIndex++;
    int best = q[qIndex].second;
    vector<int> targets = {best};
    auto it = indexS.find(best);
    int count = 0;
    while (it != indexS.begin()) {
      --it;
      targets.push_back(*it);
      if (++count == k) break;
    }
    it = indexS.find(best);
    count = 0;
    while (it != indexS.end()) {
      if (++it == indexS.end()) break;
      targets.push_back(*it);
      if (++count == k) break;
    }
    for (auto(target) = (targets).begin(); (target) != (targets).end();
         (target)++) {
      indexS.erase(*target);
      if (isT1) t1.insert(*target);
    }
    isT1 = !isT1;
  }
  for (auto i = 0; i < n; i++) {
    cout << (t1.count(i) ? "1" : "2");
  }
  cout << endl;
  return 0;
}
