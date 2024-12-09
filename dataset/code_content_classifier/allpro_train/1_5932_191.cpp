#include <bits/stdc++.h>
using namespace std;
const signed long long INF = 1000000100;
const long double EPS = 1e-9;
vector<string> S;
char buff[1000100];
void read_data() {
  int n;
  scanf("%d", &n);
  for (int(i) = (1); (i) <= (n); (i)++) {
    scanf("%s", buff);
    S.push_back(buff);
  }
  sort(S.begin(), S.end(), [](string &a, string &b) { return a + b < b + a; });
  for (string s : S) printf("%s", s.c_str());
  printf("\n");
}
void solve() {}
int main() {
  read_data();
  solve();
}
