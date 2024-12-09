#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a;
  while (cin >> a) {
    list<int> v;
    int sereja = 0, dima = 0;
    for (int i = 0; i < a; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    while (!v.empty()) {
      if (v.front() > v.back()) {
        sereja += v.front();
        v.pop_front();
      } else {
        sereja += v.back();
        v.pop_back();
      }
      if (v.front() > v.back()) {
        dima += v.front();
        v.pop_front();
      } else {
        dima += v.back();
        v.pop_back();
      }
    }
    cout << sereja << " " << dima << endl;
  }
  return 0;
}
