#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
map<long long, long long>::iterator it;
vector<long long> v;
int main() {
  long long a, b, c, d;
  cin >> a;
  v.resize(a);
  for (int i = 0; i < a; i++) {
    scanf("%lld", &v[i]);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < a; i++) {
    c = v[i] - v[i - 1];
    if (c < 0) c = c * -1;
    mp[c]++;
  }
  it = mp.begin();
  cout << it->first << " " << it->second << endl;
  return 0;
}
