#include <bits/stdc++.h>
using namespace std;

int main() {
  long ans;
  string s;
  cin >> s;
  ans=s.size()*(s.size()+1)/2+1;
  vector<long> c(26);
  for(long i=0;i<s.size();i++) c[s[i]-'a']++;
  for(long i=0;i<26;i++) ans-=c[i]*(c[i]+1)/2;
  cout << ans << endl;
}