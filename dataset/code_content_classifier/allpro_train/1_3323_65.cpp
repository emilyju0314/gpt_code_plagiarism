#include <bits/stdc++.h>
using namespace std;
int n;
int i, j;
int main() {
  cin >> n;
  auto answer = 0;
  cin >> i;
  while (--n) {
    cin >> j;
    if (j != i) {
      ++answer;
    }
    i = j;
  }
  cout << answer + 1 << endl;
}
