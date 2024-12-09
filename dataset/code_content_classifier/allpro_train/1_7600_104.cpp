#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,v;
  cin >> N;
  set<int> s;
  for(int i=0;i<N;i++) cin >> v, s.insert(v);
  cout << s.size() << endl;
}