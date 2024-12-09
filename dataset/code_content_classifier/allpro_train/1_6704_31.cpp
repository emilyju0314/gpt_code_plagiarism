#include <bits/stdc++.h>
bool wayToSort(long long i, long long j) { return i > j; }
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long a[100001], b[100001];
  int index;
  int alimit, blimit;
  cin >> alimit >> blimit;
  for (index = 0; index < alimit; ++index) cin >> a[index];
  for (index = 0; index < blimit; ++index) cin >> b[index];
  sort(a, a + alimit);
  sort(b, b + blimit, wayToSort);
  long long moves = 0;
  for (int i = 0; i < min(blimit, alimit) && a[i] < b[i]; ++i) {
    moves += (b[i] - a[i]);
  }
  cout << moves;
}
