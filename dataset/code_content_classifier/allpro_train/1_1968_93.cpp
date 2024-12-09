#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long a = 0;
  long long b = 0;
  long long c = 0;
  for(int i = 0;i<n;i++){
    if(s[i]=='R') a++;
    else if(s[i] =='G')b++;
    else c++;
  }
  long long sum = a*b*c;
  for(int i = 0;i<n;i++){
  for(int j = 1;i+j+j<n;j++){
  if(s[i]!=s[i+j]&&s[i+j]!=s[i+j+j]&&s[i]!=s[i+j+j]) sum --;
  }}
  cout << sum ;
  return 0;
}