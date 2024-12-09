#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp, mp1;
vector<pair<long long, pair<long long, long long> > > vpp, vpp1;
vector<pair<long long, long long> > vp, fin;
vector<long long> v, v1, v2, dummy;
map<pair<long long, long long>, long long> mpp;
map<long long, bool> mb;
vector<long long> prime;
bool visited[1005 + 10];
long long arr[1005 + 10];
long long n, k, a, b, c, d, ta, sum = 0, cnt = 0, m, l, req, sz;
bool sortbysec(const pair<pair<long long, long long>, long long> &a,
               const pair<pair<long long, long long>, long long> &b) {
  return (a.second < b.second);
}
void seive() {
  memset(arr, 0, sizeof arr);
  memset(visited, false, sizeof false);
  prime.push_back(2);
  for (long long i = 4; i <= 1005; i += 2) {
    arr[i] = 1;
    visited[i] = true;
  }
  for (long long i = 3; i <= 1005; i += 2) {
    if (visited[i] == false) {
      prime.push_back(i);
      arr[i] = prime.size();
      for (long long j = i + i; j <= 1005; j += i) {
        if (arr[j] == 0) arr[j] = prime.size();
        visited[j] = true;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  seive();
  cin >> ta;
  for (long long test = 0; test < ta; test++) {
    cin >> n;
    v.clear();
    mp.clear();
    set<long long> st;
    long long cnt = 1;
    vector<long long> ans;
    for (long long i = 0; i < n; i++) {
      cin >> a;
      v.push_back(a);
      if (mp[arr[v[i]]] == 0) mp[arr[v[i]]] = cnt++;
      ans.push_back(mp[arr[v[i]]]);
    }
    cout << cnt - 1 << endl;
    for (long long i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
