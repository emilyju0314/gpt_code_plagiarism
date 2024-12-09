#include <bits/stdc++.h>
using namespace std;
void read(vector<unsigned long long int> &v) {
  for (int i = 0; i < v.size(); i++) cin >> v[i];
}
void print(vector<unsigned long long int> v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}
unsigned long long int n, m, a, b, temp;
string str;
set<unsigned long long int> s;
vector<unsigned long long int> v;
bool check(unsigned long long int n) {
  unsigned long long int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    if (n / v[i] == 0) break;
    sum += n / v[i];
    if (sum >= m) break;
  }
  if (sum < m) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m;
  for (unsigned long long int i = 2; i <= 1000000; i++) v.push_back(i * i * i);
  unsigned long long int l = 8;
  unsigned long long int r = 1e16;
  unsigned long long int mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  unsigned long long int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    if (l / v[i] == 0) break;
    sum += l / v[i];
  }
  if (sum != m)
    cout << -1;
  else
    cout << l;
}
