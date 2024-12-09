#include<iostream>
#include<string>
using namespace std;
int main(){
  int a,c;
  string b;
  cin>>a>>b>>c;
  for(int i=0;i<a;i++){
    if(b.at(i)!=b.at(c-1))
      b.at(i)='*';
  }
  cout<<b<<endl;
}
