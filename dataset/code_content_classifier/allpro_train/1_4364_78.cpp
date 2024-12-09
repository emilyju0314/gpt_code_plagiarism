#include <bits/stdc++.h>
using namespace std;
int a[100100];
int ans[100100];
int main() {
  int n;
  cin >> n;
  a[0] = INT_MAX;
  stack<int> stack_;
  int result = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    ans[i] = 0;
    while (stack_.size() && a[stack_.top()] < a[i]) {
      ans[i]++;
      ans[i] = max(ans[i], ans[stack_.top()]);
      stack_.pop();
    }
    stack_.push(i);
  }
  for (int i = 1; i <= n; i++) {
    result = max(result, ans[i]);
  }
  cout << result << endl;
  return 0;
}
