#include<bits/stdc++.h>
using namespace std;
int main()
{
  int tt;
  cin>>tt;
  while(tt--){
    string s;
    cin>>s;
    char a,b,c,d;
    int n=s.size();
    bool flag=true;
    int cnt1=0,cnt2=0,cnt3=0,cnt=0;
    if(s[0]==s[n-1]){flag=false;}
    else{
      c=s[0];
      d=s[n-1];
    }
    for(int i=0;i<n;i++){
      if(s[i]==c){
        s[i]='(';cnt1++;
      }
      else if(s[i]==d){
        s[i]=')';cnt2++;
      }
      else if(s[i]!=c&&s[i]!=d){
        a=s[i];
        cnt3++;
      }
    }
//  cout<<a<<endl;
//  cout<<cnt1<<" "<<cnt2<<endl;
    if(abs(cnt1-cnt2)!=cnt3){flag=false;}
    if(cnt1>cnt2){b=')';}
    else{b='(';}
    if(flag){for(int i=0;i<n;i++){
      if(s[i]==a){s[i]=b;}
    }}
    for(int i=0;i<n;i++){
      if(s[i]=='('){cnt++;}
      else if(s[i]==')'){cnt--;}
      if(cnt<0){flag=false;break;}
    }
    cout<<((flag)?"YES":"NO")<<endl;
  }
  return 0;
}