#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  v.push_back(1);
  while (1) {
    char a, b;
    cin >> a >> b;
    if (b == '+')
      v.push_back(1);
    else if (b == '-')
      v.push_back(-1);
    else
      break;
  }
  int n;
  cin >> n;
  int l = 0, r = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 1) {
      l++;
      r += n;
    } else {
      l -= n;
      r--;
    }
  }
  if (n >= l && n <= r) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
    return 0;
  }
  int N = n;
  vector<int> ans;
  for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i] == 1) {
      l--;
      r -= n;
      int nN = max(l, N - n);
      ans.push_back(N - nN);
      N = nN;
    } else {
      l += n;
      r++;
      int nN = min(r, N + n);
      ans.push_back(nN - N);
      N = nN;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans[0] << " ";
  for (int i = 1; i < ans.size(); i++) {
    if (v[i] == 1)
      cout << "+ ";
    else
      cout << "- ";
    cout << ans[i] << " ";
  }
  cout << "= ";
  cout << n << endl;
}
