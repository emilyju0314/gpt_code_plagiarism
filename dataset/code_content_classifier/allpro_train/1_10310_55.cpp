#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n], b[n];
  priority_queue<pair<int, bool> > pq;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pq.push(make_pair(a[i], 0));
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    pq.push(make_pair(b[i], 1));
  }
  bool c = 0;
  long long s[] = {0, 0};
  while (!pq.empty()) {
    pair<int, bool> curr = pq.top();
    if (curr.second == c) {
      s[c] += curr.first;
    }
    pq.pop();
    c = !c;
  }
  cout << s[0] - s[1];
  return 0;
}
