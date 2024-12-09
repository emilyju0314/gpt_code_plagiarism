#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else {
    return gcd(b, a % b);
  }
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
vector<vector<int> > vec(100005);
map<int, int> mp;
bool vis[100005];
void flag(int node) {
  if (vis[node]) return;
  vis[node] = 1;
  if (mp[node] == 1) {
    if (vec[node].size())
      for (long long c = 0; c < vec[node].size(); c++) {
        if (mp[vec[node][c]] == 2) continue;
        mp[vec[node][c]] = 2;
        flag(vec[node][c]);
      }
  } else if (mp[node] == 2) {
    if (vec[node].size())
      for (long long c = 0; c < vec[node].size(); c++) {
        if (mp[vec[node][c]] == 1) continue;
        mp[vec[node][c]] = 1;
        flag(vec[node][c]);
      }
  }
}
int main() {
  int n;
  cin >> n;
  int x[n], z[n];
  for (long long c = 0; c < n - 1; c++) {
    cin >> x[c] >> z[c];
    vec[x[c]].push_back(z[c]);
    vec[z[c]].push_back(x[c]);
  }
  mp[x[0]] = 1;
  flag(x[0]);
  set<int> se1, se2;
  vector<int> vec1, vec2;
  for (long long c = 0; c < n + 1; c++) {
    if (mp[c] == 1) {
      se1.insert(c);
      vec1.push_back(c);
    } else if (mp[c] == 2)
      se2.insert(c);
  }
  unsigned long long ans = 0, num;
  for (long long c = 0; c < vec1.size(); c++) {
    num = vec1[c];
    if (vec[num].size() < se2.size()) {
      ans += se2.size() - vec[num].size();
    }
  }
  cout << ans << "\n";
  return 0;
}
