#include <bits/stdc++.h>
using namespace std;
int sz, prime[10000];
bool isPrime[100005 + 5];
void sieve() {
  for (int i = 2; i <= 100005; i++) isPrime[i] = true;
  sz = 0;
  for (int i = 2; i < 100005; i++)
    if (isPrime[i]) {
      prime[sz++] = i;
      for (int j = 2; i * j < 100005; j++) isPrime[i * j] = false;
    }
}
int binarySearch(int lo, int hi, int value) {
  int mid;
  for (int i = 0; i < 20; i++) {
    mid = (lo + hi) / 2;
    if (prime[mid] == value) return prime[mid];
    if (value < prime[mid])
      hi = mid - 1;
    else
      lo = mid;
  }
  return prime[mid];
}
int n;
int a[100005], pos[100005];
int main() {
  sieve();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i + 1;
  }
  vector<pair<int, int> > res;
  for (int i = 0; i < n; i++) {
    int from = pos[i + 1];
    int to = i + 1;
    while (from - to) {
      int tmp = from - binarySearch(0, sz - 1, from - to + 1) + 1;
      res.push_back(make_pair(tmp, from));
      swap(a[from - 1], a[tmp - 1]);
      swap(pos[a[from - 1]], pos[a[tmp - 1]]);
      from = tmp;
    }
  }
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); i++)
    printf("%d %d\n", res[i].first, res[i].second);
  return 0;
}
