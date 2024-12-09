#include <bits/stdc++.h>
using namespace std;
int lsone(int n) { return (n & -n); }
long long int pow1(long long int a, long long int b) {
  if (b == 0)
    return 1ll;
  else if (b == 1)
    return a;
  else {
    long long int x = pow1(a, b / 2);
    x *= x;
    x %= 1000000007;
    if (b % 2) {
      x *= a;
      x %= 1000000007;
    }
    return x;
  }
}
int n, temp, cnt[210000];
vector<int> v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    v.push_back(temp);
    cnt[temp]++;
  }
  if (n == 1) {
    cout << 1 << "\n";
    cout << v[0] << "\n";
    return 0;
  }
  int maxim = 1, curr = 0, pos = v[0];
  for (int i = 1; i <= 2e5; i++) {
    curr += cnt[i];
    int p1 = i + 1;
    while (cnt[p1] >= 2) {
      curr += cnt[p1];
      p1++;
    }
    if (cnt[p1] == 1) curr++;
    if (curr > maxim) {
      maxim = curr;
      pos = i;
    }
    i = p1 - 1;
    curr = 0;
  }
  deque<int> d;
  for (int i = 0; i < cnt[pos]; i++) {
    d.push_back(pos);
  }
  for (int i = pos + 1;; i++) {
    if (cnt[i] == 0) break;
    if (cnt[i] == 1) {
      d.push_back(i);
      break;
    } else {
      d.push_front(i);
      for (int j = 0; j < cnt[i] - 1; j++) d.push_back(i);
    }
  }
  cout << maxim << "\n";
  while (!d.empty()) {
    int temp = d.front();
    d.pop_front();
    cout << temp << " ";
  }
  cout << "\n";
  return 0;
}
