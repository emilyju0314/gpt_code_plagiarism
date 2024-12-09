#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,ans;
  cin>>a>>b>>c>>d;
  ans = max(0, min(b,d)-max(a,c));
  cout<<ans;
}