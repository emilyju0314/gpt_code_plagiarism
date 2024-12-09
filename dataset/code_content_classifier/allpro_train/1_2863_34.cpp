#include <bits/stdc++.h>
using namespace std;
int main() {
  string DRUGI = "cslnb", PRVI = "sjfnb";
  int N;
  cin >> N;
  vector<long long> v(N);
  set<long long> set;
  int dvaput = 0;
  for (int i = 0; i < N; i++) {
    cin >> v[i];
    if (set.count(v[i])) {
      dvaput = v[i];
    }
    set.insert(v[i]);
  }
  if (v.size() - set.size() > 1) {
    cout << DRUGI;
  } else if (set.count(dvaput - 1) || (v.size() > set.size() && dvaput == 0)) {
    cout << DRUGI;
  } else {
    sort(v.begin(), v.end());
    long long sum = 0;
    for (int i = 0; i < N; i++) {
      sum += (v[i] - i);
    }
    if (sum % 2 == 1) {
      cout << PRVI;
    } else {
      cout << DRUGI;
    }
  }
}
