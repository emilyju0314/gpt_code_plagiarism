#include <bits/stdc++.h>
using namespace std;
int m = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int A[n];
  map<int, int> ma;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    ma[A[i]] = i;
  }
  int k = 0;
  vector<pair<int, int> > ans;
  for (int i = 0; i < n; i++) {
    int x1 = ma[i + 1];
    if (x1 == i) {
    } else {
      if (2 * (abs(x1 - i)) >= n) {
        k = k + 1;
        ma[A[i]] = x1;
        int c = A[x1];
        A[x1] = A[i];
        A[i] = c;
        ans.push_back(make_pair(i + 1, x1 + 1));
      } else {
        if (x1 >= (n / 2) && i >= (n / 2)) {
          k = k + 3;
          ma[A[i]] = x1;
          ans.push_back(make_pair(1, x1 + 1));
          ans.push_back(make_pair(1, i + 1));
          ans.push_back(make_pair(1, x1 + 1));
          int c = A[x1];
          A[x1] = A[i];
          A[i] = c;
        } else if (x1 < (n / 2) && i < (n / 2)) {
          ma[A[i]] = x1;
          k = k + 3;
          ans.push_back(make_pair(n, x1 + 1));
          ans.push_back(make_pair(n, i + 1));
          ans.push_back(make_pair(n, x1 + 1));
          int c = A[x1];
          A[x1] = A[i];
          A[i] = c;
        } else {
          k = k + 5;
          ma[A[i]] = x1;
          int c = A[x1];
          A[x1] = A[i];
          A[i] = c;
          ans.push_back(make_pair(1, max(x1, i) + 1));
          ans.push_back(make_pair(1, n));
          ans.push_back(make_pair(min(x1, i) + 1, n));
          ans.push_back(make_pair(1, n));
          ans.push_back(make_pair(1, max(x1, i) + 1));
        }
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
