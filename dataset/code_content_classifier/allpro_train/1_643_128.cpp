#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long fast_power(long long base, long long power) {
  long long res = 1;
  while (power) {
    if (power & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    power /= 2;
  }
  return (res % mod);
}
void in_out_txt() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
vector<int> vec;
void fll() {
  vec.push_back(1);
  vec.push_back(10);
  vec.push_back(11);
  int i = 1, j = 1, s = 3, x = 0;
  while (j < 5) {
    j++;
    while (i < s) {
      vec.push_back(vec[i] * 10);
      vec.push_back(vec[i] * 10 + 1);
      x++;
      i++;
    }
    s = vec.size();
  }
  vec.push_back(1000000);
}
int n;
short mem[65][1000005];
bool vis[65][1000005];
int solve(int ind, int sum) {
  if (ind == vec.size() && sum == n) {
    return 0;
  }
  if (sum > n || ind == vec.size()) return 1e3;
  if (mem[ind][sum] != -1) return mem[ind][sum];
  mem[ind][sum] = solve(ind + 1, sum);
  int p = solve(ind, sum + vec[ind]);
  if (p + 1 < mem[ind][sum]) mem[ind][sum] = p + 1, vis[ind][sum] = 1;
  return mem[ind][sum];
}
void print_(int ind, int sum) {
  if (ind == vec.size() || sum == n) {
    return;
  }
  if (vis[ind][sum] == 1) {
    cout << vec[ind] << " ";
    print_(ind, sum + vec[ind]);
  } else
    print_(ind + 1, sum);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fll();
  memset(mem, -1, sizeof mem);
  cin >> n;
  int co = solve(0, 0);
  cout << co << endl;
  print_(0, 0);
  return 0;
}
