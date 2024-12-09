#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void debugi(vector<int>& vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void debugl(vector<ll>& vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void debugmap(map<int, int>& mp) {
  for (auto x : mp) {
    cout << x.first << " " << x.second << " , ";
  }
  cout << endl;
}
void debugset(set<int>& st) {
  for (auto x : st) {
    cout << x << " ";
  }
  cout << endl;
}
void debugparri(vector<pair<int, int>>& arr) {
  for (int i = 0; i < (int)arr.size(); i++) {
    cout << "[" << arr[i].first << " : " << arr[i].second << "]"
         << " ";
  }
  cout << endl;
}
void debugpi(pair<int, int>& pi) {
  cout << pi.first << " " << pi.second << endl;
}
void debugq(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}
ll mod = 1000000007;
bool check(int n, int i, int j) {
  if ((0 <= i & i < n) && (0 <= j & j < n)) {
    return true;
  }
  return false;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<int> pre(n), suf(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] != i + 1) {
        s += 1;
      }
      pre[i] = s;
    }
    s = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i] != i + 1) {
        s += 1;
      }
      suf[i] = s;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (pre[i] != 0 && suf[i] != 0 && arr[i] == i + 1) {
        cnt += 1;
      }
    }
    if (cnt == 0) {
      if (s == 0) {
        cout << 0 << endl;
        continue;
      } else {
        cout << 1 << endl;
        continue;
      }
    }
    cout << 2 << endl;
    continue;
  }
  return 0;
}
