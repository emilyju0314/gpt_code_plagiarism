#include <bits/stdc++.h>
using namespace std;
const long double epsylon = 1e-9;
const std::string PROGRAM_NAME = "ivo";
pair<int, int> get(const vector<int>& q) {
  cout << "?";
  for (int i = 0; i < (int)q.size(); ++i) {
    cout << " " << q[i];
  }
  cout << endl;
  fflush(stdout);
  pair<int, int> x;
  cin >> x.first;
  if (x.first == -1) {
    exit(0);
  }
  cin >> x.second;
  return x;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> q(k);
  for (int i = 0; i < (int)q.size(); ++i) {
    q[i] = i + 1;
  }
  pair<int, int> a = get(q);
  q[a.first - 1] = k + 1;
  pair<int, int> b = get(q);
  int bigger = 0, smaller = 0;
  for (int i = 0; i < k; ++i) {
    if (q[i] == b.first) {
      continue;
    }
    int old_value = q[i];
    q[i] = a.first;
    pair<int, int> temp;
    temp = get(q);
    if (temp.first == b.first) {
      if (a.second < b.second) {
        smaller++;
      } else {
        bigger++;
      }
    } else {
      if (a.second < b.second) {
        bigger++;
      } else {
        smaller++;
      }
    }
    q[i] = old_value;
  }
  cout << "! " << smaller + 1 << endl;
  fflush(stdout);
  return 0;
}
