#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ara1[100000], ara2[100000], unlocked = 0;
  int numOfEvenchest = 0, numOfOddchest = 0, numOfEvenkey = 0, numOfOddkey = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> ara1[i];
    if (ara1[i] % 2 == 1) numOfOddchest++;
  }
  numOfEvenchest = n - numOfOddchest;
  for (int i = 0; i < m; i++) {
    cin >> ara2[i];
    if (ara2[i] % 2 == 1) numOfOddkey++;
  }
  numOfEvenkey = m - numOfOddkey;
  if (numOfEvenchest >= numOfOddkey) {
    unlocked += numOfOddkey;
  } else {
    unlocked += numOfEvenchest;
  }
  if (numOfOddchest >= numOfEvenkey) {
    unlocked += numOfEvenkey;
  } else {
    unlocked += numOfOddchest;
  }
  cout << unlocked;
  return 0;
}
