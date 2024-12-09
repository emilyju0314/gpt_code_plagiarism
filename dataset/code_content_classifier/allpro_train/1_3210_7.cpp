#include <bits/stdc++.h>
using namespace std;
long long int product(long long int x) {
  long long int prod = 1;
  while (x) {
    prod *= (x % 10);
    x /= 10;
  }
  return prod;
}
long long int findNumber(long long int l, long long int r) {
  string a = to_string(l);
  string b = to_string(r);
  long long int ans = r;
  for (long long int i = 0; i < b.size(); i++) {
    if (b[i] == '0') continue;
    string curr = b;
    curr[i] = ((curr[i] - '0') - 1) + '0';
    for (long long int j = i + 1; j < curr.size(); j++) curr[j] = '9';
    long long int num = 0;
    for (auto c : curr) num = num * 10 + (c - '0');
    if (num >= l && product(ans) < product(num)) ans = num;
  }
  return ans;
}
int main() {
  long long int n, sum = 1, res, numbers;
  cin >> n;
  numbers = findNumber(1, n);
  while (numbers != 0) {
    res = numbers % 10;
    numbers /= 10;
    sum *= res;
  }
  cout << sum;
  return 0;
}
