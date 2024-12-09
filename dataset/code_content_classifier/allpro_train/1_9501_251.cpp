#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, k, t, p;
  vector<long long int> vec, vec1, vec3;
  for (i = 1; i < 31; i++) {
    vec.push_back(powl(2, i));
  }
  for (i = 1; i < 20; i++) {
    vec1.push_back(powl(3, i));
  }
  for (i = 0; i < vec.size(); i++) {
    for (j = 0; j < vec1.size(); j++) {
      if (vec[i] * vec1[j] <= 2000000000) vec3.push_back(vec[i] * vec1[j]);
    }
  }
  sort(vec3.begin(), vec3.end());
  long long int nos = 0, l, r;
  cin >> l >> r;
  auto it = lower_bound(vec.begin(), vec.end(), l);
  auto it1 = lower_bound(vec.begin(), vec.end(), r);
  if (*it1 == r)
    nos += (it1 - it + 1);
  else
    nos += (it1 - it);
  it = lower_bound(vec1.begin(), vec1.end(), l);
  it1 = lower_bound(vec1.begin(), vec1.end(), r);
  if (*it1 == r)
    nos += (it1 - it + 1);
  else
    nos += (it1 - it);
  it = lower_bound(vec3.begin(), vec3.end(), l);
  it1 = lower_bound(vec3.begin(), vec3.end(), r);
  if (*it1 == r)
    nos += (it1 - it + 1);
  else
    nos += (it1 - it);
  if (l == 1) nos++;
  cout << nos << endl;
}
