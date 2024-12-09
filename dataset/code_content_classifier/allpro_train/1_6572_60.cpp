#include<iostream>
#include<cmath>
using namespace std;

int main(void){
  string s;
  int n=1000;
  while(n--){
    cin>>s;
    bool ans = true;
    for(int i=0;i<s.size()-1;i++){
      if((s[i]-'A')/3 == (s[i+1]-'A')/3 && abs(s[i]-s[i+1])==1){
	continue;
      }
      if(abs(s[i]-s[i+1])==3)continue;
      ans=false;
      break;
    }
    if(ans)cout<<s<<endl;
  }
}