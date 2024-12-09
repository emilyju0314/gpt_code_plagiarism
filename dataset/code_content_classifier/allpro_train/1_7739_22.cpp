#include <bits/stdc++.h>
using namespace std;
long double sqr(long double first) { return first * first; }
const double PI = acos(-1);
const int INF = 1e9;
const int MAXN = 200000;
int n, d;
pair<int, int> p[MAXN];
int a[MAXN];
int u[MAXN], v[MAXN], cost[MAXN];
int sz;
int dist[MAXN];
int main() {
  ios::sync_with_stdio(0);
  for (int i = 0; i < 9; i++)
    cout << i << "??"
         << "<>" << i + 1 << "\n";
  cout << "9??"
       << ">>"
       << "??0\n??"
       << "<>1\n";
  for (int i = 0; i <= 9; i++) cout << "?" << i << ">>" << i << "?\n";
  cout << "?"
       << ">>"
       << "??\n>>"
       << "?";
  return 0;
}
