#include <bits/stdc++.h>
using namespace std;
vector<int> line;
int main() {
  int n, k, a, b, c, d;
  cin >> n >> k >> a >> b >> c >> d;
  if (k < n + 1 || n == 4) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (i != a && i != b && i != c && i != d) line.push_back(i);
  cout << a << " " << c << " ";
  for (int i = 0; i < line.size(); i++) cout << line[i] << " ";
  cout << d << " " << b << endl;
  cout << c << " " << a << " ";
  for (int i = 0; i < line.size(); i++) cout << line[i] << " ";
  cout << b << " " << d << endl;
}
