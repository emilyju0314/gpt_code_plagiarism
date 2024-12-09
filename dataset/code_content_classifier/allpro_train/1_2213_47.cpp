#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct node {
  int x, gas;
  node() {}
  node(int _x, int _gas) : x(_x), gas(_gas) {}
};
bool operator<(const node a, const node b) { return a.x < b.x; }
bool cmp(node a, node b) { return a.x < b.x; }
struct table {
  int n, m;
  vector<vector<int> > a;
  vector<short int> sz;
  table(vector<int> &arr) {
    n = 20;
    m = arr.size();
    a = vector<vector<int> >(n, vector<int>(m));
    for (int k = 0; k < m; k++) {
      a[0][k] = arr[k];
    }
    for (int k = 1; k < n; k++) {
      for (int i = 0; i < m; i++) {
        if (i + (1 << (k - 1)) < m) {
          a[k][i] = min(a[k - 1][i], a[k - 1][i + (1 << (k - 1))]);
        } else {
          a[k][i] = a[k - 1][i];
        }
      }
    }
    sz.resize(m + 1);
    sz[1] = 0;
    for (int k = 2; k <= m; k++) {
      if ((2 << sz[k - 1]) < k) {
        sz[k] = sz[k - 1] + 1;
      } else {
        sz[k] = sz[k - 1];
      }
    }
  }
  int query(int left, int right) {
    int s = sz[right - left + 1];
    return min(a[s][left], a[s][right - (1 << s) + 1]);
  }
  void print() {
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < (int)a[k].size(); i++) {
        cout << a[k][i] << " ";
      }
      cout << '\n';
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  int d, n, m;
  cin >> d >> n >> m;
  vector<node> arr(m);
  for (int k = 0; k < m; k++) {
    cin >> arr[k].x >> arr[k].gas;
  }
  arr.push_back(node(0, 0));
  arr.push_back(node(d, 0));
  sort(arr.begin(), arr.end(), cmp);
  vector<int> help(arr.size());
  for (int k = 0; k < (int)arr.size(); k++) {
    help[k] = arr[k].gas;
  }
  table s(help);
  long long cur = n, res = 0;
  for (int k = 1; k < (int)arr.size() - 1; k++) {
    int low = k + 1, high = arr.size() - 1;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      if (s.query(k + 1, mid) < arr[k].gas) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    int ind = -1;
    if (s.query(k + 1, high) < arr[k].gas) {
      ind = high;
    }
    if (s.query(k + 1, low) < arr[k].gas) {
      ind = low;
    }
    cur -= arr[k].x - arr[k - 1].x;
    int len = arr[ind].x - arr[k].x;
    if (len > cur && len <= n) {
      res += (len - cur) * arr[k].gas;
      cur = len;
    }
    if (len > n) {
      res += (n - cur) * arr[k].gas;
      cur = n;
    }
    if (arr[k].x - arr[k - 1].x > n) {
      cout << -1;
      return 0;
    }
  }
  if (arr[arr.size() - 1].x - arr[arr.size() - 2].x > n) {
    cout << -1;
    return 0;
  }
  cout << res;
  return 0;
}
