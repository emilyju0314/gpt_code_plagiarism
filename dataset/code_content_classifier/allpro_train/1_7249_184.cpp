#include <iostream>
#include <string>
using namespace std;

string d[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main(){
  string s;
  cin>>s;
  for(int i=0;i<7;++i){
    if(d[6-i]==s){
      cout<<i+1;
      break;
    }
  }
  return 0;
}