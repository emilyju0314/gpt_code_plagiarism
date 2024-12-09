#include <bits/stdc++.h>
using namespace std;
bool not_possible = false;
long long int count_visitors(vector<vector<int>> &adj, vector<int> &p,
                             vector<long long> &visitor, int curr, int par) {
  long long int a = 0;
  for (auto x : adj[curr]) {
    if (x != par) a += count_visitors(adj, p, visitor, x, curr);
  }
  a += p[curr];
  visitor[curr] = a;
  return a;
}
long long int count_happy_people(vector<vector<int>> &adj, vector<int> &p,
                                 vector<long long> &visitor,
                                 vector<long long> &h, int curr, int par) {
  long long int happy_people_child = 0;
  for (auto x : adj[curr]) {
    if (x != par) {
      happy_people_child += count_happy_people(adj, p, visitor, h, x, curr);
    }
  }
  long long int happy_people_curr = (visitor[curr] + h[curr]) / 2;
  if (happy_people_curr > visitor[curr] || happy_people_curr < 0 ||
      (visitor[curr] + h[curr]) % 2 != 0 ||
      happy_people_curr < happy_people_child) {
    not_possible = true;
  }
  return happy_people_curr;
}
int main() {
  long long int T;
  cin >> T;
  for (long long int itr = 0; itr < T; itr++) {
    not_possible = false;
    long long int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (long long int i = 0; i < n; i++) cin >> p[i];
    vector<long long> h(n);
    for (long long int i = 0; i < n; i++) cin >> h[i];
    vector<vector<int>> adj(n);
    for (long long int i = 0; i < n - 1; i++) {
      long long int x, y;
      cin >> x >> y;
      adj[x - 1].push_back(y - 1);
      adj[y - 1].push_back(x - 1);
    }
    vector<long long int> visitor(n);
    count_visitors(adj, p, visitor, 0, -1);
    count_happy_people(adj, p, visitor, h, 0, -1);
    if (not_possible)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
}
