#include <bits/stdc++.h>
using namespace std;
int getLis(vector<int>& vec) {
  vector<int> dp(((int)(vec).size()), 1);
  for (int i = 1; i < ((int)(vec).size()); i++) {
    for (int j = 0; j < i; j++) {
      if (vec[j] <= vec[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  return *(max_element((dp).begin(), (dp).end()));
}
int main() {
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> vec;
  multiset<int> st;
  for (int i = 0; i < (n); i++) {
    int u;
    double v;
    cin >> u >> v;
    vec.push_back(u);
  }
  int lis = getLis(vec);
  cout << ((int)(vec).size()) - lis << "\n";
}
