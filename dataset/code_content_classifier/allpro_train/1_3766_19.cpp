#include <bits/stdc++.h>
using namespace std;
int num(int x) {
  int mn = 10000;
  for (register int i = (0); i < (int)4; ++i) {
    if (x < mn) mn = x;
    x = (x / 10) + (x % 10) * 1000;
  }
  return mn;
}
int main(void) {
  set<int> st;
  int n;
  cin >> n;
  for (register int i = (0); i < (int)n; ++i) {
    string tmp;
    if (i) cin >> tmp;
    int a, b;
    cin >> a >> b;
    int x = a * 100 + (b % 10) * 10 + b / 10;
    st.insert(num(x));
  }
  cout << ((int)(st).size()) << endl;
  return 0;
}
