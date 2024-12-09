#include <iostream>
using namespace std;

bool so[10001];

int main (){
  so[0]=1;
  so[1]=1;
  for(int i=2;i*i<10001;i++){
    if(so[i]==0){
      for(int j=2;i*j<=10001;j++)
	so[i*j]=1;
    }
  }
  int n;
  while(cin>>n){
    int co=0;
    for(int i=1;i<=n;i++)
      if(so[i]==0 && so[n-i+1]==0) co++;
    cout<<co<<endl;
  }
  return 0;
}