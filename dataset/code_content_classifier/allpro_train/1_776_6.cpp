#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
#define int long long
typedef pair<int,int>P;

signed main(){
  int n;
  string s;
  cin>>n>>s;
  int A=0,B=0;
  r(i,n){
    if('A'<=s[i]&&s[i]<='M')A++;
    if('N'<=s[i]&&s[i]<='Z')A--;
    if('a'<=s[i]&&s[i]<='m')B++;
    if('n'<=s[i]&&s[i]<='z')B--;
  }
  cout<<abs(A)+abs(B)<<endl;
  if(A>0){
    r(i,abs(A))cout<<'A';
  }
  if(A<0){
    r(i,abs(A))cout<<'Z';
  }
  if(B>0){
    r(i,abs(B))cout<<'a';
  }
  if(B<0){
    r(i,abs(B))cout<<'z';
  }
  cout<<endl;
}

