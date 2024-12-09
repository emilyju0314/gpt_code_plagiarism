#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const double pi = acos(-1.0);
long long int x, k, ctr = 0;
int flag = 0;
vector<long long int> divisors;
void getdivisors() {
  for (long long int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      divisors.push_back(i);
      if (x / i != i) {
        divisors.push_back(x / i);
      }
    }
  }
}
void DFS(long long int val, int depth) {
  if (depth == k || val == 1) {
    cout << val << " ";
    ctr++;
    if (ctr == 100000) {
      flag = 1;
      return;
    }
    return;
  }
  for (int i = 0; i < (int)divisors.size() && divisors[i] <= val && !flag;
       i++) {
    if (val % divisors[i] == 0) DFS(divisors[i], depth + 1);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  while (cin >> x >> k) {
    divisors.clear();
    getdivisors();
    sort(divisors.begin(), divisors.end());
    DFS(x, 0);
    cout << endl;
  }
  return 0;
}
