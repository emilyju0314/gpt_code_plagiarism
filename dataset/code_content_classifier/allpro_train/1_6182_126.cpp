#include <bits/stdc++.h>
using namespace std;
int ec;
int oc;
vector<vector<int> > ans;
stack<int> even;
stack<int> odd;
int makeEven() {
  vector<int> temp;
  if (!even.empty()) {
    temp.push_back(even.top());
    even.pop();
    ans.push_back(temp);
    return 1;
  }
  if (!odd.empty()) {
    temp.push_back(odd.top());
    odd.pop();
    if (!odd.empty()) {
      temp.push_back(odd.top());
      odd.pop();
      ans.push_back(temp);
    } else {
      return 0;
    }
    return 1;
  }
  return 0;
}
int makeOdd() {
  vector<int> temp;
  if (!odd.empty()) {
    temp.push_back(odd.top());
    odd.pop();
    ans.push_back(temp);
    return 1;
  }
  return 0;
}
int main() {
  int n, k, p;
  cin >> n >> k >> p;
  ec = 0;
  oc = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      even.push(x);
      ec++;
    } else {
      odd.push(x);
      oc++;
    }
  }
  for (int i = 0; i < p; i++) {
    if (!makeEven()) {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (int i = 0; i < k - p; i++) {
    if (!makeOdd()) {
      cout << "NO" << endl;
      return 0;
    }
  }
  int len = odd.size();
  if (len % 2 != 0) {
    cout << "NO" << endl;
    return 0;
  }
  len = ans[0].size();
  while (!even.empty()) {
    ans[0].push_back(even.top());
    even.pop();
  }
  while (!odd.empty()) {
    ans[0].push_back(odd.top());
    odd.pop();
  }
  len = ans.size();
  cout << "YES" << endl;
  for (int i = 0; i < k; i++) {
    cout << ans[i].size() << " ";
    int len = ans[i].size();
    for (int j = 0; j < len; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
