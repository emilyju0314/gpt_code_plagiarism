#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;
int spf[MAXN];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < MAXN; i++) spf[i] = i;
  for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
  for (int i = 3; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < MAXN; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
long long m = 1e9 + 7;
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long p = power(x, y / 2) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
const int maxN = 1e5;
const int k = 86;
int tree[2 * maxN][k];
vector<pair<int, long long> > tree1[2 * maxN];
void merge(int ind) {
  for (int i = 0; i < k; i++) {
    tree[ind][i] = max(tree[ind << 1][i], tree[ind << 1 | 1][i]);
  }
}
void build(int n) {
  for (int i = n - 1; i > 0; i--) {
    merge(i);
  }
}
void build1(pair<int, long long> arr[], int n) {
  for (int i = 0; i < n; i++) {
    tree1[i + n] = {arr[i]};
  }
  for (int i = n - 1; i > 0; i--) {
    for (auto ele : tree1[i << 1]) tree1[i].push_back(ele);
    for (auto ele : tree1[i << 1 | 1]) tree1[i].push_back(ele);
    sort(tree1[i].begin(), tree1[i].end());
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = 1; j < tree1[i].size(); j++) {
      tree1[i][j].second = (tree1[i][j].second * tree1[i][j - 1].second) % m;
    }
  }
}
map<int, int> inv_prime;
long long query(int l, int r, int n) {
  long long res = 1;
  int cnt[k] = {0};
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      for (int i = 0; i < k; i++) cnt[i] = max(cnt[i], tree[l][i]);
      l++;
    }
    if (r & 1) {
      r--;
      for (int i = 0; i < k; i++) cnt[i] = max(cnt[i], tree[r][i]);
    }
  }
  for (int i = 0; i < k; i++) {
    res = (res * power(inv_prime[i], cnt[i])) % m;
  }
  return res;
}
long long query1(int l, int r, int n) {
  int _l = l;
  long long res = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      auto itr =
          lower_bound(tree1[l].begin(), tree1[l].end(), make_pair(_l, 0LL));
      if (itr != tree1[l].begin()) {
        itr--;
        res = (res * (itr->second)) % m;
      }
      l++;
    }
    if (r & 1) {
      r--;
      auto itr =
          lower_bound(tree1[r].begin(), tree1[r].end(), make_pair(_l, 0LL));
      if (itr != tree1[r].begin()) {
        itr--;
        res = (res * (itr->second)) % m;
      }
    }
  }
  return res;
}
int main() {
  sieve();
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt = 0;
  map<int, int> prime;
  for (int i = 2; i * i <= MAXN; i++) {
    if (spf[i] == i) prime[i] = cnt, inv_prime[cnt] = i, cnt++;
  }
  for (int i = 0; i < n; i++) {
    int start = arr[i];
    arr[i] = 1;
    for (int j = 0; j < k; j++) tree[i + n][j] = 0;
    while (start > 1) {
      long long div = spf[start];
      if (div * div <= MAXN) {
        tree[i + n][prime[div]]++;
      } else {
        arr[i] = div;
      }
      start /= spf[start];
    }
  }
  pair<int, long long> temp[n];
  map<int, int> prev;
  for (int i = 0; i < n; i++) {
    if (prev.find(arr[i]) != prev.end()) {
      temp[i] = {prev[arr[i]], arr[i]};
    } else {
      temp[i] = {-1, arr[i]};
    }
    prev[arr[i]] = i;
  }
  build(n);
  build1(temp, n);
  long long last = 0;
  long long x, y;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    x = (last + x) % n + 1;
    y = (last + y) % n + 1;
    if (y < x) {
      swap(x, y);
    }
    x--, y--;
    last = query1(x, y + 1, n) * query(x, y + 1, n) % m;
    cout << last << endl;
  }
  return 0;
}
