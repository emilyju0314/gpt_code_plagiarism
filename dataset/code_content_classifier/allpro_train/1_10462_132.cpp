#include <iostream>
#include <string>
int main(){
  std::string s;int i,a=-1,z;
  for(std::cin>>s,i=0;i<s.size();++i){
    if(s[i]=='A'&&a<0)a=i;
    if(s[i]=='Z')z=i;
  }
  std::cout<<z-a+1<<"\n";
}