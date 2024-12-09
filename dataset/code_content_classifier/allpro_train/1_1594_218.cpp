#include <bits/stdc++.h>
using namespace std;
long long r, c;
char arr[1005][1005];
long long vtx[1005][1005];
long long num = -1;
vector<pair<int, int> > adjlist[1000005];
priority_queue<pair<int, int> > pq;
void process(long long i, long long j, long long a, long long b) {
  if (a <= 0 || b <= 0 || a > r || b > c) return;
  if (arr[a][b] != 'T')
    adjlist[vtx[i][j]].push_back(pair<int, int>(vtx[a][b], 1));
}
int main() {
  cin >> r >> c;
  for (long long i = 1; i <= r; i++) {
    for (long long j = 1; j <= c; j++) {
      cin >> arr[i][j];
      if (arr[i][j] != 'T') {
        vtx[i][j] = ++num;
      }
    }
  }
  for (long long i = 1; i <= r; i++) {
    for (long long j = 1; j <= c; j++) {
      if (arr[i][j] != 'T') {
        process(i, j, i - 1, j);
        process(i, j, i + 1, j);
        process(i, j, i, j + 1);
        process(i, j, i, j - 1);
      }
    }
  }
  long long dist[num + 5];
  bool process[num + 5];
  for (long long i = 0; i < num; i++) {
    dist[i] = 1e12 + 2;
    process[i] = 0;
  }
  long long id1, id2;
  for (long long i = 1; i <= r; i++) {
    for (long long j = 1; j <= c; j++) {
      if (arr[i][j] == 'E') {
        id1 = i;
        id2 = j;
      }
    }
  }
  long long root = vtx[id1][id2];
  dist[root] = 0;
  pq.push(pair<int, int>(0, root));
  while (!pq.empty()) {
    long long a = pq.top().second;
    pq.pop();
    if (process[a]) continue;
    process[a] = 1;
    for (long long i = 0; i < adjlist[a].size(); i++) {
      pair<int, int> u = adjlist[a][i];
      long long b = u.first, w = u.second;
      if (dist[a] + w < dist[b]) {
        dist[b] = dist[a] + w;
        pq.push(pair<int, int>(-dist[b], b));
      }
    }
  }
  long long leng;
  for (long long i = 1; i <= r; i++) {
    for (long long j = 1; j <= c; j++) {
      if (arr[i][j] == 'S') {
        leng = dist[vtx[i][j]];
        break;
      }
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= r; i++) {
    for (long long j = 1; j <= c; j++) {
      if ('0' <= arr[i][j] && arr[i][j] <= '9') {
        if (dist[vtx[i][j]] <= leng) {
          ans += (arr[i][j] - '0');
        }
      }
    }
  }
  cout << ans;
}
