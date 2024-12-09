#include <bits/stdc++.h>
using namespace std;
long long int l, x, y, n, m, i, z, p, s, e, q, j, k = 1000000007, c, d, t, h,
                                                  sum = 0;
string s1, s2;
vector<long long int> v[1000001];
long long int a[1000001], visited[1000001], b[200001], dis[1000001];
char ch;
stack<long long int> st;
void bfs(long long int s) {
  queue<long long int> q;
  q.push(s);
  dis[s] = 0;
  st.push(s);
  visited[s] = 1;
  while (!q.empty()) {
    k = q.front(), q.pop();
    for (auto x : v[k]) {
      if (visited[x]) continue;
      visited[x] = 1;
      st.push(x);
      q.push(x);
      dis[x] = dis[k] + 1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int k2;
  cin >> n >> m >> k2;
  long long int a[n + 2][m + 2];
  long long int arr[(n + 2) * (m + 2)];
  for (long long int i = 0; i < n + 2; i++) {
    for (long long int j = 0; j < m + 2; j++) {
      if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
        a[i][j] = -1;
      else {
        arr[(m * (i - 1)) + j] = 0;
        cin >> ch;
        if (ch == '#')
          a[i][j] = -1;
        else
          a[i][j] = 1;
      }
    }
  }
  long long int curr, left, right, up, down;
  for (long long int i = 0; i < n + 1; i++) {
    for (long long int j = 0; j < m + 1; j++) {
      if (a[i][j] == 1) {
        curr = (m * (i - 1)) + j, left = (m * (i - 1)) + j - 1,
        right = (m * (i - 1)) + j + 1, up = (m * (i - 2)) + j,
        down = (m * (i)) + j;
        if (a[i][j - 1] == 1) v[curr].push_back(left);
        if (a[i][j + 1] == 1) v[curr].push_back(right);
        if (a[i - 1][j] == 1) v[curr].push_back(up);
        if (a[i + 1][j] == 1) v[curr].push_back(down);
      }
    }
  }
  bfs(curr);
  for (i = 1; i <= k2; i++) {
    k = st.top();
    st.pop();
    arr[k] = -1;
  }
  for (long long int i = 1; i < n + 1; i++) {
    for (long long int j = 1; j < m + 1; j++) {
      curr = (m * (i - 1)) + j;
      if (a[i][j] == -1)
        cout << "#";
      else if (arr[curr] == -1)
        cout << "X";
      else
        cout << ".";
    }
    cout << endl;
  }
}
