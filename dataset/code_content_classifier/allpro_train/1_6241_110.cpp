#include <bits/stdc++.h>
using namespace std;
void run_case() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int &a : A) {
    cin >> a;
  }
  vector<int> ans;
  for (int i = 1; i < n; i++) {
    ans.push_back(A[i - 1] - A[i]);
  }
  sort(ans.begin(), ans.end());
  ;
  int res = A[n - 1] - A[0];
  for (int i = 0; i < k - 1; i++) {
    res += ans[i];
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  int test = 1;
  while (test--) {
    run_case();
    cout << '\n';
  }
}
