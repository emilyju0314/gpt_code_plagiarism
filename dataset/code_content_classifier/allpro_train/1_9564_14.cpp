#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
int n;
vector<int> vec;
void no() {
  cout << "NO" << endl;
  exit(0);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vec.push_back(a);
  }
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < int(vec.size()); i++) {
    if (vec[i] == 25)
      a++;
    else if (vec[i] == 50) {
      if (a >= 1)
        a--, b++;
      else
        no();
    } else if (vec[i] == 100) {
      if (b >= 1 and a >= 1)
        a--, b--;
      else if (a >= 3)
        a -= 3;
      else
        no();
    }
  }
  cout << "YES" << endl;
  return 0;
}
