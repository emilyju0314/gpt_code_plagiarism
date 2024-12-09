#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp;
  cin >> n;
  vector<int> v;
  while (n--) {
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  if (v.size() % 2 == 0) {
    cout << v[v.size() / 2 - 1] << "\n";
  } else {
    cout << v[v.size() / 2] << "\n";
  }
}
