#include <bits/stdc++.h>
using namespace std;
stack<int> s;
queue<int> q;
int main() {
  int n, k, c = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.push(a);
    q.push(a);
  }
  for (int i = 0; i < n; i++) {
    if (s.top() <= k) {
      s.pop();
      c++;
    } else if (q.front() <= k) {
      c++;
      q.pop();
    } else
      break;
  }
  cout << c << endl;
}
