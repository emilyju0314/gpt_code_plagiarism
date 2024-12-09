#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  return (b == 0 ? a : gcd(b, a % b));
}
long long n, m, r, z, l, k, a, h, t, s;
char c;
const int maxn = 10010;
vector<int> ed[maxn];
int x[maxn], y[maxn], w[maxn], b[maxn];
long long N, Q;
long long current_answer;
long long cnt1[1234567];
long long answers[200500];
long long BLOCK_SIZE;
long long arr[200500];
pair<pair<long long, long long>, long long> queries[200500];
inline bool mo_cmp(const pair<pair<long long, long long>, long long> &x,
                   const pair<pair<int, int>, int> &y) {
  int block_x = x.first.first / BLOCK_SIZE;
  int block_y = y.first.first / BLOCK_SIZE;
  if (block_x != block_y) return block_x < block_y;
  return x.first.second < y.first.second;
}
inline void add(long long x) {
  if (x > 1e5) return;
  if (cnt1[x] == x) current_answer--;
  if (cnt1[x] == x - 1) current_answer++;
  cnt1[x]++;
}
inline void remove(long long x) {
  if (x > 1e5) return;
  if (cnt1[x] == x) current_answer--;
  if (cnt1[x] == x + 1) current_answer++;
  cnt1[x]--;
}
void solve() {
  cin >> N >> Q;
  BLOCK_SIZE = 1000;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = 0; i < Q; i++) {
    long long x, y;
    cin >> queries[i].first.first >> queries[i].first.second;
    queries[i].first.first--;
    queries[i].first.second--;
    queries[i].second = i;
  }
  sort(queries, queries + Q, mo_cmp);
  int mo_left = 0, mo_right = -1;
  current_answer = 0;
  for (int i = 0; i < Q; i++) {
    int left = queries[i].first.first;
    int right = queries[i].first.second;
    while (mo_right < right) {
      mo_right++;
      add(arr[mo_right]);
    }
    while (mo_right > right) {
      remove(arr[mo_right]);
      mo_right--;
    }
    while (mo_left < left) {
      remove(arr[mo_left]);
      mo_left++;
    }
    while (mo_left > left) {
      mo_left--;
      add(arr[mo_left]);
    }
    answers[queries[i].second] = current_answer;
  }
  for (int i = 0; i < Q; i++) cout << answers[i] << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  memset(cnt1, 0, sizeof(cnt1));
  solve();
  return 0;
}
