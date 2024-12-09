#include <bits/stdc++.h>
using namespace std;
int n, v1, v2, t1, t2, ans1, ans2;
int main() {
  cin >> n >> v1 >> v2 >> t1 >> t2;
  ans1 = 2 * t1 + n * v1;
  ans2 = 2 * t2 + n * v2;
  if (ans1 > ans2) {
    cout << "Second" << endl;
  } else if (ans2 > ans1) {
    cout << "First" << endl;
  } else {
    cout << "Friendship" << endl;
  }
}
