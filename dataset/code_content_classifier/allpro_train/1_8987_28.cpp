#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n = s.length();
  for (int i=n-2; i>=0; i--) {
    if (i % 2 == 0) {
      continue;
    }
    if (s.substr(0, i/2+1) == s.substr(i/2+1, i/2+1)) {
      cout<<i+1<<endl;
      return 0;
    }
  }
}