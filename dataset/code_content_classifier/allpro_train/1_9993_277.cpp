#include <bits/stdc++.h>
using namespace std;
bool a[10000005];
vector<int> p;
int n;
void seive() {
  long long i, j;
  p.push_back(2);
  for (i = 3; i <= 10000005; i += 2) {
    if (p.size() == n) break;
    if (a[i] == 0) {
      p.push_back(i);
      for (j = i * i; j <= 10000005; j += 2 * i) a[j] = 1;
    }
  }
}
int main() {
  cin >> n;
  int i;
  seive();
  for (i = 0; i < p.size(); i++) cout << p[i] << ' ';
  return 0;
}
