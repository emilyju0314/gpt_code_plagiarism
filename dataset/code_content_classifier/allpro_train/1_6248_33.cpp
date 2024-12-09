#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 5;
const long long MAXN2 = 1e4 + 5;
const long long MAXN3 = 1e3 + 5;
deque<pair<long long, long long>> q1;
bool visited[MAXN2][MAXN3];
long long arr[MAXN];
long long dist[MAXN2][MAXN3];
int main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + m + 1);
  long long r, g;
  cin >> g >> r;
  q1.push_back(make_pair(1, 0));
  visited[1][0] = true;
  for (long long i = 1; i <= m; i++) {
    for (long long j = 0; j <= g; j++) {
      dist[i][j] = 1e17;
    }
  }
  dist[1][0] = 0;
  while (!q1.empty()) {
    pair<long long, long long> hold = q1.front();
    q1.pop_front();
    long long i = hold.first;
    long long temp = hold.second;
    if (i < m && temp + arr[i + 1] - arr[i] <= g &&
        !visited[i + 1][temp + arr[i + 1] - arr[i]]) {
      q1.push_front(make_pair(i + 1, temp + arr[i + 1] - arr[i]));
      dist[i + 1][temp + arr[i + 1] - arr[i]] = dist[i][temp];
      visited[i + 1][temp + arr[i + 1] - arr[i]] = true;
    }
    if (i > 1 && temp + arr[i] - arr[i - 1] <= g &&
        !visited[i - 1][temp + arr[i] - arr[i - 1]]) {
      q1.push_front(make_pair(i - 1, temp + arr[i] - arr[i - 1]));
      dist[i - 1][temp + arr[i] - arr[i - 1]] = dist[i][temp];
      visited[i - 1][temp + arr[i] - arr[i - 1]] = true;
    }
    if (temp == g && !visited[i][0]) {
      q1.push_back(make_pair(i, 0));
      dist[i][0] = dist[i][temp] + r + g;
      visited[i][0] = true;
    }
  }
  long long ans = 1e17;
  for (long long i = 0; i <= g; i++) {
    ans = min(ans, dist[m][i] + i);
  }
  if (ans >= 1e17) {
    ans = -1;
  }
  cout << ans << endl;
}
