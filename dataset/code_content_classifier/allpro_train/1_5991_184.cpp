#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cin.get();
  int sum = 0;
  vector<int> pages(7);
  for (int i = 0; i < 7; i++) {
    cin >> pages[i];
    sum += pages[i];
  }
  n %= sum;
  if (n == 0) n = sum;
  int day = 0;
  while (n > 0) n -= pages[day++];
  cout << day;
  return 0;
}
