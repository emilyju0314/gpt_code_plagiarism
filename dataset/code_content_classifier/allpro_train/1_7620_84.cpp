#include<iostream>
#include<string>
using namespace std;

int main(){
  string str1, str2;
  int n,t=0,h=0;
  cin>>n;
  
  for(int i=0;i<n;i++){
  cin>>str1>>str2;
  if ( str1>str2) t+=3;
  else if ( str1 < str2 ) h+=3;
  else {t+=1;h+=1;};
  }
  cout << t << " "<<h<<endl;
  return 0;
}
