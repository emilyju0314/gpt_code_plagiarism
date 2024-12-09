#include <bits/stdc++.h>
using namespace std;
map<string, int> mm1, mm2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mm1[s]++;
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mm2[s]++;
  }
  int ans = 0;
  ans = ans + max(max(abs(mm1["S"] - mm2["S"]), abs(mm1["M"] - mm2["M"])),
                  abs(mm1["L"] - mm2["L"]));
  ans = ans + max(abs(mm1["XXL"] - mm2["XXL"]), abs(mm1["XXS"] - mm2["XXS"]));
  ans =
      ans + max(abs(mm1["XXXL"] - mm2["XXXL"]), abs(mm1["XXXS"] - mm2["XXXS"]));
  ans = ans + max(abs(mm1["XL"] - mm2["XL"]), abs(mm1["XS"] - mm2["XS"]));
  cout << ans;
  return 0;
}
