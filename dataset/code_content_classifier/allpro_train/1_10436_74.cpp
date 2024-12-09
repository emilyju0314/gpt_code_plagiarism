#include <bits/stdc++.h>
using namespace std;
const long long maxN = 1e6 + 7, MOD = 81409, inf = 1e9, N = 1e4 + 7;
long long k, n, answer, cnt, help, c[30], now, op, num, pointer, mid;
string d;
vector<char> p;
int main() {
  cin >> k >> d;
  if ((k * 2) - 1 > d.size()) return cout << "IMPOSSIBLE\n", 0;
  for (long long i = 0; i < d.size(); i++)
    if (d[i] != '?') c[d[i] - 'a' + 1]++;
  for (long long i = k + 1; i <= 26; i++)
    if (c[i]) return cout << "IMPOSSIBLE\n", 0;
  for (long long i = 0; i < d.size(); i++) {
    if (d[i] != '?' && d[d.size() - i - 1] == '?')
      d[d.size() - 1 - i] = d[i];
    else if (d[i] == '?' && d[d.size() - 1 - i] != '?')
      d[i] = d[d.size() - i - 1];
    else if (d[i] != '?' && d[d.size() - 1 - i] != '?' &&
             d[i] != d[d.size() - 1 - i])
      return cout << "IMPOSSIBLE\n", 0;
  }
  mid = d.size() / 2;
  if (!(d.size() % 2)) mid--;
  for (long long i = 0; i <= mid; i++)
    if (d[i] == '?') cnt++;
  for (long long i = 1; i <= k; i++)
    if (!c[i]) help++, p.push_back('a' + i - 1);
  if (help > cnt) return cout << "IMPOSSIBLE\n", 0;
  num = cnt - help;
  if (p.size() || num) {
    for (long long i = 0; i <= mid; i++) {
      if (d[i] == '?' && num)
        d[i] = d[d.size() - i - 1] = 'a', num--;
      else if (d[i] == '?')
        d[i] = p[pointer], d[d.size() - i - 1] = p[pointer], pointer++;
    }
  }
  return cout << d << "\n", 0;
}
