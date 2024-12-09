#include <bits/stdc++.h>
using namespace std;
int main() {
  priority_queue<long long int, vector<long long int>, greater<long long int>>
      huff;
  int n;
  long long int t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    huff.push(t);
  }
  t = 0;
  if (!(n % 2)) {
    t += huff.top();
    huff.pop();
    t += huff.top();
    huff.pop();
    huff.push(t);
  }
  long long int s;
  while (huff.size() > 2) {
    s = 0;
    s += huff.top();
    huff.pop();
    s += huff.top();
    huff.pop();
    s += huff.top();
    huff.pop();
    huff.push(s);
    t += s;
  }
  cout << t;
  return 0;
}
