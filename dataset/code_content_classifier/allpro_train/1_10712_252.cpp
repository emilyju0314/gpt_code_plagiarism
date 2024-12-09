#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
int main() {
  int n;
  cin >> n;
  int m;
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> m;
    if (m != 0) s.insert(m);
  }
  cout << s.size();
}
