#include <bits/stdc++.h>
using namespace std;
struct CarInfo {
  int num, state;
};
int main() {
  int Nmax = 100;
  int n;
  int a[Nmax][Nmax];
  cin >> n;
  vector<CarInfo> cars(n);
  for (int i = 0; i < n; i++) {
    cars[i].state = 1;
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) cars[i].state = 0;
      if (a[i][j] == 3) cars[i].state = cars[j].state = 0;
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++)
    if (cars[i].state) count++;
  cout << count << endl;
  for (int i = 0; i < n; i++)
    if (cars[i].state) cout << i + 1 << " ";
  cars.clear();
  return 0;
}
