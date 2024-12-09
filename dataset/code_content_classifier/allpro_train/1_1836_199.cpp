#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> comp;
vector<int> onecycle;
vector<int> clength;
vector<int> v9;
int cycle_start;
int cycle_end;
vector<int> vbip1;
vector<int> vbip2;
void addedge(int u, int v, vector<int> adj[]) { adj[u].push_back(v); }
void dfsforconnectedcomponents(int s, vector<int> adj[], int V, int u[],
                               int &count) {
  v9.push_back(s);
  u[s] = 1;
  int i;
  for (i = 0; i < adj[s].size(); i++) {
    if (u[adj[s][i]] == 0) {
      count++;
      dfsforconnectedcomponents(adj[s][i], adj, V, u, count);
    }
  }
}
void connectedcomponents(int V, vector<int> adj[], int u[], int a[]) {
  int i;
  for (i = 1; i < V + 1; i++) {
    if (u[i] == 0 && a[i] == 1) {
      int count = 1;
      dfsforconnectedcomponents(i, adj, V, u, count);
      comp.push_back(v9);
      v9.clear();
    }
  }
}
bool dfs1foronecycle(int s, int V, int color[], vector<int> adj[], int p[]) {
  color[s] = 1;
  int i;
  for (i = 0; i < adj[s].size(); i++) {
    if (color[adj[s][i]] == 0) {
      p[adj[s][i]] = s;
      if (dfs1foronecycle(adj[s][i], V, color, adj, p)) {
        return true;
      }
    } else if (color[adj[s][i]] == 1 && p[s] != adj[s][i]) {
      cycle_start = adj[s][i];
      cycle_end = s;
      return true;
    }
  }
  color[s] = 2;
  return false;
}
void cyclesusingdfs1(int V, vector<int> adj[], int color[], int p[]) {
  int i;
  for (i = 1; i < V + 1; i++) {
    if (color[i] == 0) {
      if (dfs1foronecycle(i, V, color, adj, p)) {
        int count = 1;
        i = cycle_end;
        while (i != cycle_start) {
          i = p[i];
          count++;
        }
        clength.push_back(count);
        count = 0;
      }
    }
  }
}
bool bfsbipartite(vector<int> adj[], int V) {
  int u[V + 1];
  int i;
  for (i = 0; i < V + 1; i++) {
    u[i] = 0;
  }
  int color[V + 1];
  for (i = 0; i < V + 1; i++) {
    color[i] = -1;
  }
  int s;
  for (s = 1; s < V + 1; s++) {
    if (color[s] == -1) {
      u[s] = 1;
      color[s] = 1;
      queue<int> q;
      q.push(s);
      while (!q.empty()) {
        int z = q.front();
        q.pop();
        for (i = 0; i < adj[z].size(); i++) {
          int k = adj[z][i];
          if (color[k] == -1) {
            color[k] = 1 - color[z];
            u[k] = 1;
            q.push(k);
          }
        }
      }
    }
  }
  int flag[V + 1];
  for (i = 0; i < V + 1; i++) {
    flag[i] = 0;
  }
  for (i = 1; i < V + 1; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      if (color[i] == color[adj[i][j]]) {
        return false;
      }
      if (color[adj[i][j]] == 1 && flag[adj[i][j]] == 0) {
        flag[adj[i][j]] = 1;
        vbip1.push_back(adj[i][j]);
      }
      if (color[adj[i][j]] == 0 && flag[adj[i][j]] == 0) {
        flag[adj[i][j]] = 1;
        vbip2.push_back(adj[i][j]);
      }
    }
  }
  return true;
}
void bfs1(int V, int s, vector<int> adj[], int d[], int anc[], int u[]) {
  int i;
  d[s] = 0;
  u[s] = 1;
  queue<int> q;
  q.push(s);
  vector<int> v;
  while (!q.empty()) {
    int z = q.front();
    q.pop();
    for (i = 0; i < adj[z].size(); i++) {
      int k = adj[z][i];
      if (u[adj[z][i]] == 0) {
        anc[z] = adj[z][i];
        d[k] = d[z] + 1;
        u[k] = 1;
        q.push(k);
      }
    }
  }
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return l;
}
string bin(long long x) {
  string s = "";
  while (x != 0) {
    if (x % 2 == 0) {
      s.push_back('0');
    } else {
      s.push_back('1');
    }
    x = x / 2;
  }
  int l = s.length();
  int i;
  reverse(s.begin(), s.end());
  return s;
}
vector<long long> prime(int n) {
  int prime[n + 1];
  for (int i = 0; i < n + 1; i++) prime[i] = 1;
  for (int p = 2; p * p <= n + 1; p++) {
    if (prime[p] == 1) {
      for (int i = p * p; i <= n + 1; i += p) prime[i] = 0;
    }
  }
  vector<long long> v;
  long long i;
  for (i = 2; i < n + 1; i++) {
    if (prime[i] == 1) {
      v.push_back(i);
    }
  }
  return v;
}
long long fun(long long n, long long dp[], long long a[]) {
  if (n <= 0) {
    return 0;
  }
  if (dp[n] == -1) {
    long long sum = 0;
    for (int i = 1; i <= a[n - 1]; i++) {
      if (n - i > 0) {
        sum += fun(n - i, dp, a) % 1000000007;
      }
    }
    return dp[n] = sum % 1000000007;
  } else {
    return dp[n] % 1000000007;
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int i;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    int count1 = 0;
    int count2 = 0;
    sort(a, a + n);
    for (i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        count1++;
      } else {
        count2++;
      }
    }
    if (count1 % 2 == 0) {
      cout << "YES" << endl;
    } else {
      int flag = 0;
      for (i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == 1) {
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
