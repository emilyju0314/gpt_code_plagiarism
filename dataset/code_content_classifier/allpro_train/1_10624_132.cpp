#include <bits/stdc++.h>
using namespace std;
int n;
long long px[300007], py[300007];
int used[300007];
int a, b, c, d;
long long area(int a, int b, int c) {
  return (px[b] - px[a]) * (py[c] - py[b]) - (py[b] - py[a]) * (px[c] - px[b]);
}
vector<int> ost(0);
int tryp() {
  for (int i = 0; i < n; i++) {
    if (area(a, b, i) == 0)
      used[i] = 1;
    else
      used[i] = 0;
  }
  ost.clear();
  for (int i = 0; i < n; i++)
    if (!used[i]) ost.push_back(i);
  for (int i = 0; i < (int)ost.size() - 2; i++) {
    if (area(ost[i], ost[i + 1], ost[i + 2]) != 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  if (n <= 2) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> px[i] >> py[i];
  }
  d = 0;
  int start = clock();
  while (clock() - start < 500) {
    a = rand() % n;
    b = rand() % n;
    if (a != b && tryp()) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
