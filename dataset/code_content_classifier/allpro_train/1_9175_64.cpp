#include<bits/stdc++.h>
using namespace std;
string s;

bool check(){
  int cal=0;
  for(int i=1;i<s.size();i++){
    int x;
    if(1<=i&&i<=6)x=i+1;
    else x=i-5;
    cal+=(s[i]-'0')*x;
  }
  

  cal%=11;
  
  int checkd;
  if(cal<=1)checkd=0;
  else{  
    checkd=11-cal;
  }
  
  
  
  
  return checkd==(int)(s[0]-'0');
}

int main(){
  cin>>s;
  reverse(s.begin(),s.end());
  int cnt=0,ans;
  for(int i=0;i<s.size();i++){
    if(s[i]=='?'){
      for(int j=0;j<10;j++){
	s[i]=j+'0';
	if(check())cnt++,ans=j;
      }
    }
  }
  if(cnt>1)cout<<"MULTIPLE"<<endl;
  else cout<<ans<<endl;
  return 0;
}