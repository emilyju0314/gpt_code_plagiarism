#include <bits/stdc++.h>
using namespace std;
int main() {
  int sumep = 1, sumht = 0, n, tam;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> tam;
    sumep += i;
    sumht += tam;
  }
  cout << sumep - sumht << endl;
  return 0;
}
