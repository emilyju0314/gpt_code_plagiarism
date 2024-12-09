#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<long long, vector<long long>, greater<long long>>
    minHeap;
struct POS {
  int x = 0, y = 0;
  POS() : x(0), y(0) {}
  POS(int _x, int _y) : x(_x), y(_y) {}
};
struct triple {
  int f, s, t;
  triple() : f(0), s(0), t(0) {}
  triple(int _f, int _s, int _t) : f(_f), s(_s), t(_t) {}
};
const int INF = 1e9 + 9;
const long long LINF = 1e17 + 9;
const long long MD = 1000000007;
inline long long po(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % MD;
    a = (a * a) % MD;
    b /= 2;
  }
  return ans;
}
const int N = 1e5 + 33;
long long n, m, k, t;
long long arr[N];
vector<int> tree[N];
string s;
int root;
int fdfs(int v, int p) {
  int ans = 0;
  for (int u : tree[v]) {
    if (u != p) {
      if (arr[u] != arr[v]) return v;
      int x = fdfs(u, v);
      ans = (x != 0 ? x : ans);
    }
  }
  return ans;
}
bool dfs(int v, int p) {
  bool ans = 1;
  for (int u : tree[v]) {
    if (u != p) {
      ans &= (v == root || arr[v] == arr[u]);
      ans &= dfs(u, v);
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int f = fdfs(1, 1);
  if (f == 0) {
    cout << "YES" << endl << 1;
    return 0;
  }
  int dif = 0, v = f;
  for (int u : tree[f]) {
    if (arr[u] != arr[f]) {
      v = u;
      dif++;
    }
  }
  if (dif > 1) v = f;
  root = v;
  if (dfs(root, root)) {
    cout << "YES" << endl << root;
  } else {
    cout << "NO";
  }
  return 0;
}
