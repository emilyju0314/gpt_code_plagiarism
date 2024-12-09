#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200009];
map<long long, long long> num;
vector<long long> v;
long long check(long long x) {
  vector<long long>::iterator it1 = v.begin();
  long long sum = 0;
  long long crnt = x;
  while (1) {
    vector<long long>::iterator it2 = lower_bound(it1, v.end(), crnt);
    if (it2 == v.end()) break;
    it1 = it2;
    it1++;
    sum += crnt;
    crnt *= 2;
  }
  return sum;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]), num[a[i]]++;
  for (map<long long, long long>::iterator i = num.begin(); i != num.end();
       i++) {
    v.push_back(i->second);
  }
  sort(v.begin(), v.end());
  long long mx = 0;
  for (long long i = 1; i <= n; i++) {
    long long x = check(i);
    mx = max(mx, x);
  }
  cout << mx << endl;
}
