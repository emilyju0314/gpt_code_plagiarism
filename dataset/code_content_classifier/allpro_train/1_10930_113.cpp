#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
      A[i] = s[i] - 48;
    }
    vector<int> Presum(n + 1);
    Presum[0] = 0;
    for (int i = 1; i <= n; i++) Presum[i] = Presum[i - 1] + A[i - 1];
    for (int i = 0; i <= n; i++) Presum[i] -= i;
    unordered_map<int, int> Count;
    for (int i = 0; i <= n; i++) {
      if (Count.find(Presum[i]) == Count.end())
        Count[Presum[i]] = 1;
      else
        Count[Presum[i]] += 1;
    }
    long long int ans = 0;
    for (auto pair : Count) {
      long long int occ = pair.second;
      long long int temp = (occ * (occ - 1)) / 2;
      ans += temp;
    }
    cout << ans << endl;
  }
  return 0;
}
