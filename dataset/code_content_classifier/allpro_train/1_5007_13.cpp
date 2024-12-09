#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while(cin >> n >> m, n | m) {
    vector<int> sum = {0};
    for(int i = 0; i < n; ++i) {
      int K;
      cin >> K;
      sum.push_back((sum.back() + (K % m)) % m);
    }
    int answer = 0;
    set<int> used = {m};
    for(auto j: sum) {
      answer = max(answer, (j - *used.upper_bound(j) + m) % m);
      used.insert(j);
      used.insert(j + m);
    }
    cout << answer << "\n";
  }
}