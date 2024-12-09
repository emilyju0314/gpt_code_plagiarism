#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T SQR(T x) {
  return x * x;
}
template <class T>
inline string TOSTR(const T &x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
template <class T>
void UPDATE_MIN(T &x, T y) {
  if (y < x) {
    x = y;
  }
}
template <class T>
void UPDATE_MAX(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
long long powmod(long long a, long long p, long long m) {
  long long r = 1;
  while (p) {
    if (p & 1) r = r * a % m;
    p >>= 1;
    a = a * a % m;
  }
  return r;
}
const int MOD = 1000 * 1000 * 1000 + 7;
const double PI = 3.1415926535897932384626433832795l;
int arr_who[(100000 + 10)];
vector<pair<int, int> > lst;
int cnt = 0;
int wins[2][(100000 + 10)];
int N;
int binsrch(int *arr, int i, int j, int val) {
  if (val > arr[j]) return -1;
  if (val < arr[i]) return -1;
  if (i == j) return (arr[i] == val) ? i : -1;
  int mid = (i + j) / 2;
  if (arr[mid] >= val)
    return binsrch(arr, i, mid, val);
  else
    return binsrch(arr, mid + 1, j, val);
}
int main() {
  cin >> N;
  for (int(i) = 0; (i) < (int)(N); (i)++) {
    cin >> arr_who[i];
    arr_who[i]--;
  }
  int cur_wins[2] = {};
  for (int(i) = 0; (i) < (int)(N); (i)++) {
    wins[0][i] = cur_wins[0];
    wins[1][i] = cur_wins[1];
    cur_wins[arr_who[i]]++;
  }
  wins[0][N] = cur_wins[0];
  wins[1][N] = cur_wins[1];
  for (int(t) = 1; (t) < (int)(N + 1); (t)++) {
    int s[2] = {0, 0};
    int i = 0, pl;
    int last_win = -1;
    while (i < N) {
      int ii[2];
      ii[0] = binsrch(wins[0], i, N, wins[0][i] + t);
      ii[1] = binsrch(wins[1], i, N, wins[1][i] + t);
      if (ii[0] == -1 && ii[1] == -1) break;
      pl = (ii[1] == -1 || (ii[0] != -1 && ii[0] < ii[1])) ? 0 : 1;
      i = ii[pl];
      s[pl]++;
      last_win = pl;
    }
    if (i != N) continue;
    if (s[last_win] <= s[last_win ^ 1]) continue;
    lst.push_back(make_pair(s[last_win], t));
  }
  sort(lst.begin(), lst.end());
  cout << lst.size() << endl;
  for (__typeof((lst).begin()) itr = (lst).begin(); itr != (lst).end(); itr++) {
    int s = (*itr).first;
    int t = (*itr).second;
    cout << s << " " << t << endl;
  }
  return 0;
}
